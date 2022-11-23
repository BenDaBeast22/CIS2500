#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "decode.h"

/**
 * Guesses the shift of an encoded text and decodes the text
 */
int main(int argc, char *argv[]){

    FILE *fp;
    FILE *fp2;
    int i;
    int j;
    int c;
    int letter = 'A';
    int shift;
    int originalShift;
    int decodeShift;
    double chiValue;

    int fFlag = FALSE;
    int oFlag = FALSE;
    int sFlag = FALSE;
    int nFlag = FALSE;
    int tFlag = FALSE;
    int SFlag = FALSE;
    int xFlag = FALSE;
    int letterCount = 0;
    int charCount = 0;
    char *inputFile;
    char *outputFile;
    char outputString[10];
    char inputString[10];
    char stdinInput[1000];
    int *frequency_table;

    for(i = 1; i < argc; i++){

        /*Determines if -F flag was inputted*/
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

        /*Determines if -O flag was inputted*/
        if((argv[i][0] == '-') && (argv[i][1] == 'O')){
            oFlag = TRUE;
            if(strcmp(argv[i],"-O") == 0){
                if((i+1) < argc){
                    outputFile = argv[i+1];
                }
            }
            else{
                outputFile = argv[i];

                outputFile += 2;
            }
        }
        if((argv[i][0] == '-') && ((argv[i][1] == 's') || (argv[i][1] == 't') || (argv[i][1] == 'x') || (argv[i][1] == 'n') || (argv[i][1] == 'S'))){
    
            if(argv[i][1] == 's'){
                sFlag = TRUE;

                for(j = 2; j < 6; j++){

                    if((argv[i][j]) == 't'){
                        tFlag = TRUE;
                    }
                    if((argv[i][j]) == 'S'){
                        SFlag = TRUE;
                    }
                    if((argv[i][j]) == 'x'){
                        xFlag = TRUE;
                    }
                    if((argv[i][j]) == 'n'){
                        nFlag = TRUE;
                    }
                }
            }
            if(argv[i][1] == 't'){
                tFlag = TRUE;

                for(j = 2; j < 6; j++){

                    if((argv[i][j]) == 's'){
                        sFlag = TRUE;
                    }
                    if((argv[i][j]) == 'x'){
                        xFlag = TRUE;
                    }
                    if((argv[i][j]) == 'n'){
                        nFlag = TRUE;
                    }
                    if((argv[i][j]) == 'S'){
                        SFlag = TRUE;
                    }
                }
            }
            if(argv[i][1] == 'x'){
                xFlag = TRUE;

                for(j = 2; j < 6; j++){

                    if((argv[i][j]) == 't'){
                        tFlag = TRUE;
                    }
                    if((argv[i][j]) == 's'){
                        sFlag = TRUE;
                    }
                    if((argv[i][j]) == 'n'){
                        nFlag = TRUE;
                    }
                    if((argv[i][j]) == 'S'){
                        SFlag = TRUE;
                    }
                }
            }
            if(argv[i][1] == 'n'){
                nFlag = TRUE;

                for(j = 2; j < 6; j++){

                    if((argv[i][j]) == 't'){
                        tFlag = TRUE;
                    }
                    if((argv[i][j]) == 'x'){
                        xFlag = TRUE;
                    }
                    if((argv[i][j]) == 's'){
                        sFlag = TRUE;
                    }
                    if((argv[i][j]) == 'S'){
                        SFlag = TRUE;
                    }
                }
            }
            if(argv[i][1] == 'S'){
                SFlag = TRUE;

                for(j = 2; j < 6; j++){

                    if((argv[i][j]) == 't'){
                        tFlag = TRUE;
                    }
                    if((argv[i][j]) == 'x'){
                        xFlag = TRUE;
                    }
                    if((argv[i][j]) == 'n'){
                        nFlag = TRUE;
                    }
                    if((argv[i][j]) == 's'){
                        sFlag = TRUE;
                    }
                }
            }
        }
    }
    /*Opens output file for writing if -O flag was inputted*/
    if(oFlag == TRUE){
        fp2 = fopen(outputFile, "w");
        if(fp2 == NULL){
            printf("Error the output file does not exist\n");
            exit(2);
        }
    }

    frequency_table = create_freq_table();

    if(fFlag == TRUE){
        
        fp = fopen(inputFile, "r");
        if(fp == NULL){
            exit(2);
        }
        i = 0;
        while(fgets(inputString, 10, fp) != NULL){
            letterCount += letter_count(inputString);
            charCount += char_count(inputString);
            add_letters(frequency_table, inputString);
        }
    }
    else{
        i = 0;
        while((c = getchar()) != EOF){
            stdinInput[i] = c;
            charCount++;
               
            if(((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122))){
                letterCount++;
            } 
            i++;
        }
        stdinInput[i] = '\0';
        add_letters(frequency_table, stdinInput); 
        printf("\n"); 
    }
    
    if(sFlag == TRUE){
        originalShift = encode_shift(letterCount, frequency_table);
        decodeShift = to_decode(originalShift);
        if(oFlag == TRUE){
            if(fFlag == TRUE){

                rewind(fp);
                printf("Decode Shift: %d\n\n",decodeShift);

                while(fgets(outputString, 10, fp) != NULL){

                    for(i = 0; i < 9; i++){
                        c = outputString[i];
                    
                        c = encode(c, decodeShift);
                    
                        if(c != '\0'){
                            fputc(c, fp2);
                        }
                        else{
                            i = 9; 
                        }
                    }
                }

            }
            else{

                printf("Decode Shift: %d\n\n",decodeShift);

                for(i = 0; stdinInput[i] != '\0'; i++){
                    c = stdinInput[i];
                    c = encode(c, decodeShift);
                    fputc(c, fp2);
                }

            }
     
        }
        else if(nFlag == TRUE){
            ;
        }
        else{
            if(fFlag == TRUE){
                rewind(fp);

                printf("Decode Shift: %d\n\n",decodeShift);
                while(fgets(outputString, 10, fp) != NULL){

                    for(i = 0; i < 9; i++){
                        c = outputString[i];
                    
                        c = encode(c, decodeShift);
            
                        if(c != '\0'){
                            printf("%c",c);
                        }
                        else{
                            i = 9; 
                        }
                    }
                }
                printf("\n\n");
            }
            else{
               printf("Decode Shift: %d\n\n",decodeShift);

                for(i = 0; stdinInput[i] != '\0'; i++){
                    c = stdinInput[i];
                    c = encode(c, decodeShift);
                    printf("%c",c);
                }
                printf("\n\n");
            } 
        } 
    }
    
    if(SFlag == TRUE){

        originalShift = encode_shift(letterCount, frequency_table);
        decodeShift = to_decode(originalShift);

        if(oFlag == TRUE){
            if(fFlag == TRUE){
                rewind(fp);
                printf("Encode Shift: %d\n\n", originalShift);

                while(fgets(outputString, 10, fp) != NULL){

                    for(i = 0; i < 9; i++){
                        c = outputString[i];
                    
                        c = encode(c, decodeShift);
                    
                        if(c != '\0'){
                            fputc(c, fp2);
                        }
                        else{
                            i = 9; 
                        }
                    }
                }
            }
            else{
                printf("Encode Shift: %d\n\n",originalShift);

                for(i = 0; stdinInput[i] != '\0'; i++){
                    c = stdinInput[i];
                    c = encode(c, decodeShift);
                    fputc(c,fp2);
                }
            }
     
        }
        else if(nFlag == TRUE){
            ;
        }
        else{
            if(fFlag == TRUE){
                rewind(fp);
                printf("Encode Shift: %d\n\n",originalShift);
                while(fgets(outputString, 10, fp) != NULL){

                    for(i = 0; i < 9; i++){
                        c = outputString[i];
                    
                        c = encode(c, decodeShift);
            
                        if(c != '\0'){
                            printf("%c",c);
                        }
                        else{
                            i = 9; 
                        }
                    }
                }
                printf("\n\n");
            }
            else{
                printf("Encode Shift: %d\n\n",originalShift);

                for(i = 0; stdinInput[i] != '\0'; i++){
                    c = stdinInput[i];
                    c = encode(c, decodeShift);
                    printf("%c",c);
                }
                printf("\n\n");
            } 
        }
        
    }

    if(xFlag == TRUE){
        printf("shift\t\tchi_square(shift)\n");

        for(shift = 0; shift < 26; shift++){
            chiValue = chi_sq(letterCount, frequency_table, shift);
            printf("%d\t\t%f\n",shift, chiValue);
        }
    }

    if(tFlag == TRUE){
        
        printf("\nNumber of letters in text: %d\n", letterCount);
        printf("Number of characters in text: %d\n", charCount);
        printf("\n");

        printf("Letters: \t\t Letter Counts:\n");

        for(i = 0; i < 26; i++){

            printf("%c \t\t %10d\n", letter, frequency_table[i]);

            letter++;

        }
    }

    if((sFlag == TRUE) && (nFlag == TRUE)){
        printf("\nDecode Shift: %d\n\n",decodeShift);
    }

    if((SFlag == TRUE) && (nFlag == TRUE)){
        printf("\nEncode Shift: %d\n\n",decodeShift);
    }
    free(frequency_table);
    if(fFlag == TRUE){
        fclose(fp);
    }
    if(oFlag == TRUE){
        fclose(fp2);
    }

    return 0;
}