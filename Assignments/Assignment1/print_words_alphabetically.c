#include <stdio.h>
#include "alphabetical_printing.h"

/**
 * Prints words from the alphabetical_array of each word starting with each letter
 * Prints in the format:
 * 'A'
 * Apple
 * Ant
 * For every letter in alphabet from(A-Z)
 */

void print_words_alphabetically(char ***alphabetical_array){

    int i;
    char c;

    for(i = 0; i < 26; i++){
        c = i+65;
        printf("'%c'\n",c);
        print_words(alphabetical_array[i]);
    }

}