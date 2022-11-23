/**
 * Calculates the offset of a char
 */
int offset(char c){

    int offset;

    if((c >= 97) && (c <= 122)){

        c -= 97;

    }

    offset = c;

    return(offset);
}