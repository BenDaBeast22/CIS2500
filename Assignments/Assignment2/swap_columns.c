#include "a2.h"

/**
 * Swaps the num1 column with the num2 column of the double array of a pointer to a Double_Array struct 
 */

int swap_columns(struct Double_Array *double_struct, int num1, int num2){

    int i;
    double old_num1;
    int rows = double_struct -> rows;
    int cols = double_struct -> cols;

    if((num1 >= 0) && (num1 < cols) && (num2 >= 0) && (num2 < cols)){

        for(i = 0; i < rows; i++){

            old_num1 = double_struct -> array[i][num1];

            double_struct -> array[i][num1] = double_struct -> array[i][num2];

            double_struct -> array[i][num2] = old_num1;

        }
        
        return(1);

    }

    else{

        return(0);
    }



}