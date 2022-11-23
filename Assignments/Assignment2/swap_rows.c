#include "a2.h"

/**
 * Swaps the num1 row with the num2 row of the double array inside a pointer to a Double_Array struct
 */
int swap_rows(struct Double_Array *double_struct, int num1, int num2){

    int j;
    double old_num1;
    int rows = double_struct -> rows;
    int cols = double_struct -> cols;

    if((num1 >= 0) && (num1 < rows) && (num2 >= 0) && (num2 <rows)){

        for(j = 0; j < cols; j++){

            old_num1 = double_struct -> array[num1][j];

            double_struct -> array[num1][j] = double_struct -> array[num2][j];

            double_struct -> array[num2][j] = old_num1;

        }

        return(1);
    }

    else{

        return(0);
        
    }

}