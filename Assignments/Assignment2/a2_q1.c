#include <stdio.h>
#include "a2.h"

/*Assignment 2 Question #1 main file*/
int main(){

    int rand_row1;
    int rand_row2;
    int rand_col1;
    int rand_col2;

    struct Double_Array *double_struct;

    printf("-------------------------------------\n");
    printf("            Question 1\n");
    printf("-------------------------------------\n");

    double_struct = double_array(6, 9);

    randomize_array(double_struct,0,100);

    print_array(double_struct);

    rand_row1 = (int)rand_double(0,5);
    rand_row2 = (int)rand_double(0,5);

    swap_rows(double_struct,rand_row1, rand_row2);

    printf("\nSwapped rows %d and %d\n\n",rand_row1, rand_row2);

    print_array(double_struct);

    rand_col1 = (int)rand_double(0,8);
    rand_col2 = (int)rand_double(0,8);

    swap_columns(double_struct,rand_col1, rand_col2);

    printf("\nSwapped cols %d and %d\n\n",rand_col1, rand_col2);

    print_array(double_struct);

    free_array(double_struct);

    printf("\n\n\n");

    return(0);
}