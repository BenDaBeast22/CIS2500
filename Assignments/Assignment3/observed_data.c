#include "decode.h"
#include <stdio.h>
/**
 * calculates observed data of text and returns the float
 */
double observed_data(char c, int letterCount){

    int n = letterCount;
    double ef[26] = EF;

    return(n * (ef[offset(c)]));
    
}