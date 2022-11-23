#include <stdlib.h>
#include "a2.h"

/*Frees a pointer to a Double_Array struct, and the array in the Double_Array struct*/
void free_array(struct Double_Array *double_struct){

    int i;
    int rows = double_struct -> rows;

    /*Free double array*/
    for(i = 0; i < rows; i++){
        
        free(double_struct -> array[i]);

    }
    free(double_struct -> array);

    /*Free struct*/
    free(double_struct);

}