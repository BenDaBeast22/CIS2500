#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alphabetical_printing.h"

/*
 * Creates an array called alphabetical_array that stores words thats first letter begin with each letter of the alphabet(A-Z) 
 * Fills each array with words thats first letter beggins with (A-Z)
 * Returns a char pointer to alphabetical_array
 */

char *** create_alphabetical_array(char **sptr, int *alphabetCount){

    int i;
    int j;
    int c = 0;
    int maxWords = 0;
    char ***alphabetical_array;
    int *elementNumber;

    /*Allocate dynamic memory for an int array of size 26*/

    elementNumber = malloc(sizeof(int)*26); 
    if(elementNumber == NULL){
        printf("Error - OS did not allocate dynamic memory\n");
        exit(1);
    }
    for(i = 0; i < 26; i++){
        elementNumber[i] = 0;
    }

    /*Allocate dynamic memory for the 26 arrays storing words with each of first letters(A-Z)*/
    
    alphabetical_array = malloc(sizeof(char **)*26);
    if(alphabetical_array == NULL){
        printf("Error - OS did not allocate dynamic memory\n");
        exit(1);
    }

    /*Allocates dynamic memory for every word stored in the 26 arrays(A-Z) of alphabetical_array */

    
    for(i = 0; i < 26; i++){ 

        maxWords = alphabetCount[i];
        alphabetical_array[i] = malloc(sizeof(char *)*(maxWords+1)); 
        if(alphabetical_array[i] == NULL){
            printf("Error - OS did not allocate dynaimc memory\n");
            exit(1);
        }
    }

    /*Allocates dynamic memory for the letters in each word of alphabetical_array*/
    
    
    for(i = 0; i < 26; i++){ 
        maxWords = alphabetCount[i];

        for(j = 0; j < maxWords; j++){
            alphabetical_array[i][j] = malloc(sizeof(char)*MAXLETTERS);
            if(alphabetical_array[i][j] == NULL){
                printf("Error - OS did not allocate dynamic memory\n");
                exit(1);
            }
        }
    }
    
    j = 0;

    /*Assigning all words from sptr to the corresponding alphabetical_array that the first letter of the word starts with*/

    for(i = 0; sptr[i] != NULL; i++){

        c = sptr[i][0];
        if((c >= 65) && (c <= 90)){ /*Converting all first chars to lowercase*/
            c += 32;
        }
        c -= 97; /*Converting all characters into integers starting from 0 to 25*/

        j = elementNumber[c];

        elementNumber[c] += 1;

        strcpy(alphabetical_array[c][j], sptr[i]);
    }

    j = 0;

    /*Setting all of the last words in alphabetical_array to NULL*/

    for(i = 0; i < 26; i++){

        j = elementNumber[i];

        alphabetical_array[i][j] = NULL;
        
    }

    free(elementNumber);

    return alphabetical_array;

}