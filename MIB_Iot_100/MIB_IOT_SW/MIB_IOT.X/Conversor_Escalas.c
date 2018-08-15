/*
 * File:   Conversor_Escalas.c
 * Author: Bernardo Leite
 *
 * Created on 24 de Abril de 2018, 18:15
 */
#include <Serial.h>
#include "Conversor_Escalas.h"
#include "Configura_Pinos.h"
#include "GERREX.h"
#include <stdio.h>
#include <xc.h>
float m = 0;
int Max_Saida1 = 10;
int Min_Saida1 = 0;
int Max_Entrada1 = 432;
int Min_Entrada1 = 188;

//int Max_Saida1 = 1000;
//int Min_Saida1 = 0;
//int Max_Entrada1 = 2845;
//int Min_Entrada1 = 192;

int Max_Saida2 = 20;
int Max_Entrada2 = 654;

int Max_Saida3 = 30;
int Max_Entrada3 = 942;

int Max_Saida4 = 40;
int Max_Entrada4 = 1220;

int Max_Saida5 = 50;
int Max_Entrada5 = 1515;

int Max_Saida6 = 60;
int Max_Entrada6 = 1734;

int Max_Saida7 = 70;
int Max_Entrada7 = 2068;

int Max_Saida8 = 80;
int Max_Entrada8 = 2303;

int Max_Saida9 = 90;
int Max_Entrada9 = 2587;

int Max_Saida10 = 100;
int Max_Entrada10 = 2795;


int Max_Saida;
int Min_Saida;
int Max_Entrada;
int Min_Entrada;

unsigned int samples [50];
unsigned long sample_result = 0;
unsigned long saida;
float offset;
int ponteiro_analog = 0;

int resultado_polinomio;

char high = 0;
char low = 0;
int valor_AD = 0;
int mudou = 0;
int SELECIONA = 0;

void Verifica_Analogica(void) {
    char valoradstr [10];

    if (ADCON0bits.GO == 0) {
        high = ADRESH;
        low = ADRESL;
        valor_AD = (int) (high * 0x100) + low;

        sample_result = sample_result + valor_AD;

        if (ponteiro_analog >= 5) {
            ponteiro_analog = 0;
            sample_result = sample_result / 5;
            valor_AD = (int) sample_result;

            //sample_result = polinomio(valor_AD);

            ajusta_escala(valor_AD);

            //sprintf(valoradstr, ",%i\r", valor_AD);
            Converte_Escala();

            sprintf(valoradstr, "%i -> %i | \r\n", valor_AD, (int) saida, m);
            //valor_AD = (int) saida;
            Buffer_Escrita_USB_Add_String(valoradstr, 0);
            //ANALOG_CMD ^= 1;
            MEMORIA[ANALOG_CMD] = (long) saida;
            
        } else {
            ponteiro_analog++;
        }
        ADCON0bits.GO = 1;
    }
}

void ajusta_escala(int valor) {
    if (valor >= Min_Entrada1 && valor <= Max_Entrada1) {
        Max_Saida = Max_Saida1;
        Min_Saida = Min_Saida1;
        Max_Entrada = Max_Entrada1;
        Min_Entrada = Min_Entrada1;
    }
    //goto fim;

    if (valor > Max_Entrada1 && valor <= Max_Entrada2) {
        Max_Saida = Max_Saida2;
        Min_Saida = Max_Saida1; //
        Max_Entrada = Max_Entrada2;
        Min_Entrada = Max_Entrada1;
    }

    if (valor > Max_Entrada2 && valor <= Max_Entrada3) {
        Max_Saida = Max_Saida3;
        Min_Saida = Max_Saida2;
        Max_Entrada = Max_Entrada3;
        Min_Entrada = Max_Entrada2;
    }

    if (valor > Max_Entrada3 && valor <= Max_Entrada4) {
        Max_Saida = Max_Saida4;
        Min_Saida = Max_Saida3;
        Max_Entrada = Max_Entrada4;
        Min_Entrada = Max_Entrada3;
    }

    if (valor > Max_Entrada4 && valor <= Max_Entrada5) {
        Max_Saida = Max_Saida5;
        Min_Saida = Max_Saida4;
        Max_Entrada = Max_Entrada5;
        Min_Entrada = Max_Entrada4;
    }
    if (valor > Max_Entrada5 && valor <= Max_Entrada6) {
        Max_Saida = Max_Saida6;
        Min_Saida = Max_Saida5;
        Max_Entrada = Max_Entrada6;
        Min_Entrada = Max_Entrada5;
    }
    if (valor > Max_Entrada6 && valor <= Max_Entrada7) {
        Max_Saida = Max_Saida7;
        Min_Saida = Max_Saida6;
        Max_Entrada = Max_Entrada7;
        Min_Entrada = Max_Entrada6;
    }

    if (valor > Max_Entrada7 && valor <= Max_Entrada8) {
        Max_Saida = Max_Saida8;
        Min_Saida = Max_Saida7;
        Max_Entrada = Max_Entrada8;
        Min_Entrada = Max_Entrada7;
    }

    if (valor > Max_Entrada8 && valor <= Max_Entrada9) {
        Max_Saida = Max_Saida9;
        Min_Saida = Max_Saida8;
        Max_Entrada = Max_Entrada9;
        Min_Entrada = Max_Entrada8;
    }

    if (valor > Max_Entrada9 && valor <= Max_Entrada10) {
        Max_Saida = Max_Saida10;
        Min_Saida = Max_Saida9;
        Max_Entrada = Max_Entrada10;
        Min_Entrada = Max_Entrada9;
    }

//fim:

    Calcula_Fator_m();
}

void Converte_Escala(void) {
    //if ((unsigned int) valor_AD >= (unsigned int) Min_Entrada) {
    //saida = (unsigned long) ((unsigned int) valor_AD - (unsigned int) Min_Entrada);
    //} else {
    //    saida = 0;
    //}
    offset = (float) ((long) Max_Saida - (long) (m * Max_Entrada));
    
    saida = (unsigned long) (((float) valor_AD * (float) m) + offset);
    //saida = saida + Min_Saida;
    
    if (saida < 0) {
        saida = 0;
    }

    /*if (saida < Min_Saida) {
        saida = Min_Saida;
    }
    if (saida > Max_Saida) {
        saida = Max_Saida;
    }*/
    if (saida > 1000) {
        saida = 1000;
    }
}

void Calcula_Fator_m(void) {
    float mX;
    float mY;
    //unsigned int d=0;

    //for (i = 0; i < 4; i++) {
    mY = Max_Saida - Min_Saida; //Range de saida
    mX = Max_Entrada - Min_Entrada; //Range de entrada
    m = mY / mX; //Fator multiplicador
    //}
    //i = 0;
}

int polinomio(int x) {
    //int x;
    //int Px;

    int x0 = 168;
    int x1 = 569;
    int x2 = 828;
    int x3 = 2837;

    int fx0 = 0;
    int fx1 = 151;
    int fx2 = 250;
    int fx3 = 1000;

    float D1;
    float D1temp1;
    float D1temp2;

    float D2;
    float D2temp1;
    float D3;

    D1 = (float) (fx1 - fx0) / (float) (x1 - x0);
    D1temp1 = (float) (fx2 - fx1) / (float) (x2 - x1);
    D1temp2 = (float) (fx3 - fx2) / (float) (x3 - x2);

    D2 = (float) (D1temp1 - D1) / (float) (x2 - x0);
    D2temp1 = (float) (D1temp2 - D1temp1) / (float) (x3 - x1);

    D3 = (float) (D2temp1 - D2) / (float) (x3 - x0);

    return (int) (fx0 + (x - x0) * D1 + (x - x0) * (x - x1) * D2 + (x - x0)*(x - x1)*(x - x2) * D3);

    //f(x0) + (x-x0)
}