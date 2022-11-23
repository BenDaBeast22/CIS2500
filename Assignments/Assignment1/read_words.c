#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alphabetical_printing.h"

/**
 * Reads words from a file into an array of words in order of words in file
 * Returns array of words
 */

char ** read_words(FILE *fp)
{
    char **sptr;
    int fileSize = 0;
    int i;
    int count = 0;

    /*fileSize is used to estimate the number of words in the files to allocate appropriate dynamic memory*/
    fileSize = file_size(fp);

    /*Allocating dynamic memory for the pointers to the words*/ 
    sptr = malloc(sizeof(char *)*fileSize);
    if(sptr == NULL){
        printf("Error - OS did not allocate dynamic memory\n");
        exit(1);
    }


    /*Allocating dynamic memory for all of the letters in each word assuming a maximum of 45 letters in a word*/
    for(i = 0; i < fileSize; i++){

        sptr[i] = malloc(sizeof(char)*MAXLETTERS);

        if(sptr[i] == NULL){
            printf("Error - OS did not allocate dynamic memory\n");
            exit(1);
        }

        /*Scanning each word from file into array holding the words*/
        if(!feof(fp)){

            fscanf(fp,"%s",sptr[i]); 
            count++;

        }
    }
    /*Setting last word in array equal to NULL pointer*/
    sptr[count] = NULL;

    return sptr; 
}