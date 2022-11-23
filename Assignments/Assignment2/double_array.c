#include <stdlib.h>
#include "a2.h"

/**
 * Takes two parameter number of rows and cols and creates a pointer to a Double_Array struct and dynamically allocates a Double_Array struct and a double array in the Double_Struct to memory
 * Returns the pointer to the Double_Array struct
 */ 

struct Double_Array * double_array(int row, int col){

    int i;
    struct Double_Array *double_struct;

    double_struct = malloc(sizeof(struct Double_Array));

    double_struct -> array = malloc(sizeof(double *)*row);

    for(i = 0; i < row; i++){

        double_struct -> array[i] = malloc(sizeof(double)*col);

    }

    double_struct -> rows = row;
    double_struct -> cols = col;

    return double_struct;
    
}