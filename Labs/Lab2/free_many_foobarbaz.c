#include <stdlib.h>
#include "main.h"

void free_many_foobarbaz(struct foobarbaz **many_foobarbaz){

    int i;

    for(i = 0; i < 20; i++){
        
        free(many_foobarbaz[i]);
        many_foobarbaz[i] = NULL;
        
    }

    free(many_foobarbaz);
    many_foobarbaz = NULL;

}