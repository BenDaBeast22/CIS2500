#include "decode.h"
/**
 * Calculates a guess to determine the encoded shift of text depending on the freqeuncy of letters
 * Returns the guess
 */
double chi_sq(int letterCount, int *frequency_table, int shift){

    char c;
    int n;
    double observedData;
    double expectedData;
    double shiftGuess = 0;

    n = letterCount;

    for(c = 97; c < 123; c++){
            
        observedData = observed_data(c, n);
            
        expectedData = frequency_table[(offset(encode(c, shift)))];
            
        shiftGuess += ((observedData - expectedData) * (observedData - expectedData)) / (n * observedData);
            
    }

    return shiftGuess;
}