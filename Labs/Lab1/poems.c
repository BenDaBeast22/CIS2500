#include <stdio.h>
#include <string.h>
#define IN 1
#define OUT 0

int main()
{
    int c;
    int wordCount;
    int lineCount;
    int wordLineCount;
    int state;
    int array[200]; /*Stores word count of each line*/
    int i = 0;
    int arrayLength = 0;

    state = OUT;
    lineCount = 0;

    c = wordCount = wordLineCount = 0;

    while((c = getchar()) != '.')
    {
        if(c == '\n'){
            lineCount++;
            array[i] = wordLineCount;
            i++;
            wordLineCount = 0;
        }

        if(c == ' ' || c == '\t' || c == '\n'){
            state = OUT;
        }

        else if(state == OUT){
            state = IN;
            wordCount++;
            wordLineCount++;
        }
    }

    arrayLength = i;

    printf("%d words on %d lines\n",wordCount, lineCount);

    for(i = 0; i < arrayLength; i++){
        printf("%d ",array[i]);
    }
    printf("\n");

    return(0);  
}