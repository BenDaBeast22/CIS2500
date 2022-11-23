#include <stdio.h>
#include <stdlib.h>
#include "a2.h"

/*Assignment 2 Question #2 main*/

int main(){

    int i;

    struct Double_Array *a1;
    struct Double_Array *a2;
    struct Double_Array *a_shallow;
    struct Double_Array *a_deep;
    struct Double_Array *b1;

    printf("-------------------------------------\n");
    printf("            Question 2a\n");
    printf("-------------------------------------\n");

    a1 = double_array(6, 9);

    randomize_array(a1, 0, 10);

    printf("The address of a1 is %p\n", &a1);

    print_struct(a1, "The structure pointed to by a1 is:");

    a2 = a1;

    printf("The address of a2 is %p\n", &a2);

    print_struct(a2, "The structure pointed to by a2 is:");

    a_shallow = shallow_copy(a1);

    printf("The address of a_shallow is %p\n",&a_shallow);

    print_struct(a_shallow, "The structure pointed to by a_shallow is:");
    
    a_deep = deep_copy(a1);
    
    printf("The address of a_deep is %p\n",&a_deep);

    print_struct(a_deep, "The structure pointed to by a_deep is:");
    
    printf("\n\n\n");

    printf("-------------------------------------\n");
    printf("            Question 2b\n");
    printf("-------------------------------------\n");

    a1 -> array[0][1] = 100.0; 
    a2 -> array[1][2] = 200.0;
    a_shallow -> array[2][3] = 300.0;
    a_deep -> array[3][4] = 400.0;

    printf("\n");

    printf("array: a1\n");
    print_array(a1);
    printf("\n");
    printf("array: a2\n");
    print_array(a2);
    printf("\n");
    printf("array: a_shallow\n");
    print_array(a_shallow);
    printf("\n");
    printf("array: a_deep\n");
    print_array(a_deep);

    printf("\n\n\n");

    printf("-------------------------------------\n");
    printf("            Question 2c\n");
    printf("-------------------------------------\n");

    b1 = double_array(6, 9);
    randomize_array(b1, 10, 20);
    
    for(i = 0; i < a1 -> rows; i++){

        free(a1 -> array[i]);
        a1 -> array[i] = NULL;

    }

    free(a1 -> array);
    a1 -> array = NULL;

    a2 -> array = b1 -> array;

    printf("array: a1\n");
    print_array(a1);
    printf("\n");
    printf("array: a2\n");
    print_array(a2);
    printf("\n");
    printf("array: a_shallow\n");
    print_array(a_shallow);
    printf("\n");
    printf("array: a_deep\n");
    print_array(a_deep);
    printf("\n");
    printf("array: b1\n");
    print_array(b1);
    printf("\n");

    a1 -> array[0][1] = 5000.0;
    a2 -> array[1][2] = 6000.0;
    a_shallow -> array[2][3] = 700.0;
    a_deep -> array[3][4] = 8000.0;
    b1 -> array[4][5] = 9000.0;

    printf("array: a1\n");
    print_array(a1);
    printf("\n");
    printf("array: a2\n");
    print_array(a2);
    printf("\n");
    printf("array: a_shallow\n");
    print_array(a_shallow);
    printf("\n");
    printf("array: a_deep\n");
    print_array(a_deep);
    printf("\n");
    printf("array: b1\n");
    print_array(b1);

    /*Freeing all malloced memory*/
    
    free_array(a1);
    free(b1);
    free_array(a_deep);

    return(0);
}