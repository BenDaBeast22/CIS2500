#include <stdio.h>
#include "main.h"
#define TRUE 1
#define FALSE 0

/*Uses sort1 links to sort key1*/

Data * sort1(Data *head){

    Data *node = head, *sort1_head = head, *nextNode;

    int restart = FALSE;

    while(node != NULL && node -> next != NULL){
        node -> sort1 = node -> next;
        node = node -> next;
    }
    
    node = head;

    while(node != NULL && node -> sort1 != NULL){
        restart = FALSE;
        nextNode = node -> sort1;
        
        if(node -> key1 > nextNode -> key1){
            sort1_head = swap1(sort1_head, node -> key1, nextNode -> key1);
            node = sort1_head;
            restart = TRUE;
        }
        if(restart == FALSE){
            node = node -> sort1;
        }

    }

    return sort1_head;
}