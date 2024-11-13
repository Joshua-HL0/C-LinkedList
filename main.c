#include "llist-int.h"
#include "llist.h"
#include "stdlib.h"
#include <stdio.h>

void addone(llist_node *node){
    ((llist_node_int*)node)->data += 1;
}

int main(){
    llist *list = calloc(1, sizeof(*list));

    llist_add_int(list, 42);
    llist_add_int(list, 12);
    llist_add_int(list, 89);
    llist_add_int(list, 34);
    llist_add_int(list, 32);
    llist_add_int(list, 11);

    llist_print_int(list);

    int target = 12;
    
    llist_node *found = llist_find(list, &match_int, &target);

    if (found){
        llist_node_int *node = (llist_node_int*)found;
        printf("found num: %d\n", node->data);
    }
    else{
        printf("Error: not found\n");
    }
    
    
    int rem = 34;
    printf("removing %d\n", rem);
    llist_remove_value(list, &match_int, &rem);
    llist_print_int(list);
   
    printf("adding one\n");
    llist_for_each(list, &addone);
    llist_print_int(list);

    llist_free_int(list);

    return 0;
}
