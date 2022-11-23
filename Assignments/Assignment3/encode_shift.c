#include "decode.h"
#include <stdio.h>

/**
 * Uses the chi_sq guess in order to determine the shift of the encoded text 
 * Returns the encoded shift guess
 */
int encode_shift(int letterCount, int *frequency_table){

    int shift = 0;
    int eFlag = FALSE;
    int encodeShift;
    double previousShiftGuess = 0.5;
    double shiftGuess = 0.0;

    for(shift = 0; shift < 26; shift++){
            
        shiftGuess = chi_sq(letterCount, frequency_table, shift); 
        
        if(shiftGuess < previousShiftGuess){
                previousShiftGuess = shiftGuess;
                encodeShift = shift;
                eFlag = TRUE;
        }

        shiftGuess = 0.0;
        
    }

    if(eFlag == FALSE){
        return 0;
    }

    else{
        return encodeShift;
    }
}