#include "list_adt.h"

int main(int argc, char *argv[]){
    FILE *fp;
    char *inputFile;
    int order;
    char line[80];
    char command[20];
    long long num;
    long long denom;
    double key;
    double decimal;
    int value;
    int numberSpaces = 0;
    int i;
    Sorted_List *list = create_list();
    Fraction fraction;
    char String[25];


    if(argc == 2){
        inputFile = argv[1];
        fp = fopen(inputFile, "r");

        if(fp == NULL){
            printf("Error - File does not exist\n");
            exit(1);
        }

        while(!feof(fp)){

            fgets(line, 50, fp);

            if(line[0] != '\n'){

                sscanf(line,"%s %lf %d", command, &key, &value);
                sscanf(line,"%*s %s", String);
                sscanf(String,"%lli" "%*c" "%lli", &num, &denom);

                if(strcmp(command, "size") == 0){
                    numberSpaces = 11 - strlen(command);
                    printf("size:");
                    for(i = 0; i < numberSpaces; i++){
                        printf(" ");
                    }
                    printf("List size = %d\n",size(list));
                }

                else if(strcmp(command, "a") == 0){
                    set_fraction(&fraction, num, denom);
                    decimal = (double)num/(double)denom;
                    append(list, fraction, decimal);
                    numberSpaces = 11 - strlen(command);
                    printf("a:");
                    for(i = 0; i < numberSpaces; i++){
                        printf(" ");
                    }
                    printf("%lf  %lli/%lli\n", decimal, fraction.num, fraction.denom);
                }

                else if(strcmp(command, "p") == 0){
                    set_fraction(&fraction, num, denom);
                    decimal = (double)num/(double)denom;
                    push(list, fraction, decimal);
                    numberSpaces = 11 - strlen(command);
                    printf("p:");
                    for(i = 0; i < numberSpaces; i++){
                        printf(" ");
                    }
                    printf("%lf  %lli/%lli\n", decimal, fraction.num, fraction.denom);
                }

                else if(strcmp(command, "print_all") == 0){
                    order = INSERTED_ORDER;
                    if(strcmp(String, "SIMPLE") == 0){
                        numberSpaces = 11 - strlen(command);
                        printf("print_all:");
                        for(i = 0; i < numberSpaces; i++){
                            printf(" ");
                        }
                        printf("Simple Fractions, Insertion Order\n");
                        print_list_fract_all(list, SIMPLE,order);

                    }
                    else if(strcmp(String, "MIXED") == 0){
                        numberSpaces = 11 - strlen(command);
                        printf("print_all:");
                        for(i = 0; i < numberSpaces; i++){
                            printf(" ");
                        }
                        printf("Mixed Fractions, Insertion Order\n");
                        print_list_fract_all(list, MIXED,order);
                    }
                }

                else if(strcmp(command, "print_sort") == 0){
                    order = SORTED_ORDER;
                    if(strcmp(String, "SIMPLE") == 0){
                        numberSpaces = 11 - strlen(command);
                        printf("print_all:");
                        for(i = 0; i < numberSpaces; i++){
                            printf(" ");
                        }
                        printf("Simple Fractions, Key Sort Order\n");
                        print_list_fract_all(list, SIMPLE,order);

                    }
                    else if(strcmp(String, "MIXED") == 0){
                        numberSpaces = 11 - strlen(command);
                        printf("print_all:");
                        for(i = 0; i < numberSpaces; i++){
                            printf(" ");
                        }
                        printf("Mixed Fractions, Key Sort Order\n");
                        print_list_fract_all(list, MIXED, SORTED_ORDER);
                    }
                }
                else if(strcmp(command, "empty") == 0){
                    numberSpaces = 11 - strlen(command);
                    printf("empty:");
                    for(i = 0; i < numberSpaces; i++){
                        printf(" ");
                    }
                    printf("size = 0\n");
                    empty_list(list);
                }
            }
        }
        destroy_list(list);
        fclose(fp);
    }
    else{
        printf("Error - Expected 1 or 2 argument\n");
        exit(2);
    }

    return 0;
}
