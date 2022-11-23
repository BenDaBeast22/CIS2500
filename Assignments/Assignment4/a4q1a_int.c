#include "list_adt.h"

int main(int argc, char *argv[]){

    FILE *fp;
    char *inputFile;
    char line[80];
    char command[20];
    double key;
    int c;
    int value;
    int numberSpaces = 0;
    int i;

    Sorted_List *list = create_list();

    if(argc == 1){

        while(!feof(stdin)){
            for(i = 0; i < 150; i++){
                line[i] = '\0';
            }

            i = 0;
            while((c = getchar()) != '\n' && (c != EOF)){
                line[i] = c;
                i++;
            }
            if(line[0] != '\n' && line[0] != EOF){

                sscanf(line,"%s %lf %d", command, &key, &value);

                if(strcmp(command, "p") == 0){
                    numberSpaces = 11 - strlen(command);
                    push(list, value, key);
                    printf("p:");
                    for(i = 0; i < numberSpaces; i++){
                        printf(" ");
                    }
                    printf("%f  %d\n",key, value);
                }

                else if(strcmp(command, "a") == 0){
                    numberSpaces = 11 - strlen(command);
                    append(list, value, key);
                    printf("a:");
                    for(i = 0; i < numberSpaces; i++){
                        printf(" ");
                    }
                    printf("%f  %d\n",key, value);
                }

                else if(strcmp(command, "rem_first") == 0){
                    numberSpaces = 11 - strlen(command);
                    printf("rem_first:");
                    for(i = 0; i < numberSpaces; i++){
                        printf(" ");
                    }
                    remove_first(list, &value, &key);
                    printf("%f  %d\n",key, value);
                }

                else if(strcmp(command, "rem_last") == 0){
                    numberSpaces = 11 - strlen(command);
                    printf("rem_last:");
                    for(i = 0; i < numberSpaces; i++){
                        printf(" ");
                    }
                    remove_last(list, &value, &key);
                    printf("%f  %d\n",key, value);
                }

                else if(strcmp(command, "rem_small") == 0){
                numberSpaces = 11 - strlen(command);
                    printf("rem_small:");
                    for(i = 0; i < numberSpaces; i++){
                        printf(" ");
                    }
                    remove_smallest_key(list, &value, &key);
                    printf("%f  %d\n",key, value);
                }

                else if(strcmp(command, "rem_large") == 0){
                    numberSpaces = 11 - strlen(command);
                    printf("rem_large:");
                    for(i = 0; i < numberSpaces; i++){
                        printf(" ");
                    }
                    remove_largest_key(list, &value, &key);
                    printf("%f  %d\n",key, value);
                }

                else if(strcmp(command, "size") == 0){
                    numberSpaces = 11 - strlen(command);
                    printf("size:");
                    for(i = 0; i < numberSpaces; i++){
                        printf(" ");
                    }
                    printf("List size = %d\n",size(list));
                }

                else if(strcmp(command, "print_all") == 0){
                    numberSpaces = 11 - strlen(command);
                    printf("print_all:");
                    for(i = 0; i < numberSpaces; i++){
                        printf(" ");
                    }
                    printf("Insertion Order\n");
                    print_list_all(list);
                }

                else if(strcmp(command, "print_sort") == 0){
                    numberSpaces = 11 - strlen(command);
                    printf("print_sort:");
                    for(i = 0; i < numberSpaces; i++){
                        printf(" ");
                    }
                    printf("Key Sort Order\n");
                    print_list_sort(list);
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

                /*printf("Tail: %f\n", list -> tail_sort -> key);*/
            }
        }
        destroy_list(list);
    }

    else if(argc == 2){
        inputFile = argv[1];
        fp = fopen(inputFile, "r");

        if(fp == NULL){
            printf("Error File does not exist\n");
            exit(1);
        }

        while(!feof(fp)){

            fgets(line, 50, fp);

            if(line[0] != '\n'){

                sscanf(line,"%s %lf %d", command, &key, &value);

                if(strcmp(command, "p") == 0){
                    numberSpaces = 11 - strlen(command);
                    push(list, value, key);
                    printf("p:");
                    for(i = 0; i < numberSpaces; i++){
                        printf(" ");
                    }
                    printf("%.6g  %d\n",key, value);
                }

                else if(strcmp(command, "a") == 0){
                    numberSpaces = 11 - strlen(command);
                    append(list, value, key);
                    printf("a:");
                    for(i = 0; i < numberSpaces; i++){
                        printf(" ");
                    }
                    printf("%.6g  %d\n",key, value);
                }

                else if(strcmp(command, "rem_first") == 0){
                    numberSpaces = 11 - strlen(command);
                    printf("rem_first:");
                    for(i = 0; i < numberSpaces; i++){
                        printf(" ");
                    }
                    remove_first(list, &value, &key);
                    printf("%.6g  %d\n",key, value);
                }

                else if(strcmp(command, "rem_last") == 0){
                    numberSpaces = 11 - strlen(command);
                    printf("rem_last:");
                    for(i = 0; i < numberSpaces; i++){
                        printf(" ");
                    }
                    remove_last(list, &value, &key);
                    printf("%.6g  %d\n",key, value);
                }

                else if(strcmp(command, "rem_small") == 0){
                numberSpaces = 11 - strlen(command);
                    printf("rem_small:");
                    for(i = 0; i < numberSpaces; i++){
                        printf(" ");
                    }
                    remove_smallest_key(list, &value, &key);
                    printf("%.6g  %d\n",key, value);
                }

                else if(strcmp(command, "rem_large") == 0){
                    numberSpaces = 11 - strlen(command);
                    printf("rem_large:");
                    for(i = 0; i < numberSpaces; i++){
                        printf(" ");
                    }
                    remove_largest_key(list, &value, &key);
                    printf("%.6g  %d\n",key, value);
                }

                else if(strcmp(command, "size") == 0){
                    numberSpaces = 11 - strlen(command);
                    printf("size:");
                    for(i = 0; i < numberSpaces; i++){
                        printf(" ");
                    }
                    printf("List size = %d\n",size(list));
                }

                else if(strcmp(command, "print_all") == 0){
                    numberSpaces = 11 - strlen(command);
                    printf("print_all:");
                    for(i = 0; i < numberSpaces; i++){
                        printf(" ");
                    }
                    printf("Insertion Order\n");
                    print_list_all(list);
                }

                else if(strcmp(command, "print_sort") == 0){
                    numberSpaces = 11 - strlen(command);
                    printf("print_sort:");
                    for(i = 0; i < numberSpaces; i++){
                        printf(" ");
                    }
                    printf("Key Sort Order\n");
                    print_list_sort(list);
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

                /*printf("Tail: %f\n", list -> tail_sort -> key);*/
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
