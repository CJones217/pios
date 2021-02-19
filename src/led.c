#include<stdlib.h>
#include "led.h"

void led_init(){
    return;
}

void led_on(){

}

void led_off(){

}

//From Class. just a pause to create delay when blinking or whatever
void delay(unsigned int d){
    unsigned int i, j;

    for(i=0;i<0x7f;i++){
        for(j=0;j<d;j++){
            asm("nop");
        }
    }

}