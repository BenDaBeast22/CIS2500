/**
 * Takes in the shift that a text was encoded with and return the shift to decode the text
 */
int to_decode(int shift){
    shift *= -1;
    return shift;
}