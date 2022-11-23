#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * Parameters: Takes in a integer num which represents the number of nodes in the list
 * Function: Creates a linked list of num size
 * Return: returns the head of the list
 */

Data * create_list(int num){
    Data *head, *ptr;
    int i;

    ptr = NULL;
    head = ptr;

    for(i = 0; i < num; i++){

        ptr = malloc(sizeof(Data));
        ptr -> value = (rand() % 11);
        ptr -> key1 = rand_double(10, 50);
        ptr -> key2 = rand_double(50, 90);
        ptr -> sort1 = NULL;
        ptr -> sort2 = NULL;
        ptr -> next = head;
        head = ptr;
    }

    return head;

}