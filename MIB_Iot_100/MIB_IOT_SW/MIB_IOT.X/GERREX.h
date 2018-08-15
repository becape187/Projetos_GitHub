void GETTask(void);
void GETMACAddr(void);
void preenche_Aguarda_str (char* dado);
void preenche_Aguarda_end(char* dado);
void Aguarda_dado(char* inicio, char* fim, char* error, void *ff (void));
void recebeFRAMEID(void);
void recebeNETWORKID(void);
void recebeNODEID(void);
void recebeFUNCTIONCODE(void);
void recebeADDRESS(void);
void recebeSIZE(void);
void recebeFRAMES(void);
void testaRespostaHTTP(void);
int trataRespostaHTTP(void);
void TASK_POST(void);
void Envia_Post_Content(void);
void SOCKET_RX(void);
void SOCKET_QUERY(void);
void WIND(void);
void nada(void);

extern char MACAddress [18];
//void cria_Arquivo(void);


#define HTTP200 1
#define HTTP204 2
#define HTTP404 3

extern unsigned int RecebendoFrames;

#define quantidadeFrames 30
extern int tamFrames;
extern char frameId[quantidadeFrames][37];
extern int networkId[quantidadeFrames];
extern int nodeId[quantidadeFrames];
extern int functionCode[quantidadeFrames];
extern int address[quantidadeFrames];
extern int size[quantidadeFrames];
extern long value[quantidadeFrames];
extern short int result[quantidadeFrames];

extern long MEMORIA[10];