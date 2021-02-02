#include<stdlib.h>
#include "list.h"

extern long __bss_start;
extern long __bss_end;


void kernel_main() {
    zero_bss();

    struct list_element* head =NULL;

    list_add(&head, 1);
    list_add(&head,3);
    list_remove(&head);
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
