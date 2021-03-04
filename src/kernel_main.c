#include "list.h"
#include "led.h"
#include "rprintf.h"
#include "serial.h"
#include "page.h"

#define NULL (void*)0 //for null

extern long __bss_start;
extern long __bss_end;
extern struct ppage *head; //change this name head is a bad name do free_list

//zero bss segment
void zero_bss(){
    char *begin_bss = &__bss_start;
    for(int i=0;((&__bss_start)+i) < &__bss_end;i++){
        begin_bss[i] = 0;
    }
}

//from in class activity that didn't work for anyone
unsigned long get_timer_count(){
    unsigned long *timer_count_register = 0xfe003004;
    return *timer_count_register;
}

void kernel_main() {

    init_pfa_list();
    //esp_printf(putc, "ascii value of c is %d\r\n", 'c');

    //led_init(); //blinky hw
    
    while(1){/* //blinky hw
        led_on();
        delay(10000);
        led_off();
        delay(10000);
        */
        //delay(10000);
        //esp_printf(putc, "ascii value of j is %d\r\n", 'j');
    }

    
}

    /* this zeroes out bss and tests list
    put into kernel_main()
    zero_bss();

    struct list_element d ={NULL,NULL,9};
    struct list_element c ={NULL, NULL, 3};
    struct list_element b ={NULL, NULL, 2};
    struct list_element a ={NULL, NULL,1};
    struct list_element *head = &a;

    list_add(&a,&b);
    list_add(&b,&c);
    list_add(&b,&d);
    list_remove(&b);*/


