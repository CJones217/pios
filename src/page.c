#include "page.h"

#define NULL (void*)0 //for null
struct ppage physical_page_array[128]; //128 pages, each 2mb in length covers 256 megs of memory
//array of ppages
struct ppage *head; //maybe this doesn't go here

void init_pfa_list(){

    struct ppage a = physical_page_array[0];
    head = &a;
    int i;
    for(i=1;i<128;i++){// change so a = physical_page_array[i]
        struct ppage b = physical_page_array[i];
        page_list_add(&a, &b);
        a=b;
    }
}

//too lazy to work on this tonight
/*struct ppage *allocate_physical_pages(unsigned int npages){ 
    int i=0;
    while(){

    }
}*/

void free_physical_pages(struct ppage *ppage_list){

}

void page_list_add(struct ppage *f, struct ppage *a){ //prob not finished
    struct ppage *end;
    struct ppage *new;

    end=f;
    new=a;

    end->next->prev=new;
    new->next=end->next;
    end->next=new;
    new->prev=end;


}