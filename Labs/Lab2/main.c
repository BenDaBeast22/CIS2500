#include <stdio.h>
#include "main.h"

int main(){

    int swap1;
    int swap2;

    struct foobarbaz **array_foobarbaz;
    
    array_foobarbaz = many_foobarbaz();
    
    print_many_foobarbaz(array_foobarbaz);

    swap1 = (int)rand_double(0,19);
    swap2 = (int)rand_double(0,19);

    printf("\nSwap1: %d\n\n",swap1);
    printf("Swap2: %d\n\n",swap2);

    swap_structures(array_foobarbaz,swap1,swap2);

    print_many_foobarbaz(array_foobarbaz);

    free_many_foobarbaz(array_foobarbaz);

    return(0);
}