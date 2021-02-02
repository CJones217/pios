#include<stdlib.h>
#include "list.h"

extern long __bss_start;
extern long __bss_end;


void kernel_main() {
    zero_bss();

    struct list_element c = {NULL,2};
    struct list_element b = {NULL,1};
    struct list_element a = {NULL, 0};
    struct list_element *head = &a;

    list_add(a, b);
    list_add(b,c);
    list_remove(b);
    int z =0;

    while(1){
    
    }

    
}

void zero_bss(){
    char *begin_bss = &__bss_start;
    char *end_bss = &__bss_end;
    begin_bss[0] = 0x0c;
    end_bss[1] =0x0b;
    int x =0;
    while(&begin_bss[x] != &end_bss){
        begin_bss[x] = 0;
        x++;
    }
}
