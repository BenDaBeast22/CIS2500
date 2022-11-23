#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

/**
 * Encodes text in a ceasar cipher 
 * Parameters: Takes shift number, -O flag(output file) and -F flag(input file)
 * The shiftNumber determines the shift of the cipher and if not provided the shift number is 13, the -F flag takes input from an input file and if not provided input comes from stdin and -O flag outputs encoded text to the output file specified and if no-O flag is provided then output goes to stdin
 */

int main(int argc, char *argv[]){

    FILE *fp;
    FILE *fp2;
    char *inputFile;
    char *outputFile;
    
    int c = 0;
    int oldc = 0;
    int shiftNumber = 13;
    int oFlag = FALSE;
    int fFlag = FALSE;
    int i;

    if(argc < 7){
        
        if(argc > 1){
            shiftNumber = atoi(argv[1]);
        }

        if(shiftNumber == 0){
            shiftNumber = 13;
        }
        
        if((shiftNumber > -26) && (shiftNumber < 26)){
            ;
        }
        
        else{
            fprintf(stderr, "%s\n", "Error - Shift number must be within -25 to 25 inclusive");
            exit(1);
        }
        /*Determines if -F flag was inputted*/
        for(i = 1; i < argc; i++){
            if((argv[i][0] == '-') && (argv[i][1] == 'F')){
                fFlag = TRUE;
                if(strcmp(argv[i],"-F") == 0){
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
        }
        /*Opens input file if -F flag was inputted*/
        if(fFlag == TRUE){
            fp = fopen(inputFile, "r");
                if(fp == NULL){
                    printf("Error the input file does not exist\n");
                    exit(2);
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
        /*Encodes input file*/
        if(fFlag == TRUE){
            if(shiftNumber > 0){

                while((c = fgetc(fp)) != EOF){

                    if(((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122))){
                        oldc = c;
                        c += shiftNumber;

                        if((c > 90) && (oldc >= 65) && (oldc <= 90)){
                            c = 64 + (c-90);
                        }

                        else if((c > 122) && (oldc >= 97) && (oldc <= 122)){
                            c = 96 + (c-122);
                        }
                        if(oFlag == TRUE){
                            fputc(c, fp2);
                        }
                        else{
                            fputc(c, stdout);
                        }
                    }
                    else{
                        if(oFlag == TRUE){
                            fputc(c, fp2);
                        }
                        else{
                            fputc(c, stdout);
                        }
                    }
                } 

            }
            else if(shiftNumber < 0){

                while((c = fgetc(fp)) != EOF){

                    if(((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122))){

                        oldc = c;
                        c += shiftNumber;

                        if((oldc >= 65) && (oldc <=90) && (c < 65)){
                            c = oldc + (26 + shiftNumber);
                        }

                        else if((oldc >= 97) && (oldc <= 122) && (c < 97)){
                            c = oldc + (26 + shiftNumber);
                        }
                        if(oFlag == TRUE){
                            fputc(c, fp2);
                        }
                        else{
                            fputc(c, stdout);
                        }
                    }
                    else{
                        if(oFlag == TRUE){
                            fputc(c, fp2);
                        }
                        else{
                            fputc(c, stdout);
                        }
                    }
                } 
            }

        }
        /*encodes file form stdin*/
        else{
            if(shiftNumber > 0){

                while((c = getchar()) != EOF){

                    if(((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122))){
                        oldc = c;
                        c += shiftNumber;

                        if((c > 90) && (oldc >= 65) && (oldc <= 90)){
                            c = 64 + (c-90);
                        }

                        else if((c > 122) && (oldc >= 97) && (oldc <= 122)){
                            c = 96 + (c-122);
                        }
                        if(oFlag == TRUE){
                            fputc(c, fp2);

                        }
                        else{
                            fputc(c, stdout);
                        }
                    }
                    else{
                        if(oFlag == TRUE){
                            fputc(c, fp2);
                        }
                        else{
                            fputc(c, stdout);
                        }
                    }
                } 

            }
            else if(shiftNumber < 0){

                while((c = getchar()) != EOF){

                    if(((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122))){

                        oldc = c;
                        c += shiftNumber;

                        if((oldc >= 65) && (oldc <= 90) && (c < 65)){
                            c = oldc + (26 + shiftNumber);
                        }

                        else if((oldc >= 97) && (oldc <= 122) && (c < 97)){
                            c = oldc + (26 + shiftNumber);
                        }
                        if(oFlag == TRUE){
                            fputc(c, fp2);
                        }
                        else{
                            fputc(c, stdout);
                        }
                    }
                    else{
                        if(oFlag == TRUE){
                            fputc(c, fp2);
                        }
                        else{
                            fputc(c, stdout);
                        }
                    }
                } 
            }
        }
    
           
    }
    else{
        printf("Error - Expected: ./encode shift (-F) inputfileName (-O) outputfile name\n");
    }
    if(fFlag == TRUE){
        fclose(fp);
    }
    if(oFlag == TRUE){
        fclose(fp2);
    }
    return 0;
}
