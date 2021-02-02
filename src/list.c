/*In list.c, write a pair of functionslistadd()andlistremove()that add and remove elements from a linkedlist*/
#include<stdlib.h>
#include "list.h"

void list_add(struct list_element *f, struct list_element *a){//check if this is right
    f->next=&a;
}

void list_remove(struct list_element *l){//check if it is in the middle of a list so you can make the previous node connect to the node connected to the soon to be deleted node?
    l->next=NULL;
}