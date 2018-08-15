/*
 * File:   GERREX.c
 * Author: Bernardo Leite
 *
 * Created on 26 de Março de 2018, 17:07
 */

#include <xc.h>
#include <Config_uC.h>
#include <Configura_Pinos.h>
#include <Serial.h>
#include <Wifi.h>
#include "Configura_Memoria.h"
#include "GERREX.h"
#include <stdio.h>
#include <pic18.h>

long MEMORIA[10];
int iii = 0;
char MACAddress [18];
unsigned int RecebendoFrames = 0;

int tamFrames = 0;

char frameId[quantidadeFrames][37];
int networkId[quantidadeFrames];
int nodeId[quantidadeFrames];
int functionCode[quantidadeFrames];
int address[quantidadeFrames];
int size[quantidadeFrames];
long value[quantidadeFrames];
short int result[quantidadeFrames];

int ponteiroFrames = 0;

void GETTask(void) {
    char teste [100];
    //sprintf(teste,"AT+S.HTTPGET=services.gerrex.com.br,/service/task/%s\r\n", MACAddress);
    //BufferCOMM_Add_String(teste);
    
    ponteiroFrames = 0;
    Buffer_Escrita_COMM_Add_String("AT+S.HTTPGET=services.gerrex.com.br,/service/task/11:22:33:44:55:66\r\n", 1);
    recebeFRAMES();
    testaRespostaHTTP();
    while (Aguarda(0x00) == 0);
    trataRespostaHTTP(); //Se vier erro RESET();)
}

void recebeFRAMES(void) {
    Aguarda_dado("*", "*", "", nada);
    
    if (Aguarda_Resposta[0] == 0x32 && Aguarda_Resposta[1] == 0x00  ) {
        Buffer_Escrita_USB_Add_String("\r\n>>>>>> No Instructions\r\n", 1);
        goto noInstructions;
    }
    ponteiroFrames = 0;
    tamFrames=0;
    INTCON0bits.GIE = 0;
    int exit = 0;
    AguardaFrames = 0;
    while (1) {
        CTSwifi = 1;
        recebeFRAMEID();
        exit = 0;
        while (exit == 0) {
            exit = Aguarda(0x00);
            if (AguardaFrames == 1) {
                AguardaFrames = 0;
                goto fim;
            }
        };
        CTSwifi = 1;
        recebeNETWORKID();
        while (Aguarda(0x00) == 0);
        CTSwifi = 1;
        recebeNODEID();
        while (Aguarda(0x00) == 0);
        CTSwifi = 1;
        recebeFUNCTIONCODE();
        while (Aguarda(0x00) == 0);
        CTSwifi = 1;
        recebeADDRESS();
        while (Aguarda(0x00) == 0);
        CTSwifi = 1;
        recebeSIZE();
        while (Aguarda(0x00) == 0);
        tamFrames++;
    }
fim:
    INTCON0bits.GIE = 1;
    AguardaFrames = 0;
    Buffer_Escrita_USB_Add_String("\r\n--FRAMES RECEBIDOS--\r\n", 1);
    
noInstructions:
    Aguarda_dado("*", "*", "", nada);
    
    //Buffer_Escrita_COMM_Add_String("AT+S.SCFG=standby_time,60\r", 1);
    //__delay_ms(300);
    WakeUp_Wifi = 0;
    //Buffer_Escrita_COMM_Add_String("AT+S.PMS=3\r", 1);
    //Aguarda_dado("+WIND:24:WiFi Up:0", "\r", "", inicia_Post);
    Postando = 0;
}

void testaRespostaHTTP(void) {
    Aguarda_dado("HTTP/1.1 ", " ", "", 0x00);
}

int trataRespostaHTTP(void) {
    int http_i = 0;
    int icase = 0;
    char strHTTP200 [] = "200";
    char strHTTP204 [] = "204";
    char strHTTP404 [] = "404";

    while (Aguarda_Resposta[http_i] != 0x00) {
        icase = 0;
        if (strHTTP200[http_i] == Aguarda_Resposta[http_i]) icase = HTTP200;
        if (strHTTP204[http_i] == Aguarda_Resposta[http_i]) icase = HTTP204;
        if (strHTTP404[http_i] == Aguarda_Resposta[http_i]) icase = HTTP404;

        http_i++;
    }
    switch (icase) {
        case 0:
            return 0;
            break;
        case 1:
            return HTTP200;
            break;
        case 2:
            __delay_ms(3000);
            RESET();
            return HTTP204;
            break;
        case 3:
            __delay_ms(3000);
            RESET();
            return HTTP404;
            break;
    }
    return 0;
}

void recebeFRAMEID(void) {
    if (ponteiroFrames > 0) {
        size[ponteiroFrames - 1] = Aguarda_Resposta[0];
    }
    Aguarda_dado("meId\":\"", "\",", "", recebeNETWORKID);
}

void recebeNETWORKID(void) {
    int i = 0;
    while (Aguarda_Resposta[i] != 0x00) {
        if (ponteiroFrames > 0) {
            int para = 0;
            para = 1;
        }
        frameId[ponteiroFrames][i] = Aguarda_Resposta[i];
        i++;
    }
    frameId[ponteiroFrames][i] = 0x00;
    Aguarda_dado("rkId\":", ",", "", recebeNODEID);
}

void recebeNODEID(void) {
    networkId[ponteiroFrames] = Aguarda_Resposta[0];
    Aguarda_dado("eId\":", ",", "", recebeFUNCTIONCODE);
}

void recebeFUNCTIONCODE(void) {
    nodeId[ponteiroFrames] = Aguarda_Resposta[0];
    Aguarda_dado("Code\":", ",", "", recebeADDRESS);
}

void recebeADDRESS(void) {
    functionCode[ponteiroFrames] = Aguarda_Resposta[0];
    Aguarda_dado("ess\":", "\",", "", recebeSIZE);
}

void recebeSIZE(void) {
    address[ponteiroFrames] = Aguarda_Resposta[0];
    Aguarda_dado("\":", ",", "", recebeFRAMEID);
    ponteiroFrames++;
}

void SETMACAddr(void) {
    CTSwifi = 1;
    int i = 0;
    while (Aguarda_Resposta[i] != 0x00) {
        MACAddress[i] = Aguarda_Resposta[i];
        i++;
    }
    MACAddress[i] = 0x00;

    limpa_Buffer_Escrita_COMM();
    limpa_Buffer_Escrita_USB();
    CTSwifi = 0;
    
    Buffer_Escrita_USB_Add_String("\r\n\r\n>MAC: ", 1);
    Buffer_Escrita_USB_Add_String(MACAddress, 1);
    Buffer_Escrita_USB_Add_String("\r\n\r\n", 1);
    
    CTSwifi = 1;
    
    inicia_Post();
}

void GETMACAddr(void) {
    Buffer_Escrita_USB_Add_String("\r\nWIFI OK - IP OK\r\n", 1);
    __delay_ms(500);
    
    Buffer_Escrita_COMM_Add_String("AT+S.GCFG=nv_wifi_macaddr\r\n", 1);
    Aguarda_dado("nv_wifi_macaddr=", "\r", "ERROR:", SETMACAddr);
}

void Aguarda_dado(char* inicio, char* fim, char* error, void *ff(void)) {
    CTSwifi = 1;
    Aguarda_Ponteiro = 0;
    sprintf(Aguarda_str, "%s", inicio);
    sprintf(Aguarda_end, "%s", fim);
    Aguarda_Funcao = ff;
    CTSwifi = 0;
}

void nada(void) {
    return;
}

void TASK_POST(void) {
    Buffer_Escrita_COMM_Add_String("AT+S.HTTPPOST=services.gerrex.com.br,/service/task,80,,,,gerrex_response.json,gerrex.json\r", 0);
    Aguarda_dado("A", "K\r", "", TASK_POST);
}

void Envia_Post_Content(void) {
    Aguarda_dado("\\0\\0\\0", "\\0\\0\\0", "ERROR:", 0x00);
    __delay_ms(2000);
    Buffer_Escrita_USB_Add_String("\r\nEnviando--->\r\n", 1);

    Buffer_Escrita_COMM_Add_String("AT+S.SOCKW=00,257\r", 1);
    Buffer_Escrita_COMM_Add_String("POST /service/task HTTP/1.1\r\n", 1);
    Buffer_Escrita_COMM_Add_String("Host: services.gerrex.com.br\r\n", 1);
    Buffer_Escrita_COMM_Add_String("Content-Type: application/json-patch+json\r\n", 1);
    Buffer_Escrita_COMM_Add_String("Content-Length: 131\r\n\r\n", 1);
    Buffer_Escrita_COMM_Add_String("{\"code\":\"11:22:33:44:55:66\",\"taskResponseFrames\":[{\"frameId\":\"c58efc7c-c1c0-48e4-956c-232817772700\",\"value\":\"4321\",\"result\":true}]}\r\n\r\n", 1);
    //SOCKET_QUERY();
    //AT+S.SOCKQ=00
    //Aguarda_Dado();)
    //AT+S.SOCKR=00,2920
    Aguarda_dado("+WIND:", ":", "", WIND);
}

void WIND(void) {
    if (Aguarda_Resposta[0] == 0x35 && Aguarda_Resposta[1] == 0x35) {
        //Aguarda_dado(":0:", "\r", "", SOCKET_QUERY);
        Aguarda_dado(":0:", "\r", "", SOCKET_RX);
    }
    if (Aguarda_Resposta[0] == 0x35 && Aguarda_Resposta[1] == 0x38) {
        Buffer_Escrita_USB_Add_String("#", 1);
    }
}

void SOCKET_QUERY(void) {
    int exit = 0;
    unsigned long timeout = 0;
    int resp_aguarda = 0;
    while (exit == 0) {
        //Buffer_Escrita_USB_Add_String("\r\nQuery Datalen\r\n");
        //while (TransmiteBuffer_USB() == 0);

        Buffer_Escrita_COMM_Add_String("AT+S.SOCKQ=00\r", 1);
        Aguarda_dado("DATALEN: ", "\r\n", "", 0x00);
        resp_aguarda = 0;
        while (resp_aguarda == 0) {
            resp_aguarda = Aguarda(0x00);

            if (resp_aguarda == 1) {
                SOCKET_RX();
                exit = 1;
            }

            timeout++;
            if (timeout >= (unsigned long) 0x5FFFF) {
                resp_aguarda = 1;
                timeout = (unsigned long) 0;
            }
        };
    }

    //while (TransmiteBuffer_COMM() == 0);
}

void SOCKET_RX(void) {
    int i = 0;

    //while (Aguarda_Resposta[i] != 0x00) {
    //Buffer_Escrita_USB_Add_String(Aguarda_Resposta);
    //    i++;
    //}
    //return;

    //INTCON0bits.GIE = 0;
    //ponteiroFrames = 0;

    Buffer_Escrita_COMM_Add_String("AT+S.SOCKR=00,", 0);
    while (Aguarda_Resposta[i] != 0x00) {
        Buffer_Escrita_COMM_Add_Char(Aguarda_Resposta[i]);
        i++;
    }
    Buffer_Escrita_COMM_Add_Char('\r');
    while (TransmiteBuffer_COMM() == 0);

    Aguarda_dado("+WIND:", ":", "", WIND);


    //recebeFRAMES();
}
//0D 0A 1A 1A 1A 0D 0A 0D 0A 4F 4B 0D 0A Fim da recepção do serviço

/*void direct_func(void (*pFunc)(void))
 {
      pFunc();
 }
 void indirect_func(void)
 {
      return;
 }
 void main(void)
 {
      direct_func(&indirect_func);
 }
 */