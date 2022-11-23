#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/*Generates a struct pointer with random initialized values*/
struct foobarbaz * rand_foobarbaz(){

    struct foobarbaz *rand_foobarbaz;

    /*Allocate memory for struct*/
    rand_foobarbaz = malloc(sizeof(struct foobarbaz));
    
    if(rand_foobarbaz == NULL){
        printf("Error - Dynamic memory not allocated\n");
        exit(1);
    }
    /*Initialize struct variables*/
    rand_foobarbaz -> foo = (int)rand_double(0, 49);
    rand_foobarbaz -> bar = rand_double(0, 100);
    rand_foobarbaz -> baz = (int)rand_double(50, 99);

    return rand_foobarbaz;
}