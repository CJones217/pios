#ifndef __LIST_H
#define __LIST_H

struct list_element{
    struct list_element *next;
    struct list_element *prev;
};

void list_add(struct list_element *f, struct list_element *a);

void list_remove(struct list_element *l);
#endif