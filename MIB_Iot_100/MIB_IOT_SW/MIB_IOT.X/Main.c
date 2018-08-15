/*
 * File:   Main.c
 * Author: Bernardo Leite
 *
 * Created on 8 de Março de 2018, 15:46
 */

#include <Config_uC.h>
#include <Configura_Pinos.h>
#include "Conversor_Escalas.h"
#include <Serial.h>
#include <Wifi.h>
#include <pic18.h>
#include <pic18f56k42.h>
#include "Configura_Memoria.h"
#include "GERREX.h"
#include <stdio.h>

unsigned char buffer_leitura_comm [tamanhoBuffer];
unsigned char buffer_leitura_USB [tamanhoBuffer];
unsigned char buffer_escrita_comm [tamanhoBuffer];
unsigned char buffer_escrita_USB [tamanhoBuffer];
int primeiro = 0;

long contaLoop = 0;
long conta = 0;
long contaLed = 0;

int Postando =0;

extern unsigned char __resetbits;
extern bit __powerdown;
extern bit __timeout;

void __interrupt(irq(U1RX), low_priority) Interrupt_USB_485(void) {
    //if (RecebendoFrames == 0) {
    //check if the interrupt is caused by RX pin
    if (U1RXIF == 1) {
        char lido = Recebe();
        Buffer_Escrita_COMM_Add_Char(lido); //Escreve para USB*** (Tratar Isso) o que receber pela USB
        Buffer_Leitura_USB_Add_Char(lido);
        U1RXIF = 0; // clear rx flag
    }
    //}
}

void __interrupt(irq(U2RX), low_priority) Interrupt_WIFI_GSM(void) {
    //if (RecebendoFrames == 0) {
    //check if the interrupt is caused by RX pin
    if (U2RXIF == 1) {
        char lido = Recebe_COMM();
        Buffer_Escrita_USB_Add_Char(lido); //Escreve para Wifi o que recebe da USB
        AguardaINT(lido);
        U2RXIF = 0; // clear rx flag
    }
    //}
}

void main(void) {
    Postando =1;
    WDTCON0bits.WDTPS = 0b01101;
    unsigned long i2 = 0;
    INTCON0bits.GIE = 1;
    INTCON0bits.IPEN = 1;


    Abre_Porta_1(USB, 115200);
    Abre_Porta_COMM(115200);

    tledStatus = 0;
    tledRX = 0;
    tledTX = 0;

    //tRTSWifi = 1;
    //tCTSwifi = 0;  //RTS do PIC e o CTS do Wifi

    ledStatus = 0; //^= 1;
    ledRX = 0; //Running;
    ledTX = 0; //LinkUp;
    //CLRWDT();
    __delay_ms(1000);

    

    FVRCONbits.ADFVR = 0b10;
    FVRCONbits.CDAFVR = 0b10;
    FVRCONbits.EN = 1;

    ADCAP = 0b11111;
    ADPREH = 0b11111;
    ADPREL = 0b11111111;

    ADACQL = 0b11111111;
    ADACQH = 0b11111;

    ADCLKbits.CS = 0b000011;

    ADCON0bits.CS = 0;
    ADCON0bits.FM = 1;
    ADREFbits.NREF = 1;
    ADREFbits.PREF = 0b10; //Testar 0b11 com ref int 2048 //0b10 Vref ext
    ADPCH = 0b011111;


    tANALOG_IN = 1;
    ANSELDbits.ANSELD7 = 1;
    ADCON0bits.ON = 1;

    tANALOG_CMD = 0; //TRISDbits.TRISD3 = 0;
    tRELE = 0; //TRISDbits.TRISD4 = 0;

    //ANALOG_CMD = 1;//LATDbits.LATD3 = 1;
    RELE = 1; //LATDbits.LATD4 = 1;

    Calcula_Fator_m();


    char motivo [20];

    sprintf(motivo, "\r\n\r\n\r\nPCON0 >%i\r\n", PCON0);
    Buffer_Escrita_USB_Add_String(motivo, 1);
    sprintf(motivo, "PCON01 >%i\r\n", PCON1);
    Buffer_Escrita_USB_Add_String(motivo, 1);

    BORCONbits.SBOREN = 0;
    BORCONbits.BORRDY = 0;

    MEMORIA[0] = 0;
    MEMORIA[1] = 0;
    MEMORIA[2] = 0;
    MEMORIA[3] = 0;
    MEMORIA[4] = 0;
    MEMORIA[5] = 0;
    MEMORIA[6] = 0;
    MEMORIA[7] = 0;
    MEMORIA[8] = 0;
    MEMORIA[9] = 0;
    
    InicializaWifi();
    

    //SWDTEN = 1;

    do {
        CTSwifi = 0;
        CLRWDT();
        if (WakeUp_Wifi == 1) {
            ledStatus ^= 1;
            ledRX = Running;
            ledTX = LinkUp;
        }


        if (Running && primeiro == 0) primeiro = 1;
        if (primeiro == 1 && Running == 0) primeiro = 2;
        if (primeiro == 2 && LinkUp == 0 && Running == 0)primeiro = 3;

        if (primeiro == 3 && LinkUp == 0) {
            primeiro = 5;
            Aguarda_dado("WiFi Up:0", "\r", "", GETMACAddr);
        }
        TransmiteBuffer_COMM();
        TransmiteBuffer_USB();

        Verifica_Analogica();

        //TESTAR CONDIÇÃO DE POST ANTES DE POSTAR
        //
        //IMPLEMENTAR TIMEOUT DAS OPERAÇÕES
        //

        if (contaLoop > 100000) {
            //RESET();
            inicia_Post();
            contaLoop = 0;
        } else {
            if (Postando == 0) contaLoop++;
        }
        
        if (conta > 0x2fffff) {
            RESET();
            conta = 0;
        } else {
            conta++;
        }

        //TESTAR ACIONAMENTO O WDT

        if (WakeUp_Wifi == 0) {

            ledStatus = 0;
            ledRX = 0;
            ledTX = 0;

            conta = 0;

            if (contaLed > 0x33333) {
                ledStatus = 1;
                __delay_ms(200);
                ledStatus = 0;
                contaLed = 0;
            } else {
                contaLed++;
            }
        }

    } while (1);
}

