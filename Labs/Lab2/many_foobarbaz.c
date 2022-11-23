#include <stdlib.h>
#include <stdio.h>
#include "main.h"

struct foobarbaz ** many_foobarbaz(){

    int i;

    struct foobarbaz **many_foobarbaz;

    many_foobarbaz = malloc(sizeof(struct foobarbaz *)*20);

    for(i = 0; i < 20; i++){

        many_foobarbaz[i] = rand_foobarbaz(); 

        if(many_foobarbaz[i] == NULL){
            printf("Error - Dynamic memory not allocated\n");
            exit(1);
        }

    }

    return many_foobarbaz;

}