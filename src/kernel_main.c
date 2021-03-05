#include "list.h"
#include "led.h"
#include "rprintf.h"
#include "serial.h"
#include "page.h"

#define NULL (void*)0 //for null

extern long __bss_start;
extern long __bss_end;
extern struct ppage *free_pages;

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
    struct ppage *pages = free_pages;
    struct ppage *new_pages = free_pages;
    delay(10000);
    esp_printf(putc, "address of page0 is %x\r\n", pages->physical_addr);
    pages = pages->next;
    delay(10000);
    esp_printf(putc, "address of page1 is %x\r\n", pages->physical_addr);
    pages = pages->next;
    delay(10000);
    esp_printf(putc, "address of page2 is %x\r\n", pages->physical_addr);
    pages = pages->next;
    delay(10000);
    esp_printf(putc, "address of page3 is %x\r\n", pages->physical_addr);
    delay(10000);
    
    unsigned int get_ma_pages=3;
    struct ppage *openstuff = allocate_physical_pages(get_ma_pages);
    esp_printf(putc, "address of openstuff0 is %x\r\n", openstuff->physical_addr);
    openstuff = openstuff->next;
    delay(10000);
    esp_printf(putc, "address of openstuff1 is %x\r\n", openstuff->physical_addr);
    openstuff = openstuff->next;
    delay(10000);
    esp_printf(putc, "address of openstuff2 is %x\r\n", openstuff->physical_addr);
    delay(10000);

    esp_printf(putc, "now we do free physical pages %d\r\n", 'j');
    esp_printf(putc, "address of newoage before free pages is %x\r\n", new_pages->physical_addr);
    delay(10000);
    free_physical_pages(openstuff);
    
    delay(10000);
    esp_printf(putc, "address of page0 is %x\r\n", new_pages->physical_addr);
    new_pages = new_pages->next;
    delay(10000);
    esp_printf(putc, "address of page1 is %x\r\n", new_pages->physical_addr);
    new_pages = new_pages->next;
    delay(10000);
    esp_printf(putc, "address of page2 is %x\r\n", new_pages->physical_addr);
    new_pages = new_pages->next;
    delay(10000);
    esp_printf(putc, "address of page3 is %x\r\n", new_pages->physical_addr);

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
        
        /*
        esp_printf(putc, "address of page0 is %x\r\n", pages->physical_addr);
        pages = pages->next;
        delay(10000);
        */
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


