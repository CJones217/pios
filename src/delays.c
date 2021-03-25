#include "delays.h"

void delay(unsigned int d){
    unsigned int i, j;

    for(i=0;i<0x7f;i++){
        for(j=0;j<d;j++){
            asm("nop");
        }
    }

}