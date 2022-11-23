#include <stdlib.h>
#include <stdio.h>

/**
 * Frees alphabetical_array from dynamic memory
 */

void free_alphabetical_array(char ***alphabetical_array){

    int i;
    int j;

    /*Frees all word pointers from dynamic memory*/
    for(i = 0; i < 26; i++){

        for(j = 0; alphabetical_array[i][j] != NULL; j++){
            
            free(alphabetical_array[i][j]);

        }


    }

    /*Frees 26 pointers to word pointers*/
    for(i = 0; i < 26; i++){

        free(alphabetical_array[i]);
  
    }

    /*Frees pointer to 26 arrays*/
    free(alphabetical_array);

}
 