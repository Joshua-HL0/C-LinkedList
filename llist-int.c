#include "llist-int.h"
#include "llist.h"
#include <stdlib.h>
#include <stdio.h>

bool llist_add_int(llist *list, int data){
    llist_node_int *node;
    node = malloc(sizeof(*node));
    if (!node) return false;

    node->data = data;
    llist_add((llist_node*)node, list);
    return true;
}

bool match_int(llist_node* node, void* data){
    return ((llist_node_int*)node)->data == *((int*)(data));
}

void llist_print_int(llist* list){
    if (!list->head) return;
    llist_node *current = list->head;
    while (current){
        printf("%d->", ((llist_node_int*)current)->data);
        current = current->next;
    }

    printf("\n");
}

void llist_free_int(llist *list){
    if (!list->head) return;
    llist_node *current = list->head;
    llist_node *next = list->head;
    while (current){
        next = current->next;
        free(current);
        current = next;
    }
}
