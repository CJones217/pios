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

    while(1){
    
    }

    
}

void zero_bss(){
    char *begin_bss = &__bss_start;
    for(int i=0;i<sizeof(begin_bss);i++){
        begin_bss[i] = 0;
    }
}
