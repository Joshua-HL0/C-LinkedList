#ifndef LLIST_INT_H
#define LLIST_INT_H

#include "llist.h"

typedef struct {
    llist_node node;
    int data;
} llist_node_int;

bool llist_add_int(llist *list, int data);
void llist_free_int(llist *list);

bool match_int(llist_node *node, void* data);
void llist_print_int(llist *list);

#endif
