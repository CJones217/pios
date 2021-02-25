#include "serial.h"

int *mu_io_register = 0x3F215040;

void putc(int data){
    *mu_io_register = data;
}