#include <stdio.h>
#include "alphabetical_printing.h"

/**
 * Prints all Words in word array sptr
 */

void print_words(char **sptr){
    int i = 0;
    for(i = 0; sptr[i] != NULL; i++){
        printf("%s\n",sptr[i]);
    }
}