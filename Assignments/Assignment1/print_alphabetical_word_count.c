#include <stdio.h>

/**
 * Prints the amount of words in each of the 26 array of alphabetical_array that store all words starting with specific letter from(A-Z)
 * Prints in form A = 2, B = 4 ... Z = 6
 */

void print_alphabetical_word_count(int *alphabetCount){
    int i;
    char c = 'a';
    for(i=0; i<25; i++){
        printf("%c = %d, ",c,alphabetCount[i]);
        c++;
    }
    printf("%c = %d\n",c,alphabetCount[25]);



}