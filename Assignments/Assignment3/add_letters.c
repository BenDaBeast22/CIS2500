/**
 * Takes in a word and frequency table 
 * Counts each specific letter and adds the count to the frequency table which has a count of the total number of letters of each word that has been added
 */ 
void add_letters(int *freq_table, char *word){

    int c;
    int i;
    for(i = 0; word[i] != '\0'; i++){

        c = word[i];
        if(((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122))){

            if((c >= 65) && (c <= 90)){ /*Converting all first chars to lowercase*/

                c += 32;
            }
            c -= 97; /*Converting all characters into integers starting from 0 to 25*/
            freq_table[c] += 1; /*Now appends character to corresponding letter of alphabet (a=0, b=1, ..., z=25)*/  
        }
    }

}