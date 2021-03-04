#include "page.h"
#include "list.h"

#define NPAGES 128
#define NULL (void*)0 //for null
extern long __end;

struct ppage physical_page_array[NPAGES]; //128 pages, each 2mb in length covers 256 megs of memory
//array of ppages
struct ppage *head = NULL; //maybe this doesn't go here change this name

void init_pfa_list(){ //need to also add address pointer
    void* p_address = 0x200000;
    //((unsigned long)&__end & (0x200000 - 1)) +0x200000;
    struct ppage *a = &physical_page_array[0];
    head = a;
    int i;
    for(i=1;i<NPAGES;i++){// change so a = physical_page_array[i]
        struct ppage *b = &physical_page_array[i];
        physical_page_array[i].physical_addr = p_address; //(struct lsit_element*) *
        p_address += 0x200000;
        page_list_add(&a, &b);
        a=b;
    }
}

//too lazy to work on this tonight
struct ppage *allocate_physical_pages(unsigned int npages){ 
    struct ppage *allocd_list;
    struct ppage *page_to_break;
    allocd_list = head;//does this change when I change the head after the forloop?
    page_to_break = head;

    
    int i;

    for(i=1;i<npages;i++){
        page_to_break=page_to_break->next;
    }

    head=page_to_break->next;//move head to node after allocd nodes
    page_to_break->next->prev=NULL; //remove node after allocd nodes connection to last allocd node
    page_to_break->next=NULL; // remove allocd nodes connection to free pages

    return allocd_list;


}

void free_physical_pages(struct ppage *ppage_list){
    //move to end of page list and connect last node to the head, then point head at first node of this list
    struct ppage *for_head;
    struct ppage *add;
    for_head=ppage_list;
    add=ppage_list;

    while(add->next!=NULL){
        add=add->next;
    }
    add->next=head; //makes the next of the end of the list the first node in the table
    head->prev=add; //makes the first node in the tables prev equal to the last node inf the list we are adding
    head=for_head; //makes head point to the first node in the table we are adding. 
    //This should make it so head ->ppage_list_begin -> ppage_list_end -> free_list
}

void page_list_add(struct ppage *f, struct ppage *a){ //prob not finished
    struct ppage *end;
    struct ppage *new;

    end=f;
    new=a;
    //change so it only adds at the end
    //check for null
    end->next->prev=new;
    new->next=end->next;
    end->next=new;
    new->prev=end;


}