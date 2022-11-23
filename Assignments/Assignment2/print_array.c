#include <stdio.h>
#include "a2.h"

/**
 * Takes a pointer to a Double_Array struct as a paramater and prints out all of the doubles stored in the array in the Double_Array struct with formatting
 */

void print_array(struct Double_Array *double_struct){

    int i;
    int j;
    int rows = double_struct -> rows;
    int cols = double_struct -> cols;

    for(i = 0; i < rows; i++){
        
        for(j = 0; j < cols; j++){

            printf("%6.1f  ", double_struct -> array[i][j]);

        }
        printf("\n");
    }

}