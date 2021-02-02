/*In list.c, write a pair of functionslistadd()andlistremove()that add and remove elements from a linkedlist*/
#include<stdlib.h> /*for null*/
#include "list.h"

/*list add is from https://www.codesdope.com/blog/article/inserting-a-new-node-in-a-linked-list-in-c/*/
/*void list_add(struct list_element *f, int new_data){//check if this is right
    struct list_element *end;
    struct list_element *new_node;
    new_node->data=new_data;
    new_node->next=NULL;

    end=f;
    if(end->next==NULL){
        end->next=new_node;
    }

    else{
        
        while(end->next){
            end = end->next;
        }
        end->next=new_node;
    }
}*/

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