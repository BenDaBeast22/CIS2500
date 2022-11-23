#include <stdlib.h>

/**
 * Frees the string pointer sptr from dynamic memory 
 */

void free_sptr(char **sptr){

    int i;

    for(i = 0; sptr[i] != NULL; i++){
        free(sptr[i]);
    }

    free(sptr);
}