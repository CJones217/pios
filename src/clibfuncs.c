
//#include <string.h>
#include "clibfuncs.h"

/*
 * C Library Routines 
 *
 *
 */



int strcmp ( const char * str1, const char * str2 ) {

    int k = 0;

    do {
        k++;
    } while((str1[k] == str2[k]) && (str1[k] != '\0') && (str2[k] != '\0'));

    if(str1[k] < str2[k]){
        return -1;
    } else if(str1[k] > str2[k]){
        return 1;
    } else {
        return 0;
    }
}


int toupper(char c){
    if(c >= 'a' && c<= 'z'){
        c -= 'a' - 'A';
    }
    return c;
}


