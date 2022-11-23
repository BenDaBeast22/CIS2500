/**
 * Counts the amount of letters in a string and return that count
 */
int letter_count(char *word){
    int i;
    int c;
    int letterCount = 0;


    for(i = 0; word[i] != '\0'; i++){

        c = word[i];

        if(((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122))){

            letterCount++;

        }
    }

    return letterCount;


}