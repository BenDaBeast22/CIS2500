/**
 * Takes in a string and returns the total number of characters in the string
 */
int char_count(char *word){
    int i;
    int charCount = 0;


    for(i = 0; word[i] != '\0'; i++){
        charCount++;
    }

    return charCount;
    
}