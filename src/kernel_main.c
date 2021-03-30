#include "list.h"
#include "delays.h"
#include "rprintf.h"
#include "serial.h"
#include "page.h"
#include "fat.h"

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

    fatInit();

    struct file the_file;
    char buffer[20];

    fatOpen(&the_file,"MOM");
    esp_printf(putc, "the file has been opened\n");
    fatRead(&the_file,buffer,15);
    esp_printf(putc, "the file has been read?\n");
    esp_printf(putc, "file name: %s\n", the_file.rde.file_name);

    int count=0;
    while(count<20){
        esp_printf(putc, "%c ",buffer[count]);
        count++;
    }
    esp_printf(putc, " \n");
    esp_printf(putc, "the buffer has been printed\n");
    
    while(1){
        
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
    list_remove(&b);
    */

    /* this tests the led
    led_init(); //add this before while loop in kernel_main
    led_on(); //add this and delays and led_off in the while loop of kernel_main
    delay(10000);
    led_off();
    delay(10000);
    */

    /* this test esp_printf add to the while loop of kernel_main
    delay(10000);
    esp_printf(putc, "ascii value of j is %d\r\n", 'j');
    */

    /* put in main
        //start of page testing
    init_pfa_list();
    struct ppage *pages = free_pages;
    esp_printf(putc, "address of freepages head is %x\r\n", pages->physical_addr);
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
    struct ppage *openstuff_head = openstuff;
    esp_printf(putc, "address of openstuff0 is %x\r\n", openstuff->physical_addr);
    openstuff = openstuff->next;
    delay(10000);
    esp_printf(putc, "address of openstuff1 is %x\r\n", openstuff->physical_addr);
    openstuff = openstuff->next;
    delay(10000);
    esp_printf(putc, "address of openstuff2 is %x\r\n", openstuff->physical_addr);
    delay(10000);
    esp_printf(putc, "address of freepages head is %x\r\n", free_pages->physical_addr);
    esp_printf(putc, "now we do free physical pages %d\r\n", 'j');
    
    delay(10000);
    free_physical_pages(openstuff_head);
    struct ppage *new_pages = free_pages;
    esp_printf(putc, "address of freepages head after free pages is %x\r\n", free_pages->physical_addr);
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
    //end of page testing
    */
