#include "list.h"

#define NULL (void*)0 //for null

void list_add(struct list_element *f, struct list_element *a){ //link first node to next node. Can change so it starts at head and adds at bottom
    struct list_element *end;
    struct list_element *new;

    end=f;
    new=a;

    end->next->prev=new;
    new->next=end->next;
    end->next=new;
    new->prev=end;


}

void list_remove(struct list_element *l){//check if it is in the middle of a list so you can make the previous node connect to the node connected to the soon to be deleted node?
    struct list_element *bye;

    bye=l;
    bye->next->prev=bye->prev;
    bye->prev->next=bye->next;    

}