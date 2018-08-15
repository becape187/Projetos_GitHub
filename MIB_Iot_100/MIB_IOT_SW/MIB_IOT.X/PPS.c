#include "Config_uC.h"
#include "PPS.h"

void lock_PPS(){
    INTCON0bits.GIE = 1;
    INTCON0bits.GIEL = 1;
    INTCON0bits.GIEH = 1;
    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCK = 1;
}

void unLock_PPS(){
    INTCON0bits.GIE = 0;
    INTCON0bits.GIEL = 0;
    INTCON0bits.GIEH = 0;
    PPSLOCK = 0x55;
    PPSLOCK = 0xAA;
    PPSLOCK = 0;
}