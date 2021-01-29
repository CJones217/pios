/*Write a function that writes zeros to thebsssegment of your kernel*/

extern long __bss_start;
extern long __bss_end;


void kernel_main() {

    zero_bss();
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
