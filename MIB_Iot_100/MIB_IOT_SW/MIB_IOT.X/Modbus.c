#include <xc.h>
#include "Modbus.h"
#include <Serial.h>
#include "Configura_Memoria.h"
#include <stdio.h>

//#pragma udata gpr3
unsigned char strBuffer[Tam_Buffer_Modbus];
unsigned int Registros[Numero_Registros];
unsigned int EstadoInterno;
unsigned int index;
unsigned int endereco_dispositivo;
unsigned int valor;
unsigned int ponteiro;
unsigned int b;
unsigned char HighCRC = 0;
unsigned char LowCRC = 0;
int TimeoutCount = 0;
short int TimeOut_Threshold = 0;

void ModBus_Novo_Byte(char NovoByte) {
    strBuffer[index] = NovoByte;

    if (index >= 1) {
        switch (strBuffer[1]) {
            case Read_Coil_Status:
                limpa();
                break;
            case Read_Input_Status:
                limpa();
                break;
            case Read_Holding_Registers:
                Read_Holding_Registers_0x03();
                break;
            case Read_Input_Registers:
                Read_Input_Registers_0x04();
                break;
            case Force_Single_Coil:
                limpa();
                break;
            case Preset_Single_Register:
                Preset_Single_Register_0x06();
                break;
            case Force_Multiple_Coils:
                limpa();
                break;
            case Preset_Multiple_Regs:
                Preset_Multiple_Registers_0x10();
                break;
            default:
                limpa();
                goto proximo_byte;
                break;
        }
        if (index > 0)index++;
        goto proximo_byte;
    }


    if (index == 0) {
        if ((endereco_dispositivo == strBuffer[0]) || (strBuffer[0] == 254)) {
            index++;
        } else limpa();
        goto proximo_byte;
    }

    index++;

proximo_byte:

    return;
}

void Enviar(int Tamanho, char *Buffer_Saida) {

/*    int i = 0;
    Delay10KTCYx(2);

    Tris_Habilita_Tranceiver_485 = 0;
    Habilita_Tranceiver_485 = 1;
    for (i = 0; i < Tamanho; i++) {
        char temp = Buffer_Saida[i];
        Registro_TX = temp;
        while (!UART_Ocupada);
    }
    TimeOut_Threshold = 0;
    TimeoutCount = 0;

    Habilita_Tranceiver_485 = 0;*/
}

void limpa(void) {
    unsigned char i;
    for (i = 0; i < Tam_Buffer_Modbus; i++) {
        strBuffer[i] = 0x00;
    }
    index = 0;
}

void Read_Coil_Status_0x01(void) {

}

void Read_Input_Status_0x02(void) {

}

void Read_Holding_Registers_0x03(void) {
    if (index >= 7) {
        unsigned int val;
        index++;
        if (CRC16(index, strBuffer) == 0) {
            unsigned int temp;
            temp = (unsigned int) (strBuffer[2]*0x100);
            ponteiro = (unsigned int) strBuffer[3] & 0x00FF;
            ponteiro = ponteiro + temp;
            valor = (strBuffer[4]*0x100) + (unsigned int) strBuffer[5] & 0x00FF;
            valor = (valor * 2) & 0x00FF;
            strBuffer[2] = (char) valor;
            valor = valor / 2;
            for (b = 0; b < (unsigned int) valor; b++) {

                if (ponteiro >= 1000) //Array Geral
                {
                    if (ponteiro >= 2000) //Array Parametros
                    {
  //                      val = ler_int_parametros(ponteiro - 2000);
                        strBuffer[3 + (b * 2)] = (unsigned char) ((val & 0xFF00) / 0x100);
                        strBuffer[4 + (b * 2)] = (unsigned char) (val & 0x00FF);
                        goto pula;
                    }
  //                  val = ler_int_geral_mod(ponteiro - 1000);
                    strBuffer[3 + (b * 2)] = (unsigned char) ((val & 0xFF00) / 0x100);
                    strBuffer[4 + (b * 2)] = (unsigned char) (val & 0x00FF);

                } else {
                    strBuffer[3 + (b * 2)] = (unsigned char) ((Registros[ponteiro + b] & 0xFF00) / 0x100);
                    strBuffer[4 + (b * 2)] = (unsigned char) (Registros[ponteiro + b] & 0x00FF);
                }
pula:
                ponteiro = ponteiro; // placebo do goto!!!!!!
                ponteiro++;

            }

            index = 5 + (valor * 2);
            CRC16(index - 2, strBuffer);
            strBuffer[index - 2] = LowCRC; //(unsigned char)(crc_calc & 0x00FF);
            strBuffer[index - 1] = HighCRC; //(unsigned char)((crc_calc & 0xFF00) / 0x100);

            //Delay1KTCYx(255);
            Enviar(index, strBuffer);
        }
        limpa();
    }
}

void Read_Input_Registers_0x04(void) {

    Read_Holding_Registers_0x03();

}

void Force_Single_Coil_0x05(void) {

}

void Preset_Single_Register_0x06(void) {
    if (index >= 7) {
        unsigned int val;
        index++;
        if (CRC16(index, strBuffer) == 0) {
            unsigned int temp;
            valor = (strBuffer[4]*0x100) + ((unsigned int) strBuffer[5] & 0x00FF);
            temp = (unsigned int) (strBuffer[2]*0x100);
            ponteiro = (unsigned int) strBuffer[3] & 0x00FF;
            ponteiro = ponteiro + temp;
            if (ponteiro >= 1000) //Array Geral
            {
                if (ponteiro >= 2000) //Array Parametros
                {
    //                escrever_int_eeprom((ponteiro - 2000), valor);
                   
                    Enviar(index, strBuffer);
                }
    //            escrever_int_geral_mod((ponteiro - 1000), valor);

                //Delay1KTCYx(255);
                Enviar(index, strBuffer);
            } else {
 //               Registros[ponteiro] = valor;
            }


        }
        limpa();
    }
}

void Force_Multiple_Coils_0x0F(void) {

}

void Preset_Multiple_Registers_0x10(void) {
    int tam = 0;
    if (index >= 6) {
        tam = 6 + strBuffer[6] + 2;
    }
    if (index >= 6 && index >= tam) {
        index++;
        if (CRC16(index, strBuffer) == 0) {
            unsigned int temp;
            temp = (unsigned int) (strBuffer[2]*0x100);
            ponteiro = (unsigned int) strBuffer[3] & 0x00FF;
            ponteiro = ponteiro + temp;
            
            valor = strBuffer[5] & 0x00FF;
            
            for (b = 0; b < (unsigned int) valor; b++) {

                if (ponteiro >= 1000) //Array Geral
                {
                    unsigned int valor_w = (unsigned int)(strBuffer[7 + (b * 2)] * 0x100) & 0xFF00;
                    valor_w = (unsigned int)(strBuffer[8 + (b * 2)] & 0x00FF) + (unsigned int)valor_w;
                    
      //              escrever_int_geral_mod((ponteiro - 1000), valor_w);
                } 
                
                ponteiro++;
                //Saida_AD();
            }

            index = 8;
            CRC16(index - 2, strBuffer);
            strBuffer[index - 2] = LowCRC; //(unsigned char)(crc_calc & 0x00FF);
            strBuffer[index - 1] = HighCRC; //(unsigned char)((crc_calc & 0xFF00) / 0x100);

            //Delay1KTCYx(255);
            Enviar(index, strBuffer);
        }
        limpa();
    }
}

unsigned int CRC16(unsigned int dataLength, char *check) //CRC 16 para checksum modbus  modo de usar  variavel16 = crc16(8,buffer);
{
    unsigned int CheckSum;
    unsigned int j = 0;
    unsigned int i;
    unsigned int temp;
    CheckSum = 0xffff;
    for (j = 0; j < dataLength; j++) // (j=0; j<dataLength-2; j++) original
    {
        temp = check[j]&0x00FF;
        CheckSum = CheckSum^(unsigned int) temp;
        for (i = 0; i < 8; i++) {
            if ((CheckSum)&0x0001)CheckSum = (CheckSum >> 1)^0xa001;
            else CheckSum >>= 1;
        }
    }
    temp = CheckSum;
    HighCRC = CheckSum >> 8;
    CheckSum <<= 8;
    LowCRC = CheckSum >> 8;
    return (temp);
}

