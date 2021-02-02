#include<stdlib.h>
#include "list.h"

extern long __bss_start;
extern long __bss_end;


void kernel_main() {
    zero_bss();

    struct list_element c ={NULL, 3};
    struct list_element b ={NULL, 2};
    struct list_element a ={NULL,1};
    struct list_element *head = &a;

    list_add(&a,&b);
    list_add(&b,&c);
    list_remove(&a);
    int bpoint = 0;

    while(1){
    
    }

    
}

void zero_bss(){
    char *begin_bss = &__bss_start;
    //char *end_bss = &__bss_end; prob don't need this with for loop
    begin_bss[0] = 0x0c;
    //end_bss[1] =0x0b;
    int breakpoint =0;
    for(int i=0;i<sizeof(begin_bss);i++){
        begin_bss[i] = 0;
    }
}
