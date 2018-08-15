#define Clock 40000000
/*#define OERR RCSTAbits.OERR
#define FERR RCSTAbits.FERR
#define CREN RCSTAbits.CREN
#define SPEN RCSTAbits.SPEN
#define TXEN TXSTAbits.TXEN
#define RX9 RCSTAbits.RX9
#define RX9D RCSTAbits.RX9D
#define RCIF PIR1bits.RCIF
#define RCIE PIE1bits.RCIE

#define BRG16 BAUDCONbits.BRG16
#define BRGH TXSTAbits.BRGH
#define SYNC TXSTAbits.SYNC
#define TX9 TXSTAbits.TX9
#define TX9D TXSTAbits.TX9D*/

/*--------------------------------SERIAL-----------------------------------*/
/*#define TRISCtrl TRISBbits.TRISB5
#define Ctrl LATBbits.LATB5
#define TRISRx TRISCbits.TRISC7
#define TRISTx TRISCbits.TRISC6

#define Registro_TX TXREG
#define UART_Ocupada TXSTAbits.TRMT*/

#define Nenhuma 0
#define Par 1
#define Impar 2
#define Array_Habilit_Par 1 //108

#define USB 0x100
#define RS485 0x101

#define Habilita_Paridade 0//Array_Parametros[Array_Habilit_Par]

long Calcula_BaudRate(long BaudRate);
void Abre_Porta_1(int PORTA, long BaudRate);
void Abre_Porta_COMM(long BaudRate);

short int Transmite(char* dado, int PORTA);
short int Transmite_COMM(char* dado);

char Recebe(void);
char Recebe_COMM(void);

int TransmiteBuffer_COMM(void);
int TransmiteBuffer_USB(void);

short int Buffer_Escrita_COMM_Add_Char(char dado);
short int Buffer_Escrita_USB_Add_Char(char dado);


short int Buffer_Escrita_COMM_Add_String(char* dado, short int aguarda);
short int Buffer_Escrita_USB_Add_String(char *dado, short int aguarda);

void Buffer_Leitura_USB_Add_Char(char dado);

void limpa_Buffer_Leitura_USB(void);
void limpa_Buffer_Leitura_COMM(void);
void limpa_Buffer_Escrita_USB(void);
void limpa_Buffer_Escrita_COMM(void);

void AguardaINT(char dado);
int Aguarda(char dado);

int StrLen(char* dado);

int verificaFimFrame(char dado);
void verificaERRO(char dado);





extern unsigned char Aguarda_str [20];
extern unsigned char Aguarda_end [10];
extern unsigned char Aguarda_error [10];
extern unsigned char Aguarda_Resposta [100];
extern unsigned int Aguarda_Ponteiro;
extern void (*Aguarda_Funcao)(void);
extern unsigned int AguardaFrames;


#define TXIF_COMM U2ERRIRbits.TXMTIF
#define TXIF_USB U1ERRIRbits.TXMTIF
#define TX_COMM U2TXB
#define TX_USB U1TXB