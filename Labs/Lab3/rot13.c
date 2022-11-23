#include <stdio.h>
#include <stdlib.h>

/**
 * Encodes text from an input file by a ceasar cipher shift of 13
 * Parameters: input file and ouput file
 * If input file is not inputted input will come from stdin and if output file is not inputted than output will be outputted to stdout
 */

int main(int argc, char *argv[]){

    FILE *fp1;
    FILE *fp2;

    char *file;
    char *fileNew;
    int c = 0;
    int oldc = 0;

    if(argc == 3){

        file = argv[1];
        fileNew = argv[2];

        fp1 = fopen(file, "r");
        if(fp1 == NULL){
            exit(1);
        }

        fp2 = fopen(fileNew, "w");
        if(fp2 == NULL){
            exit(1);
        }
        /*Encodes text by shift of 13*/
        while((c = fgetc(fp1)) != EOF){
            
            if(((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122))){
                oldc = c;
                c += 13;

                if((c > 90) && (oldc >= 65) && (oldc <= 90)){
                    c = 64 + (c-90);
                }

                else if((c > 122) && (oldc >= 97) && (oldc <= 122)){
                    c = 96 + (c-122);
                }

                fputc(c,fp2);
            }
            else{
                fputc(c, fp2);
            }
        }

        fclose(fp1);
        fclose(fp2);
    }

    else{
        printf("Error - 2 arguments required\n");
        exit(2);
    }

    return 0;
}