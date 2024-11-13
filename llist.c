#include "llist.h"

void llist_add(llist_node *node, llist *list){
    node->next = list->head;
    list->head = node;
}

void llist_remove(llist_node *node, llist *list){ // this accepts a pointer to a node, another function will accept a function pointer "match"
    if (!list->head || !node) return;                    // to be able to compare data so the user doesn't have to keep pointers

    if (list->head == node) list->head = node->next;
    else{
        llist_node *current = list->head;
        while (current->next && current->next != node){
            current = current->next;
        }
        if (current->next == node){
            current->next = node->next;
        }
    }
}

llist_node* llist_find(llist *list, bool (*match)(llist_node*, void*), void* data){ // user is expected to use a function which matches their data type in their child struct
    llist_node *current = list->head;
    while (current){
        if (match(current, data)){
            return current;
        }
        current = current->next;
    }
    return (void*)0;
}

void llist_for_each(llist *list, void (*function)(llist_node*)){
    llist_node *current = list->head;
    while (current){
        function(current);
        current = current->next;
    }
}


void llist_remove_value(llist *list, bool(*match)(llist_node*, void*), void* data){
    llist_node* pos = llist_find(list, match, data);
    llist_remove(pos, list);
}
