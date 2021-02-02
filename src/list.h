/*In list.h, define a general purpose struct for a linked list element.*/

struct list_element{
    struct list_element *next;
    struct list_element *prev;
    int data;
};
