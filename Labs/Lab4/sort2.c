#include <stdio.h>
#include "main.h"
#define TRUE 1
#define FALSE 0

/*Uses sort1 links to sort key1*/

Data * sort2(Data *head){

    Data *node = head, *sort2_head = head, *nextNode;

    int restart = FALSE;

    while(node != NULL && node -> next != NULL){
        node -> sort2 = node -> next;
        node = node -> next;
    }
    
    node = head;

    while(node != NULL && node -> sort2 != NULL){
        restart = FALSE;
        nextNode = node -> sort2;
        
        if(node -> key2 > nextNode -> key2){
            sort2_head = swap2(sort2_head, node -> key2, nextNode -> key2);
            node = sort2_head;
            restart = TRUE;
        }
        if(restart == FALSE){
            node = node -> sort2;
        }

    }

    return sort2_head;
}