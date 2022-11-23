#include "main.h"
#include <stdio.h>

/**
 * Parameters: Takes in the head of the list and 2 double to be swapped
 * Swaps the 2 doubles
 * Return: Return the head of the list which could be a new head from before if node was swapped with the head node
 */

Data * swap1(Data *sort1_head, double a, double b){

    /*If a and b are the same this does nothing*/
    if(a == b){
        return sort1_head;
    }

    /*Search for a*/
    Data *prevA = NULL, *currA = sort1_head;
    while(currA != NULL && currA -> key1 != a){
        prevA = currA;
        currA = currA -> sort1;
    }

    /*Search for b*/
    Data *prevB = NULL, *currB = sort1_head;
    while(currB != NULL && currB -> key1 != b){
        prevB = currB;
        currB = currB -> sort1;
    }

    /*If a or b is not found then return*/
    if(currA == NULL || currB == NULL){
        return sort1_head;
    }

    /*If a is not the head then*/
    if(prevA != NULL){
        prevA -> sort1 = currB;
    }
    /*Else make b new head*/
    else{
        sort1_head = currB;
    }

    /*If b is not the head then*/
    if(prevB != NULL){
        prevB -> sort1 = currA;
    }
    /*Else make a new head*/
    else{
        sort1_head = currA;
    }

    /*Swaps sort pointers*/
    Data *temp = currB -> sort1;
    currB -> sort1 = currA -> sort1;
    currA -> sort1 = temp;

    return sort1_head;
    
}