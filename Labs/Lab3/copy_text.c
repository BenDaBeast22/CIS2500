#include <stdio.h>
#include <stdlib.h>

/**
 * Copies text from input file to output file
 * Paramaters: input file and output file
 * If input file is not provided copies text from stdin and if output file is not provided copies text to stdout
 */

int main(int argc, char *argv[]){

    FILE *fp1;
    FILE *fp2;
    int c;
    char *file;
    char *fileNew;
    
    if(argc == 3){

        file = argv[1];
        fileNew = argv[2];
        /*open input file for reading*/
        fp1 = fopen(file,"r");
        if(fp1 == NULL){
            exit(1);
        }
        /*open output file for writing*/
        fp2 = fopen(fileNew, "w");
        if(fp2 == NULL){
            exit(1);
        }
        /*Write to output file*/
        while((c = fgetc(fp1)) != EOF){
            fputc(c,fp2);
        }

        fclose(fp1);
        fclose(fp2);

    }

    else if(argc == 2){

        file = argv[1];

        fp1 = fopen(file,"r");
        if(fp1 == NULL){
            exit(1);
        }
        /*Write to stdout*/
        while((c = fgetc(fp1)) != EOF){
            putchar(c);
        }

        fclose(fp1);

    }

    else if(argc == 1){
        /*Write to stdout*/
        while((c = getchar()) != EOF){
            putchar(c);
        }
    }
    else{
        exit(2);
    }

    return 0;
}