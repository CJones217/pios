#include<stdlib.h> /*for null*/
#include "list.h"

void list_add(struct list_element *f, struct list_element *a){
    struct list_element *end;
    struct list_element *new;

    end=f;
    new=a;

    end->next=new;


}

void list_remove(struct list_element *l){//check if it is in the middle of a list so you can make the previous node connect to the node connected to the soon to be deleted node?
    
    l->next=NULL;
}