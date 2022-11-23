#include <stdio.h>
#include <stdlib.h>
#include "alphabetical_printing.h"

int main()
{
    FILE *fp;
    FILE *fp2;
    char **sptr;
    char ***alphabetical_array;
    int *alphabetCount;

    fp = fopen("a1_words.txt","r");
    
    if(fp == NULL){
        exit(1);
    }

    sptr = read_words(fp);
    print_words(sptr);
    alphabetCount = alphabetical_word_count(sptr);

    print_alphabetical_word_count(alphabetCount);
    
    alphabetical_array = create_alphabetical_array(sptr, alphabetCount);

    print_words_alphabetically(alphabetical_array);

    free_alphabetical_array(alphabetical_array);

    free_sptr(sptr);

    free_alphabetical_word_count(alphabetCount);


    fclose(fp);

    fp2 = fopen("a1_moreWords.txt","r");
    
    if(fp2 == NULL){
        exit(1);
    }

    sptr = read_words(fp2);
    print_words(sptr);

    alphabetCount = alphabetical_word_count(sptr);

    print_alphabetical_word_count(alphabetCount);
    
    alphabetical_array = create_alphabetical_array(sptr, alphabetCount);

    print_words_alphabetically(alphabetical_array);


    free_alphabetical_array(alphabetical_array);

    free_alphabetical_word_count(alphabetCount);

    free_sptr(sptr);

    fclose(fp2);

    return(0);
}