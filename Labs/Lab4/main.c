#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(){

    Data *head, *sort1_head, *sort2_head, *node;
    int numNodes = 0;
    int counter = 0;
    printf("Input number of nodes in linked list(must be greater than 5): \n");
    scanf("%d", &numNodes);

    if(numNodes > 5){
        ;
    }
    else{
        printf("Error - Must be a number greater than 5\n");
        exit(1);
    }

    /*Create a linked list with numNodes nodes*/
    head = create_list(numNodes);

    /*Print next links*/
    printf("Printing next links\n");
    print_list(head);
    printf("\n");

    /*Print sort1 links*/
    sort1_head = sort1(head);
    printf("Printing sort1 links\n");
    print_list_sort1(sort1_head);
    printf("\n");

    /*Print sort2 links*/
    sort2_head = sort2(head);
    printf("Printing sort2 Links\n");
    print_list_sort2(sort2_head);
    printf("\n");

    /*Going through next links and every third value is multiplied by 10*/
    node = head;
    while(node != NULL){
        counter++;
        if(counter == 3){
            node -> value *= 10;
            counter = 0;
        }
        node = node -> next; 
    }

    /*Print next links again*/
    printf("Printing next links\n");
    print_list(head);
    printf("\n");

    /*Print sort1 links again*/
    printf("Printing sort1 links\n");
    print_list_sort1(sort1_head);
    printf("\n");

    /*Print sort2 links again*/
    printf("Printing sort2 links\n");
    print_list_sort2(sort2_head);

    free_linked_list(head);
    
    return(0);
}