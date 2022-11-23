#include <stdio.h>
#include "main.h"

/**
 * Prints out the linked list using nodes sort1 links to traverse the list
 */

void print_list_sort1(Data *node){

    while(node != NULL){

        printf("[ node->%2d, node->%f, node->%f> ]\n",node -> value, node -> key1, node -> key2);
        
        node = node -> sort1;
  
    }
}