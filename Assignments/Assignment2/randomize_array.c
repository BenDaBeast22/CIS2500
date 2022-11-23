#include "a2.h"

/**
 * Takes in a pointer to a Double_Array struct a minimum number and maximum number to be randomized
 * Randomizes all of the doubles in the double array inside the Double_Array struct using the max and min as bounds
 */

void randomize_array(struct Double_Array *double_struct, double min, double max){

    int i;
    int j;
    int rows = double_struct -> rows;
    int cols = double_struct -> cols;

    for(i = 0; i < rows; i++){

        for(j = 0; j < cols; j++){

            double_struct -> array[i][j] = rand_double(min, max);

        }
    }

}