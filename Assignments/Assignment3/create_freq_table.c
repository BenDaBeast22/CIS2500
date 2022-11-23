#include <stdlib.h>
/**
 * Dynamically creates an int array to store frequency of each letter and returns the array
 */
int * create_freq_table(){
    
    int *freq_table;
    int i;

    freq_table = malloc(sizeof(int) * 26);

    for(i = 0; i < 26; i++){
        freq_table[i] = 0;
    }

    return(freq_table);

}