/*
 * File:   Wifi.c
 * Author: Bernardo Leite
 *
 * Created on 22 de Março de 2018, 17:12
 */
#include "Configura_Memoria.h"
#include <Config_uC.h>
#include <Configura_Pinos.h>
#include <Serial.h>
#include <Wifi.h>
#include <GERREX.h>
#include <stdio.h>
#include <pic18.h>

unsigned char text [10];

void InicializaWifi(void) {
    tLinkUp = 1;
    tMiniAP = 0;
    tRunning = 1;
    tWakeUp = 0;

    ANSELEbits.ANSELE1 = 0;
    ANSELAbits.ANSELA4 = 0;

    WakeUp_Wifi = 1;
    MiniAP = 1;

    tWifiReset = 0;
    WifiReset = 0;
    __delay_ms(10);
    WifiReset = 1;
}

void cria_Arquivo(char* nome, char* dado) {
    unsigned char tamanho [15];
    int tam = 0;
    __delay_ms(10);
    Buffer_Escrita_COMM_Add_String("AT+S.FSC=", 1);
    Buffer_Escrita_COMM_Add_String(nome, 1);
    tam = length(dado);
    sprintf(tamanho, ",%i\r", tam);
    Buffer_Escrita_COMM_Add_String(tamanho, 1);
    Buffer_Escrita_COMM_Add_String(dado, 1);
    
}

void append_Arquivo_Json(void) {
    int i = 0;
    int primeiro = 0;
    char virgula[2];
    char linhaArquivo [120];
    
    cria_Arquivo("gerrex.json", "{\"code\":\"00:80:E1:BF:E3:C8\",\"taskResponseFrames\":[");
    
    //MEMORIA[0] = 100;
    //MEMORIA[1] = 101;
    MEMORIA[2] = 0;
    MEMORIA[3] = 0;
    MEMORIA[4] = 0;
    MEMORIA[5] = 0;
    MEMORIA[6] = 0;
    
    
    
    for (i = 0; i < tamFrames; i++) {
        char resultado [6];
        
        long valorMem = MEMORIA[address[i] - 0x30];
        char valorMem_Char[10];
        
        sprintf(valorMem_Char,"%08lx",valorMem);
        result[i] = 1;

        if (primeiro == 0) {
            virgula[0] = 0x00;
            primeiro = 1;
        }
        else {
            virgula[0] = ',';
            virgula[1] = 0x00;
        }
        if (result[i] == 1) sprintf(resultado, "true");
        else sprintf(resultado, "false");
        sprintf(linhaArquivo, "%s{\"frameId\":\"%s\",\"value\":\"%c%c,%c%c,%c%c,%c%c\",\"result\":%s}", virgula, frameId[i], valorMem_Char[0], valorMem_Char[1], valorMem_Char[2],valorMem_Char[3], valorMem_Char[4],valorMem_Char[5],valorMem_Char[6],valorMem_Char[7], resultado);
        //Buffer_Escrita_USB_Add_String(linhaArquivo, 1);
        
        cria_Arquivo("gerrex.json", linhaArquivo);
        ///cria_Arquivo("gerrex.json", frameId[i]);
        //cria_Arquivo("gerrex.json", "\",\"value\":\"");

        //cria_Arquivo("gerrex.json", "\",\"value\":\"%i\",\"result\":");
        //cria_Arquivo("gerrex.json", "true}\r\n");
        

    }
    cria_Arquivo("gerrex.json", "]}\r");

}

void inicia_Post(void) {
    Postando = 1;
    WakeUp_Wifi = 1;
    Buffer_Escrita_COMM_Add_String("AT+S.FSD=gerrex.json\r", 1);
    __delay_ms(500);
    Buffer_Escrita_USB_Add_String("Inicia_Arquivo_Gerrex\r\n", 1);
    append_Arquivo_Json();
    Aguarda_dado("-S", "\r", "", Post);
}

void Post(void) {
    Aguarda_dado("*", "*", "", nada);
    
    Buffer_Escrita_USB_Add_String("Post...\r\n", 1);
    //Buffer_Escrita_USB_Add_String("AT+S.FSP=gerrex.json,0,100000\r", 1);
    Buffer_Escrita_COMM_Add_String("AT+S.FSP=gerrex.json,0,100000\r", 1);
    //__delay_ms(1000);
    //Buffer_Escrita_COMM_Add_String("AT+S.HTTPPOST=services.gerrex.com.br,/service/task,80,,,,retorno.json,gerrex.json\r\n", 1);
    Aguarda_dado("AT", "OK", "", Post2); //Aguarda_dado("AT", "OK", "", verifica_tamanho_arquivo);
}

void Post2(void){
    Buffer_Escrita_COMM_Add_String("AT+S.HTTPPOST=services.gerrex.com.br,/service/task,80,,,,retorno.json,gerrex.json\r\n", 1);
    Aguarda_dado("AT", "OK", "", recebe); //Aguarda_dado("AT", "OK", "", verifica_tamanho_arquivo);
}

//void verifica_tamanho_arquivo(void){
//Buffer_Escrita_COMM_Add_String("AT+S.FSL\r",1);
//    Aguarda_dado("AT-S.File:D	", "	retorno.json", "", buffer_tamanho_arquivo);
//}
//void buffer_tamanho_arquivo(void){
//    sprintf(text, Aguarda_Resposta);
//    Aguarda_dado("AT", "OK\r", "", recebe);
//}

void recebe(void) {
    Buffer_Escrita_COMM_Add_String("AT+S.FSP=retorno.json,0,", 1);
    Buffer_Escrita_COMM_Add_String("100000\r", 1);
    Aguarda_dado("Read Cap:", "\r", "", recebeFRAMES);
}

int length(char* dado) {
    int i = 0;
    while (dado[i] != 0x00)i++;
    return i;
}