#ifndef __PAGE_H
#define __PAGE_H

struct ppage {
    struct ppage *next;
    struct ppage *prev;
    void *physical_addr;
};

void init_pfa_list();

struct ppage *allocate_physical_pages(unsigned int npages);

void free_physical_pages(struct ppage *ppage_list);

void page_list_add(struct ppage *f, struct ppage *a);
#endif