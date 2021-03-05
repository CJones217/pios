#include "page.h"
#include "list.h"

#define NPAGES 128
#define NULL (void*)0 //for null
extern long __end;

struct ppage physical_page_array[NPAGES]; //128 pages, each 2mb in length covers 256 megs of memory
//array of ppages
struct ppage *free_pages = NULL; //maybe this doesn't go here change this name

void init_pfa_list(){ //need to also add address pointer
    void* p_address = 0x200000;
    ((unsigned long)&__end & (0x200000 - 1)) +0x200000; //from class
    struct ppage *a = &physical_page_array[0];
    physical_page_array[0].physical_addr = p_address;
    p_address += 0x200000;
    free_pages = a;
    int i;
    for(i=1;i<NPAGES;i++){// change so a = physical_page_array[i]
        struct ppage *b = &physical_page_array[i];
        physical_page_array[i].physical_addr = p_address; //(struct lsit_element*) *
        p_address += 0x200000;
        page_list_add(a, b);
        a=b;
    }
}

struct ppage *allocate_physical_pages(unsigned int npages){ 
    struct ppage *allocd_list;
    struct ppage *page_to_break;
    allocd_list = free_pages;//does this change when I change the free_pages after the forloop?
    page_to_break = free_pages;

    int i;
    for(i=1;i<npages;i++){
        page_to_break=page_to_break->next;
    }

    free_pages=page_to_break->next;//move free_pages to node after allocd nodes
    page_to_break->next->prev=NULL; //remove node after allocd nodes connection to last allocd node
    page_to_break->next=NULL; // remove allocd nodes connection to free pages

    return allocd_list;

}

void free_physical_pages(struct ppage *ppage_list){
    //move to end of page list and connect last node to the free_pages, then point free_pages at first node of this list
    struct ppage *for_free_pages;
    struct ppage *add;
    for_free_pages=ppage_list;
    add=ppage_list;

    while(add->next!=NULL){
        add=add->next;
    }
    add->next=free_pages; //makes the next of the end of the list the first node in the table
    free_pages->prev=add; //makes the first node in the tables prev equal to the last node inf the list we are adding
    free_pages=for_free_pages; //makes free_pages point to the first node in the table we are adding. 
    //This should make it so free_pages ->ppage_list_begin -> ppage_list_end -> free_list
}

void page_list_add(struct ppage *f, struct ppage *a){ //prob not finished
    struct ppage *end;
    struct ppage *new;

    end=f;//end of list
    new=a;//what to add
    //change so it only adds at the end
    //check for null 
    end->next=new;
    new->prev=end;


}