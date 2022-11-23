#include <stdio.h>
#include "a2.h"

/**
 * Takes in a pointer a Double_Array struct and prints the adress of the struct, the row and column size, the adress of the array and all of the elements in the array
 */

void print_struct(struct Double_Array *double_struct, char *header_string){

    int i;
    int j;
    int rows = double_struct -> rows;
    int cols = double_struct -> cols;

    printf("%s\n", header_string);

    printf("struct address = %p\n", double_struct);

    printf("row_size = %d, col_size = %d\n", rows, cols);

    printf("array address = %p, with contents:\n\n", double_struct -> array);

     for(i = 0; i < rows; i++){
        
        for(j = 0; j < cols; j++){

            printf("%4.1f  ", double_struct -> array[i][j]);

        }
        printf("\n");
    }
    printf("\n");

}