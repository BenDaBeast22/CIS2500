#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/*Frees all of the nodes in linked list*/

void free_linked_list(Data *head){
    
    Data *oldNode = NULL, *newHead = head;
    while(newHead != NULL){

        oldNode = newHead;
        newHead = newHead -> next;
        free(oldNode); 

    }

}