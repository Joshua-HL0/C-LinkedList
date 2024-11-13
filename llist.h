#ifndef LLIST_H
#define LLIST_H

#include <stdbool.h>

typedef struct llist_node {  // this implementation will use struct inheretance, so that further linked lists with specific data types can be
   struct llist_node *next;        // implemented on top of this one as needed. often this can be better than using void pointers as it avoids having to 
} llist_node;                // do 2 mallocs, 1 for the struct and 1 for the data inside. an example child struct will be implemented in a different file

typedef struct {
    llist_node *head;
} llist;
 
void llist_add(llist_node *node, llist *list);
void llist_remove(llist_node *node, llist *list);
llist_node* llist_find(llist *list, bool (*match)(llist_node*, void*), void* data);
void llist_for_each(llist *list, void (*function)(llist_node*));
void llist_reverse(llist *list);
void llist_remove_value(llist *list, bool(*match)(llist_node*, void*), void* data);


#endif
