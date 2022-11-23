#include "main.h"
#include <stdio.h>

/**
 * Parameters: Takes in the head of the list and 2 double to be swapped
 * Swaps the 2 doubles
 * Return: Return the head of the list which could be a new head from before if node was swapped with the head node
 */

Data * swap2(Data *sort2_head, double a, double b){

    /*If a and b are the same does nothing*/
    if(a == b){
        return sort2_head;
    }

    /*Search for a*/
    Data *prevA = NULL, *currA = sort2_head;
    while(currA != NULL && currA -> key2 != a){
        prevA = currA;
        currA = currA -> sort2;
    }

    /*Search for b*/
    Data *prevB = NULL, *currB = sort2_head;
    while(currB != NULL && currB -> key2 != b){
        prevB = currB;
        currB = currB -> sort2;
    }

    /*If a or b is not found then return*/
    if(currA == NULL || currB == NULL){
        return sort2_head;
    }

    /*If a is not the head then*/
    if(prevA != NULL){
        prevA -> sort2 = currB;
    }
    /*Or else make b new head*/
    else{
        sort2_head = currB;
    }

    /*If b is not the head then*/
    if(prevB != NULL){
        prevB -> sort2 = currA;
    }
    /*Or else make a new head*/
    else{
        sort2_head = currA;
    }

    /*Swap sort pointers*/
    Data *temp = currB -> sort2;
    currB -> sort2 = currA -> sort2;
    currA -> sort2 = temp;

    return sort2_head;
    
}