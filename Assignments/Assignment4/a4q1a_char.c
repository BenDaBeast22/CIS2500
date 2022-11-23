#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_adt.h"

int main(int argc, char *argv[]){

    FILE *fp;
    char *inputFile;
    char value[80];
    char line[150];
    int key;
    int initial_space = 0;
    int numberSpaces = 0;
    int i, j, c;
    
    if(argc == 1){
        Sorted_List *list = create_list();
        
        while(!feof(stdin)){
            for(i = 0; i < 150; i++){
                line[i] = '\0';
            }
           
            i = 0;
            while((c = getchar()) != '\n' && (c != EOF)){
                line[i] = c;
                i++;    
            }
            if(line[0] == 'p' && (line[1] == ' ' || line[1] == '\0')){

                initial_space = 0;

                for(i = 2; line[i] == ' '; i++){
                    initial_space++;
                }
                j = 0;

                for(i = 2 + initial_space; (line[i] != '\0') && (i < 82); i++){
                    value[j] = line[i];
                    j++;
                }
                value[j] = '\0';
                key = strlen(value);
                numberSpaces = 11 - 1;
                push(list, value, key);
                printf("p:");
                for(i = 0; i < numberSpaces; i++){
                    printf(" ");
                }
                printf("%d  %s\n",key, value);
            }

            else if(line[0] == 'a' && (line[1] == ' '|| line[1] == '\0')){
                initial_space = 0;

                for(i = 2; line[i] == ' '; i++){
                        initial_space++;
                }

                j = 0;

                for(i = 2 + initial_space; (line[i] != '\0') && (i < 82); i++){
                    value[j] = line[i];
                    j++;
                }

                value[j] = '\0';
                key = strlen(value);
                numberSpaces = 11 - 1;
                append(list, value, key);
                printf("a:");
                for(i = 0; i < numberSpaces; i++){
                    printf(" ");
                }
                printf("%d  %s\n",key, value);
            }
            /*rem_first*/
            else if(line[0] == 'r' && line[1] == 'e' && line[2] == 'm' && line[3] == '_' && line[4] == 'f' && line[5] == 'i' && line[6] == 'r' && line[7] == 's' && line[8] == 't' && line[9] == '\0'){
                numberSpaces = 11 - 9;
                printf("rem_first:");
                for(i = 0; i < numberSpaces; i++){
                    printf(" ");
                }
                remove_first(list, &value, &key);
                printf("%d  %s\n",key, value);
            }
            /*rem_last*/
            else if(line[0] == 'r' && line[1] == 'e' && line[2] == 'm' && line[3] == '_' && line[4] == 'l' && line[5] == 'a' && line[6] == 's' && line[7] == 't' && line[8] == '\0'){
                numberSpaces = 11 - 8;
                printf("rem_last:");
                for(i = 0; i < numberSpaces; i++){
                    printf(" ");
                }
                remove_last(list, &value, &key);
                printf("%d  %s\n",key, value);
            }
            /*rem_small*/
            else if(line[0] == 'r' && line[1] == 'e' && line[2] == 'm' && line[3] == '_' && line[4] == 's' && line[5] == 'm' && line[6] == 'a' && line[7] == 'l' && line[8] == 'l' && line[9] == '\0'){
            numberSpaces = 11 - 9;
                printf("rem_small:");
                for(i = 0; i < numberSpaces; i++){
                    printf(" ");
                }
                remove_smallest_key(list, &value, &key);
                printf("%d  %s\n",key, value);
            }
            /*rem_large*/
            else if(line[0] == 'r' && line[1] == 'e' && line[2] == 'm' && line[3] == '_' && line[4] == 'l' && line[5] == 'a' && line[6] == 'r' && line[7] == 'g' && line[8] == 'e' && line[9] == '\0'){
                numberSpaces = 11 - 9;
                printf("rem_large:");
                for(i = 0; i < numberSpaces; i++){
                    printf(" ");
                }
                remove_largest_key(list, &value, &key);
                printf("%d  %s\n",key, value);
            }
            /*size*/
            else if(line[0] == 's' && line[1] == 'i' && line[2] == 'z' && line[3] == 'e' && line[4] == '\0'){
                numberSpaces = 11 - 4;
                printf("size:");
                for(i = 0; i < numberSpaces; i++){
                    printf(" ");
                }
                printf("List size = %d\n",size(list));
            }
            /*print_all*/
            else if(line[0] == 'p' && line[1] == 'r' && line[2] == 'i' && line[3] == 'n' && line[4] == 't' && line[5] == '_' && line[6] == 'a'&& line[7] == 'l' && line[8] == 'l' && line[9] == '\0'){
                numberSpaces = 11 - 9;
                printf("print_all:");
                for(i = 0; i < numberSpaces; i++){
                    printf(" ");
                }
                printf("Insertion Order\n");
                print_list_all(list);
            }
            /*print_sort*/
            else if(line[0] == 'p' && line[1] == 'r' && line[2] == 'i' && line[3] == 'n' && line[4] == 't' && line[5] == '_' && line[6] == 's'&& line[7] == 'o' && line[8] == 'r' && line[9] == 't'&&line[10] == '\0'){
                numberSpaces = 11 - 10;
                printf("print_sort:");
                for(i = 0; i < numberSpaces; i++){
                    printf(" ");
                }
                printf("Key Sort Order\n");
                print_list_sort(list);
            }
            else if(line[0] == 'e' && line[1] == 'm' && line[2] == 'p' && line[3] == 't' && line[4] == 'y' && line[5] == '\0'){
                numberSpaces = 11 - 5;
                printf("empty:");
                for(i = 0; i < numberSpaces; i++){
                    printf(" ");
                }
                printf("size = 0\n");
                empty_list(list);
            }      
        }
        destroy_list(list); 
    }

    else if(argc == 2){
        Sorted_List *list = create_list();

        inputFile = argv[1];

        fp = fopen(inputFile, "r");
        
        if(fp == NULL){
            exit(1);
        } 

        while(!feof(fp)){

            fgets(line,100,fp);
            chop(line);

            if(line[0] == 'p' && (line[1] == ' ' || line[1] == '\0')){

                initial_space = 0;

                for(i = 2; line[i] == ' '; i++){
                    initial_space++;
                }
                j = 0;

                for(i = 2 + initial_space; (line[i] != '\0') && (i < 82); i++){
                    value[j] = line[i];
                    j++;
                }
                value[j] = '\0';
                key = strlen(value);
                numberSpaces = 11 - 1;
                push(list, value, key);
                printf("p:");
                for(i = 0; i < numberSpaces; i++){
                    printf(" ");
                }
                printf("%d  %s\n",key, value);
            }

            else if(line[0] == 'a' && (line[1] == ' ' || line[1] == '\0')){
                initial_space = 0;

                for(i = 2; line[i] == ' '; i++){
                        initial_space++;
                }

                j = 0;

                for(i = 2 + initial_space; (line[i] != '\0') && (i < 82); i++){
                    value[j] = line[i];
                    j++;
                }

                value[j] = '\0';
                key = strlen(value);
                numberSpaces = 11 - 1;
                append(list, value, key);
                printf("a:");
                for(i = 0; i < numberSpaces; i++){
                    printf(" ");
                }
                printf("%d  %s\n",key, value);
            }
            /*rem_first*/
            else if(line[0] == 'r' && line[1] == 'e' && line[2] == 'm' && line[3] == '_' && line[4] == 'f' && line[5] == 'i' && line[6] == 'r' && line[7] == 's' && line[8] == 't' && line[9] == '\0'){
                numberSpaces = 11 - 9;
                printf("rem_first:");
                for(i = 0; i < numberSpaces; i++){
                    printf(" ");
                }
                remove_first(list, &value, &key);
                printf("%d  %s\n",key, value);
            }
            /*rem_last*/
            else if(line[0] == 'r' && line[1] == 'e' && line[2] == 'm' && line[3] == '_' && line[4] == 'l' && line[5] == 'a' && line[6] == 's' && line[7] == 't' && line[8] == '\0'){
                numberSpaces = 11 - 8;
                printf("rem_last:");
                for(i = 0; i < numberSpaces; i++){
                    printf(" ");
                }
                remove_last(list, &value, &key);
                printf("%d  %s\n",key, value);
            }
            /*rem_small*/
            else if(line[0] == 'r' && line[1] == 'e' && line[2] == 'm' && line[3] == '_' && line[4] == 's' && line[5] == 'm' && line[6] == 'a' && line[7] == 'l' && line[8] == 'l' && line[9] == '\0'){
            numberSpaces = 11 - 9;
                printf("rem_small:");
                for(i = 0; i < numberSpaces; i++){
                    printf(" ");
                }
                remove_smallest_key(list, &value, &key);
                printf("%d  %s\n",key, value);
            }
            /*rem_large*/
            else if(line[0] == 'r' && line[1] == 'e' && line[2] == 'm' && line[3] == '_' && line[4] == 'l' && line[5] == 'a' && line[6] == 'r' && line[7] == 'g' && line[8] == 'e' && line[9] == '\0'){
                numberSpaces = 11 - 9;
                printf("rem_large:");
                for(i = 0; i < numberSpaces; i++){
                    printf(" ");
                }
                remove_largest_key(list, &value, &key);
                printf("%d  %s\n",key, value);
            }
            /*size*/
            else if(line[0] == 's' && line[1] == 'i' && line[2] == 'z' && line[3] == 'e' && line[4] == '\0'){
                numberSpaces = 11 - 4;
                printf("size:");
                for(i = 0; i < numberSpaces; i++){
                    printf(" ");
                }
                printf("List size = %d\n",size(list));
            }
            /*print_all*/
            else if(line[0] == 'p' && line[1] == 'r' && line[2] == 'i' && line[3] == 'n' && line[4] == 't' && line[5] == '_' && line[6] == 'a'&& line[7] == 'l' && line[8] == 'l' && line[9] == '\0'){
                numberSpaces = 11 - 9;
                printf("print_all:");
                for(i = 0; i < numberSpaces; i++){
                    printf(" ");
                }
                printf("Insertion Order\n");
                print_list_all(list);
            }
            /*print_sort*/
            else if(line[0] == 'p' && line[1] == 'r' && line[2] == 'i' && line[3] == 'n' && line[4] == 't' && line[5] == '_' && line[6] == 's'&& line[7] == 'o' && line[8] == 'r' && line[9] == 't'&&line[10] == '\0'){
                numberSpaces = 11 - 10;
                printf("print_sort:");
                for(i = 0; i < numberSpaces; i++){
                    printf(" ");
                }
                printf("Key Sort Order\n");
                print_list_sort(list);
            }
            else if(line[0] == 'e' && line[1] == 'm' && line[2] == 'p' && line[3] == 't' && line[4] == 'y' && line[5] == '\0'){
                numberSpaces = 11 - 5;
                printf("empty:");
                for(i = 0; i < numberSpaces; i++){
                    printf(" ");
                }
                printf("size = 0\n");
                empty_list(list);
            }      
        } 
        destroy_list(list);  
        fclose(fp);
    }
    else{
        printf("Error - Expected 1 or 2 argument\n");
    }
    return 0;
}