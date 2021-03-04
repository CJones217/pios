/*In list.h, define a general purpose struct for a linked list element.*/

struct list_element{
    struct list_element *next;
    struct list_element *prev;
    int data;
};

void list_add(struct list_element *f, struct list_element *a);

void list_remove(struct list_element *l);
