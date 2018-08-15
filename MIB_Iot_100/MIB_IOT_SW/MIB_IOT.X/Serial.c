/*
 * File:   Serial.c
 * Author: Bernardo Leite
 *
 * Created on 9 de Março de 2018, 10:40
 */
#include <xc.h>
#include <Serial.h>
#include <Configura_Pinos.h>
//#include <pic18f56k42.h>
//#include <pic18f56k42.h>
#include "Configura_Memoria.h"
#include "PPS.h"
#include <stdio.h>

//char Aguarda_buffer [100];
unsigned char Aguarda_str [20];
unsigned char Aguarda_end [10];
unsigned char Aguarda_error [10];
unsigned char Aguarda_end_frame [10];
unsigned char Aguarda_Resposta [100];

unsigned int AguardaFrames = 0;

unsigned int Aguarda_Ponteiro = 0;
unsigned int Aguarda_End_Ponteiro = 0;

unsigned int Aguarda_str_OK = 0;
void (*Aguarda_Funcao)(void);

unsigned int ponteiro_escrita_COMM = 0;
unsigned int ponteiro_escrita_USB = 0;
unsigned int ponteiro_COMM = 0;
unsigned int ponteiro_USB = 0;

unsigned int Ponteiro_ERRO = 0;
unsigned int Ponteiro_FIM = 0;

unsigned int recebeu_r_n = 0;
int tempo = 0;
int breakpoint_sw = 0;

void Abre_Porta_1(int PORTA, long BaudRate) {
    long baud = Calcula_BaudRate(BaudRate);

    U1CON0bits.TXEN = 1;
    U1CON0bits.RXEN = 1;
    U1CON0bits.BRGS = 1;
    PIE3bits.U1IE = 1;
    PIE3bits.U1RXIE = 1;
    //U1CON0bits.U1MODE = 0b0011;
    U1CON0bits.U1MODE = 0;

    U1BRGH = (unsigned char) ((baud & 0xFF00) / 0x100);
    U1BRGL = (unsigned char) (baud & 0x00FF);



    if (PORTA == USB) {
        unLock_PPS();
        RC0PPS = 0b010011; //TX USB
        //RC1PPS = 0b01111; //RX USB 010001
        U1RXPPS = 0b010001;
        lock_PPS();
        ANSELCbits.ANSELC1 = 0;
        TRISCbits.TRISC0 = 0;
        TRISCbits.TRISC1 = 1;

    }
    if (PORTA == RS485) {
        unLock_PPS();
        RC5PPS = 0b010011;
        ; //TX 485
        U1RXPPS = 0b010111; //RX 485
        ANSELCbits.ANSELC5 = 0;
        TRISCbits.TRISC5 = 0;
        TRISCbits.TRISC7 = 1;
        lock_PPS();
    }

    U1CON1bits.ON = 1;
}

void Abre_Porta_COMM(long BaudRate) {
    long baud = Calcula_BaudRate(BaudRate);
    
    tCTSwifi = 0;
    tRTSWifi = 1;

    U2BRGH = (unsigned char) ((baud & 0xFF00) / 0x100);
    U2BRGL = (unsigned char) (baud & 0x00FF);
    U2CON0bits.TXEN = 1;
    U2CON0bits.BRGS = 1;

    U2CON0bits.RXEN = 1;
    U2CON0bits.BRGS = 1;
    PIE6bits.U2IE = 1;
    PIE6bits.U2RXIE = 1;
    //U2CON0bits.U2MODE = 0b0011;
    U2CON0bits.U2MODE = 0;

    unLock_PPS();
    RB1PPS = 0b010110;
    U2RXPPS = 0b001000;

    ANSELBbits.ANSELB0 = 0;

    TRISBbits.TRISB0 = 1;
    TRISBbits.TRISB1 = 0;

    lock_PPS();

    U2CON1bits.ON = 1;
}

long Calcula_BaudRate(long BaudRate) {
    long baud;

    baud = Clock / BaudRate;
    baud = baud / (long) 4;
    baud--;

    return baud;
}

/*short int Paridade(unsigned char Byte) {
    unsigned int resto;
    Byte ^= (Byte >> 4);
    Byte ^= (Byte >> 2);
    Byte ^= (Byte >> 1);
    Byte ^= (Byte & 0x01);
    resto = Byte % 2;
    return (resto > 0);
}*/

char Recebe(void) {
    return U1RXB;
}

char Recebe_COMM(void) {
    return U2RXB;
}

/*short int Transmite(char* dado, int PORTA) {
    int posicao = 0;
    while (dado[posicao] > 0x00) {
        while (U1ERRIRbits.TXMTIF == 0);
        U1TXB = dado[posicao];
        posicao++;
    }
    return dado;
}*/

int TransmiteBuffer_USB(void) {
    if (TXIF_USB == 0) return 0;
    if (ponteiro_escrita_USB < ponteiro_USB) {
        TX_USB = buffer_escrita_USB[ponteiro_escrita_USB];
        ponteiro_escrita_USB++;
        return 0;
    } else {
        ponteiro_USB = 0;
        ponteiro_escrita_USB = 0;
        return 1;
    }
}

int TransmiteBuffer_COMM(void) {
    if (TXIF_COMM == 0) return 0;
    if (ponteiro_escrita_COMM < ponteiro_COMM) {
        TX_COMM = buffer_escrita_comm[ponteiro_escrita_COMM];
        ponteiro_escrita_COMM++;
        return 0;
    } else {
        ponteiro_COMM = 0;
        ponteiro_escrita_COMM = 0;
        return 1;
    }
}

void Buffer_Leitura_USB_Add_Char(char dado) {

}

short int Buffer_Escrita_USB_Add_String(char *dado, short int aguarda) {
    int i = 0;
    ponteiro_USB = 0;
    ponteiro_escrita_USB = 0;
    buffer_escrita_USB[0] = 0x00;

    while (dado[i] != 0x00) {
        if (i >= tamanhoBuffer) return;
        Buffer_Escrita_USB_Add_Char(dado[i]);
        i++;
    }
    if (aguarda){
        while (TransmiteBuffer_USB() == 0);
    }
}

short int Buffer_Escrita_USB_Add_Char(char dado) {
    buffer_escrita_USB[ponteiro_USB] = dado;

    //if (buffer_escrita_USB[ponteiro_USB - 1] == 0x0D && buffer_escrita_USB[ponteiro_USB] == 0x0A) {
    //    recebeu_r_n = 1;
    //}

    if (ponteiro_USB >= tamanhoBuffer) ponteiro_USB = 0;
    else ponteiro_USB++;
}

short int Buffer_Escrita_COMM_Add_Char(char dado) {
    buffer_escrita_comm[ponteiro_COMM] = dado;
    if (ponteiro_COMM >= tamanhoBuffer) ponteiro_COMM = 0;
    else ponteiro_COMM++;
}

short int Buffer_Escrita_COMM_Add_String(char *dado, short int aguarda) {
    int i = 0;

    ponteiro_COMM = 0;
    ponteiro_escrita_COMM = 0;
    buffer_escrita_comm[0] = 0x00;

    while (dado[i] != 0x00) {
        if (i >= tamanhoBuffer) return;
        Buffer_Escrita_COMM_Add_Char(dado[i]);
        i++;
    }
    if (aguarda){
        while (TransmiteBuffer_COMM() == 0);
    }
}

/*short int Transmite_COMM(char* dado) {
    int posicao = 0;
    while (dado[posicao] > 0x00) {
        while (U2ERRIRbits.TXMTIF == 0);
        U2TXB = dado[posicao];
        posicao++;
    }
    return dado;
}*/

void AguardaINT(char dado) {
    verificaERRO(dado);
    if (Aguarda_str_OK == 0) {
        if (dado == Aguarda_str[Aguarda_Ponteiro]) {
            Aguarda_Ponteiro++;
            if (Aguarda_str[Aguarda_Ponteiro] == 0x00) {
                Aguarda_str_OK = 1;
                Aguarda_Ponteiro = 0;
            }
        } else {
            Aguarda_Ponteiro = 0;
        }
    } else {
        Aguarda_Resposta[Aguarda_Ponteiro] = dado;
        Aguarda_Ponteiro++;
        if (breakpoint_sw == 1) {
            breakpoint_sw = 1;
        }
        if (dado == Aguarda_end[Aguarda_End_Ponteiro]) {
            Aguarda_End_Ponteiro++;
            if (Aguarda_end[Aguarda_End_Ponteiro] == 0x00) {
                Aguarda_Resposta[Aguarda_Ponteiro - Aguarda_End_Ponteiro] = 0x00;
                Aguarda_End_Ponteiro = 0;
                Aguarda_str_OK = 0;

                Aguarda_Funcao();
            }
        }
    }
}

int Aguarda(char dado) {
    if (U2RXIF == 1) {
        dado = U2RXB;
        U2RXIF = 0;
    } else {
        return 0;
    }
    
    CTSwifi = 1;

    verificaERRO(dado);
    verificaFimFrame(dado);

    if (Aguarda_str_OK == 0) {
        if (dado == Aguarda_str[Aguarda_Ponteiro]) {
            Aguarda_Ponteiro++;
            if (Aguarda_str[Aguarda_Ponteiro] == 0x00) {
                Aguarda_str_OK = 1;
                Aguarda_Ponteiro = 0;
            }
        } else {
            Aguarda_Ponteiro = 0;
        }
    } else {
        Aguarda_Resposta[Aguarda_Ponteiro] = dado;
        Aguarda_Ponteiro++;

        if (dado == Aguarda_end[Aguarda_End_Ponteiro]) {
            Aguarda_End_Ponteiro++;
            if (Aguarda_end[Aguarda_End_Ponteiro] == 0x00) {
                Aguarda_Resposta[Aguarda_Ponteiro - Aguarda_End_Ponteiro] = 0x00;
                Aguarda_End_Ponteiro = 0;
                Aguarda_Ponteiro = 0;
                Aguarda_str_OK = 0;
                
                CTSwifi = 0;
                return 1;
            }
        }
    }
    CTSwifi = 0;
    return 0;
}

int verificaFimFrame(char dado) {
    char FIM [] = "}]";
    if (dado == FIM[Ponteiro_FIM]) {
        Ponteiro_FIM++;
        if (Ponteiro_FIM >= 0x02) {
            AguardaFrames = 1;
        }
    } else {
        Ponteiro_FIM = 0;
    }
}

void verificaERRO(char dado) {
    char ERRO [] = "ERRO:";
    if (dado == ERRO[Ponteiro_ERRO]) {
        Ponteiro_ERRO++;
        if (ERRO[Ponteiro_ERRO] == 0x00) {
            RESET(); //Reinicia hardwar
        }
    } else {
        Ponteiro_ERRO = 0;
    }
}


void limpa_Buffer_Leitura_COMM(void);
void limpa_Buffer_Leitura_USB(void);

void limpa_Buffer_Escrita_USB(void) {
    int i = 0;
    ponteiro_USB = 0;
    ponteiro_escrita_USB = 0;
    while (i < tamanhoBuffer) {
        buffer_escrita_USB[i] = 0x00;
        i++;
    }
};

void limpa_Buffer_Escrita_COMM(void) {
    int i = 0;
    ponteiro_COMM = 0;
    ponteiro_escrita_COMM = 0;
    while (i < tamanhoBuffer) {
        buffer_escrita_comm[i] = 0x00;
        i++;
    }
};


/*int StrLen(char * dado) {
    int tam = 0;
    while (dado[tam] != 0) tam++;
    return tam;
}*/
