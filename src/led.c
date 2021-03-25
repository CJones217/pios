#include<stdint.h>
#include "led.h"


uint32_t *gpsel4 = 0xFE200010;
uint32_t *gpset1 = 0xFE200020;
uint32_t *gpclr1 = 0xFE20002C;
uint32_t mask = 0xFFFFFF3F;
/*mask found like this

1111 1110 0010 0000 0000 0000 0001 0000 gpsel4 to binary
&&
1111 1111 1111 1111 1111 1110 0011 1111 mask
---------------------------------------
1111 1110 0010 0000 0000 0000 0001 0000 gpsel4 with bits 8-6 zeroed

*/

//Configures the GPIO42 pin to act as an output
void led_init(){
    *gpsel4 = *gpsel4 & mask;
    *gpsel4 = *gpsel4 | 0x00000040;// number from blinky.pdf
    return;
}

//Turns the LED on by writing a 1 to GPIO pin 42
void led_on(){
    *gpset1 = *gpset1 | 0x00000400; //this should be gpio36 which is between 32 - 63 and should change gpset1
}

//Turns the ACT LED off by writint a 0 to GPIO pin 42
void led_off(){
    *gpclr1 = *gpclr1 | 0x00000400; ////this should be gpio36 which is between 32 - 63 and should change gpset1
}

