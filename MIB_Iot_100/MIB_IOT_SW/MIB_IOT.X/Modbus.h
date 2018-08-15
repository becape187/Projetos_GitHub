/*90
FUNÇÕES MODBUS
01 Read Coil Status
02 Read Input Status
03 Read Holding Registers
04 Read Input Registers
05 Force Single Coil
06 Preset Single Register
15 (0F Hex) Force Multiple Coils
16 (10 Hex) Preset Multiple Regs*/

//#include "Configura_Pinos.h"

#define Tam_Buffer_Modbus 2 //40
#define Numero_Registros 20

//#define Registro_TX TXREG2
//#define UART_Ocupada TXSTA2bits.TRMT

#define Read_Coil_Status 1
#define Read_Input_Status 2
#define Read_Holding_Registers 3
#define Read_Input_Registers 4
#define Force_Single_Coil 5
#define Preset_Single_Register 6
#define Force_Multiple_Coils 15
#define Preset_Multiple_Regs 16


extern unsigned char strBuffer[Tam_Buffer_Modbus];
extern unsigned int Registros[Numero_Registros];
extern unsigned  int endereco_dispositivo;
extern int TimeoutCount;
extern short int TimeOut_Threshold;


void Read_Coil_Status_0x01 (void);
void Read_Input_Status_0x02 (void);
void Read_Holding_Registers_0x03 (void);
void Read_Input_Registers_0x04 (void);
void Force_Single_Coil_0x05 (void);
void Preset_Single_Register_0x06 (void);
void Force_Multiple_Coils_0x0F (void);
void Preset_Multiple_Registers_0x10 (void);
void ModBus_Novo_Byte(char NovoByte);
void limpa(void);
void Enviar(int Tamanho,char *Buffer_Saida);
unsigned int CRC16(unsigned int dataLength,char *check);
