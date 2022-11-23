#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "frequency_table.h"

/**
 * Prints the amount of letters and characters of a text and prints the frequency of each letter in the text
 */

int main(int argc, char *argv[]){

    FILE *fp;
    int i;
    int c;
    char letter = 'A';
    int charCount = 0;
    int fFlag = FALSE;
    char *inputFile;
    int letterCount = 0;
    char inputString[10];
    int *frequency_table;
    
    if(argc > 3){

        printf("Error - to many arguments\n");
        exit(1);
    }

    for(i = 1; i < argc; i++){

        if((argv[i][0] == '-') && (argv[i][1] == 'F')){

            fFlag = TRUE;

            if(strcmp(argv[i], "-F") == 0){

                if((i+1) < argc){
                    inputFile = argv[i+1];
                }
            }
            else{
                inputFile = argv[i];
                    
                inputFile += 2;
            }
        }
    }

    frequency_table = create_freq_table();

    if(fFlag == TRUE){

        fp = fopen(inputFile, "r");
        if(fp == NULL){
            printf("File does not exist\n");
            exit(1);
        }

        while(fgets(inputString, 10, fp) != NULL){
            letterCount += letter_count(inputString);
            charCount += char_count(inputString);
            add_letters(frequency_table, inputString);
        }
        printf("Number of letters in text: %d\n", letterCount);
        printf("Number of characters in text: %d\n", charCount);
        printf("\n");

        printf("Letters: \t\t Letter Counts:\n");

        for(i = 0; i < 26; i++){

            printf("%c \t\t %9d\n", letter, frequency_table[i]);

            letter++;

        }
    }

    else{

        while((c = getchar()) != EOF){
            charCount++;   
            
            if(((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122))){
                letterCount++;
            }
            inputString[0] = c;
            inputString[1] = '\0';
            add_letters(frequency_table, inputString);
            
        }
        printf("\n");
        printf("Number of letters in the text: %d\n", letterCount);
        printf("Number of characters in text: %d\n", charCount);

        printf("\n");

        printf("Letters: \t\t Letter Counts:\n");

        for(i = 0; i < 26; i++){

            printf("%c \t\t %9d\n", letter, frequency_table[i]);

            letter++;

        }

    }
    free(frequency_table);
    if(fFlag == TRUE){
        fclose(fp);
    }

    return 0;

}
