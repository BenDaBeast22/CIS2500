#include "copyrecords.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Can decode records and copy them to another file or print them to stdin
 */
int main(int argc, char *argv[]){

    FILE *fp, *fp2, *fp3;
    int i;
    int j;
    int k;
    int c;
    int fFlag = FALSE;
    int oFlag = FALSE;
    int dFlag = FALSE;
    int rFlag = FALSE;
    int numStruct;
    int letterCount = 0;
    int encodeShift;
    int decodeShift;
    int *frequency_table;
    char inputStdin[MAXSIZE];
    char *inputFile;
    char *outputFile;
    char *textFile;

    typedef struct data record;

    record items[100];
    
    for(i =  1; i < argc; i++){

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

        /*Determines if -D flag was inputted*/
        if((argv[i][0] == '-') && (argv[i][1] == 'D')){
            dFlag = TRUE;
            if(strcmp(argv[i],"-D") == 0){
                if((i+1) < argc){
                    textFile = argv[i+1];
                }
            }
            else{
                textFile = argv[i];

                textFile += 2;
            }
        }

        /*Determines if -r flag was inputted*/
        if((argv[i][0] == '-') && (argv[i][1] == 'r')){
            rFlag = TRUE;
        }
    }

    if(fFlag == TRUE){
        fp = fopen(inputFile, "rb");
        if(fp == NULL){
            printf("File does not exist\n");
            exit(1);
        }
    }
    else{
        i = 0;
        while((c = getchar()) != EOF){
            inputStdin[i] = c;
            i++; 
        }
        inputStdin[i] = '\0';
        fp = fopen(inputStdin, "r");
        if(fp == NULL){
            printf("File does not exist\n");
            exit(1);
        }
        printf("\n");
    }

    fseek(fp, 0, SEEK_END);

    numStruct = (ftell(fp))/408;

    rewind(fp);

    if((fFlag == FALSE) && (rFlag == TRUE)){
        j = 1;
        for(i = 0; i < (numStruct); i++){

            fseek(fp, sizeof(record) * (-j), SEEK_END);
            fread(&items[i], sizeof(record), 1, fp);
            j++;
        }
    }
    else{

        for(i = 0; i < numStruct; i++){
            
            fread(&items[i], sizeof(record), 1, fp);
            
        }

    }

    if(dFlag == TRUE){

        fp2 = fopen(textFile, "r");
        if(fp2 == NULL){
            printf("File does not exist\n");
            exit(1);
        }

        frequency_table = create_freq_table();
        
        while((fgets(textFile, 10, fp2)) != NULL){
            letterCount += letter_count(textFile);
            add_letters(frequency_table, textFile);
        }

        encodeShift = encode_shift(letterCount, frequency_table);
        decodeShift = to_decode(encodeShift);

        for(i = 0; i < numStruct; i++){
            for(j = 0; items[i].string1[j] != '\0'; j++){ 
                c = items[i].string1[j]; 
                items[i].string1[j] = encode(c, decodeShift);
            }
        }
        
        for(i = 0; i < numStruct; i++){
            for(j = 0; items[i].string2[j] != '\0'; j++){ 
                c = items[i].string2[j]; 
                items[i].string2[j] = encode(c, decodeShift);
            }
        }
    }

    if(oFlag == TRUE){

        fp3 = fopen(outputFile, "wb");
        if(fp3 == NULL){
            printf("File does not exist\n");
            exit(2);
        }
        for(i = 0; i < numStruct; i++){

            fwrite(&items[i], sizeof(record), 1, fp3);

        }
    }

    else{

        printf("\n");

        for(i = 0; i < numStruct; i++){
            printf("%s\n", items[i].string1);

            for(j = 0; j < 23; j++){
                printf("%f, ", items[i].decimal[j]);
            }

            printf("%f\n", items[i].decimal[23]);

            printf("%s\n", items[i].string2);

            for(k = 0; k < 11; k++){
                printf("%d, ", items[i].integers[k]);
            }
            printf("%d\n\n", items[i].integers[11]);
        }

    }

    free(frequency_table);
    if(fFlag == TRUE){
        fclose(fp);
    }
    if(dFlag == TRUE){
        fclose(fp2);
    }
    if(oFlag == TRUE){
        fclose(fp3);
    }

    return 0;
}