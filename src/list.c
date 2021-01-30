/*In list.c, write a pair of functionslistadd()andlistremove()that add and remove elements from a linkedlist*/
#include<stdlib.h>
#include "list.h"

void list_add(struct list_element *f, struct list_element *a, int data){
    f->next=&a;
    a->data=data;
}

void list_remove(struct list_element *l){
    l->next=NULL;
}