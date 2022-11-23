#include <stdio.h>
#include "main.h"

void print_many_foobarbaz(struct foobarbaz **many_foobarbaz){

    int i;
    int count = 0;

    for(i = 0; i < 20; i++){

        printf("%2d foo: %2d bar: %3f baz: %2d\n",count, many_foobarbaz[i] -> foo, many_foobarbaz[i] -> bar, many_foobarbaz[i] -> baz);
        
        count++;
        
    }   

}