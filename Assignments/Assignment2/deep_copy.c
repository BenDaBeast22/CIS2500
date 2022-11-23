#include <stdlib.h>
#include <stdio.h>
#include "a2.h"

/**
 * Takes in a pointer to a Double_Array struct and makes a pointer to a new Double_Array struct with all entries copied form original pointer to the Double_Aray struct
 * Returns the new Double_Array struct thats entries have all been copied from the original
 */ 

struct Double_Array * deep_copy(struct Double_Array *double_struct){

    int i;
    int j;
    struct Double_Array *struct_copy;
    int rows = double_struct -> rows;
    int cols = double_struct -> cols;

    struct_copy = malloc(sizeof(struct Double_Array));

    struct_copy -> rows = rows;
    struct_copy -> cols = cols;

    struct_copy -> array = malloc(sizeof(double)*rows);

    for(i = 0; i < rows; i++){

        struct_copy -> array[i] = malloc(sizeof(double)*cols);

    }

    for(i = 0; i < rows; i++){

        for(j = 0; j < cols; j++){

            struct_copy -> array[i][j] = double_struct -> array[i][j];

        }
    }

    return(struct_copy);

}