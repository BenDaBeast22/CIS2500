#include "list_adt.h"
#include "map_reduce_functions.h"
#include "map_reduce_adt.h"

int main(int argc, char *argv[]){
    FILE *fp;
    Sorted_List *listArray[10];
    char *inputFile;
    char line[80];
    char command[20];
    double key;
    int value;
    int result;
    int numberSpaces = 0;
    int i,n,n2;
    Sorted_List *newList = create_list();
    Sorted_List *list = create_list();
    value_type *array;
    char order[15];

    for(i = 0; i < 10; i++){
        listArray[i] = create_list();
    }

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
                sscanf(line,"%*s %s",order);

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

                else if((strcmp(command, "p|0") == 0) || (strcmp(command, "p|1") == 0) || (strcmp(command, "p|2") == 0) || (strcmp(command, "p|3") == 0) || (strcmp(command, "p|4") == 0) ||
                (strcmp(command, "p|5") == 0) || (strcmp(command, "p|6") == 0) || (strcmp(command, "p|7") == 0) || (strcmp(command, "p|8") == 0) || (strcmp(command, "p|9") == 0)){
                    n = command[2] - 48;
                    numberSpaces = 11 - 3;
                    push(listArray[n],value,key);
                    printf("p:");
                    for(i = 0; i < numberSpaces; i++){
                        printf(" ");
                    }
                    printf("list = %d, %.6g  %d\n",n, key, value);
                }

                else if((strcmp(command, "a|0") == 0) || (strcmp(command, "a|1") == 0) || (strcmp(command, "a|2") == 0) || (strcmp(command, "a|3") == 0) || (strcmp(command, "a|4") == 0) ||
                (strcmp(command, "a|5") == 0) || (strcmp(command, "a|6") == 0) || (strcmp(command, "a|7") == 0) || (strcmp(command, "a|8") == 0) || (strcmp(command, "a|9") == 0)){
                    n = command[2] - 48;
                    numberSpaces = 11 - 3;
                    append(listArray[n],value,key);
                    printf("a:");
                    for(i = 0; i < numberSpaces; i++){
                        printf(" ");
                    }
                    printf("list = %d, %.6g  %d\n",n, key, value);
                }

                else if((strcmp(command, "sum|0") == 0) || (strcmp(command, "sum|1") == 0) || (strcmp(command, "sum|2") == 0) || (strcmp(command, "sum|3") == 0) || (strcmp(command, "sum|4") == 0) ||
                (strcmp(command, "sum|5") == 0) || (strcmp(command, "sum|6") == 0) || (strcmp(command, "sum|7") == 0) || (strcmp(command, "sum|8") == 0) || (strcmp(command, "sum|9") == 0)){
                    n = command[4] - 48;
                    numberSpaces = 11 - 3;
                    result = sum(listArray[n]);
                    printf("sum:");
                    for(i = 0; i < numberSpaces; i++){
                        printf(" ");
                    }
                    printf("list = %d, result = %d\n",n, result);
                }

                else if((strcmp(command, "square|0") == 0) || (strcmp(command, "square|1") == 0) || (strcmp(command, "square|2") == 0) || (strcmp(command, "square|3") == 0) || (strcmp(command, "square|4") == 0) ||
                (strcmp(command, "square|5") == 0) || (strcmp(command, "square|6") == 0) || (strcmp(command, "square|7") == 0) || (strcmp(command, "square|8") == 0) || (strcmp(command, "square|9") == 0)){
                    n = command[7] - 48;
                    numberSpaces = 11 - 6;
                    newList = square(listArray[n]);
                    printf("square:");
                    for(i = 0; i < numberSpaces; i++){
                        printf(" ");
                    }
                    printf("list = %d\n",n);
                    print_list_all(newList);
                }

                else if(command[0] == 'd' && command[1] == 'i' && command[2] == 'f' && command[3] == 'f' && command[4] == '|'){
                    n = command[5] - 48;
                    n2 = command[7] - 48;

                    numberSpaces = 11 - 4;
                    if(strcmp(order,"INSERTED_ORDER") == 0){
                        array = diff(listArray[n], listArray[n2], INSERTED_ORDER);
                        printf("diff:");
                        for(i = 0; i < numberSpaces; i++){
                            printf(" ");
                        }
                        printf("list1 = %d, list2 = %d, Insertion Order\n",n,n2);
                        print_array(array, size(listArray[n]));
                    }

                    if(strcmp(order,"SORTED_ORDER") == 0){
                        array = diff(listArray[n], listArray[n2], SORTED_ORDER);
                        printf("diff:");
                        for(i = 0; i < numberSpaces; i++){
                            printf(" ");
                        }
                        printf("list1 = %d, list2 = %d, Key Sort Order\n",n,n2);
                        print_array(array, size(listArray[n]));
                    }
                }

                else if(command[0] == 's' && command[1] == 'u' && command[2] == 'm' && command[3] == '_' && command[4] == 's' && command[5] == 'q' && command[6] == '_' && command[7] == 'd'){
                    n = command[9] - 48;
                    n2 = command[11] - 48;

                    numberSpaces = 11 - 8;
                    if(strcmp(order,"INSERTED_ORDER") == 0){
                        result = sum_of_sq_diff(listArray[n], listArray[n2], INSERTED_ORDER);
                        printf("sum_sq_d:");
                        for(i = 0; i < numberSpaces; i++){
                            printf(" ");
                        }
                        printf("list1 = %d, list2 = %d, Insertion Order, result = %d\n",n,n2, result);
                    }

                    if(strcmp(order,"SORTED_ORDER") == 0){
                        result = sum_of_sq_diff(listArray[n], listArray[n2], SORTED_ORDER);
                        printf("sum_sq_d:");
                        for(i = 0; i < numberSpaces; i++){
                            printf(" ");
                        }
                        printf("list1 = %d, list2 = %d, Sorted_Order, result = %d\n",n,n2,result);
                    }
                }

                else if((strcmp(command, "print_all|0") == 0) || (strcmp(command, "print_all|1") == 0) || (strcmp(command, "print_all|2") == 0) || (strcmp(command, "print_all|3") == 0) || (strcmp(command, "print_all|4") == 0) ||
                (strcmp(command, "print_all|5") == 0) || (strcmp(command, "print_all|6") == 0) || (strcmp(command, "print_all|7") == 0) || (strcmp(command, "print_all|8") == 0) || (strcmp(command, "print_all|9") == 0)){
                    n = command[10] - 48;
                    numberSpaces = 11 - 9;
                    printf("print_all:");
                    for(i = 0; i < numberSpaces; i++){
                        printf(" ");
                    }
                    printf("list = %d, Insertion Order\n", n);
                    print_list_all(listArray[n]);
                }

                else if((strcmp(command, "print_sort|0") == 0) || (strcmp(command, "print_sort|1") == 0) || (strcmp(command, "print_sort|2") == 0) || (strcmp(command, "print_sort|3") == 0) || (strcmp(command, "print_sort|4") == 0) ||
                (strcmp(command, "print_sort|5") == 0) || (strcmp(command, "print_sort|6") == 0) || (strcmp(command, "print_sort|7") == 0) || (strcmp(command, "print_sort|8") == 0) || (strcmp(command, "print_sort|9") == 0)){
                    n = command[11] - 48;
                    numberSpaces = 11 - 9;
                    printf("print_sort:");
                    for(i = 0; i < numberSpaces; i++){
                        printf(" ");
                    }
                    printf("list = %d, Key Sort Order\n", n);
                    print_list_sort(listArray[n]);
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
            }
        }
        destroy_list(list);
        destroy_list(newList);
        for(i = 0; i < 10; i++){
            destroy_list(listArray[i]);
        }
        fclose(fp);
    }
    else{
        for(i = 0; i < 10; i++){
            destroy_list(listArray[i]);
        }
        destroy_list(list);
        destroy_list(newList);
        printf("Error - Expected 1 or 2 argument\n");
        exit(2);
    }

    return 0;
}
