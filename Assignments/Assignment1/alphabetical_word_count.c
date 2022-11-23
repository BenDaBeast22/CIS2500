#include <stdlib.h>
#include <stdio.h>

/**
 * Counts the number of words begin with each letter in sptr an array of words
 * Creates an array called alphabetCount Dynamically in order to store count
 * Returns alphabetCount
 */

int * alphabetical_word_count(char **sptr){

    int i;
    int c; /*character from string array represented as int*/
    int *alphabetCount = malloc(sizeof(int)*26);
    if(alphabetCount == NULL){
        printf("Error - OS did not allocate dynamic memory\n");
        exit(1);
    }

    for(i = 0; i < 26; i++){
        alphabetCount[i] = 0;
    }

    /*Counts the number of words starting with each letter in sptr(array of words)*/
    for(i = 0; sptr[i] != NULL; i++){

        c = sptr[i][0];

        if((c >= 65) && (c <= 90)){ /*Converting all first chars to lowercase*/

            c += 32;
        }
        c -= 97; /*Converting all characters into integers starting from 0 to 25*/

        alphabetCount[c] += 1; /*Now appends character to corresponding letter of alphabet (a=0, b=1, ..., z=25)*/   
    }

    return alphabetCount;
}