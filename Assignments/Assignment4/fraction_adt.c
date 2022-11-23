#include "fraction_adt.h"
#include <stdio.h>
#include <stdlib.h>

/**Sets the numerator and denominator of a fraction using a fraction pointer
 *Returns TRUE if the denominator is not 0 otherwise it returns FALSE*/
int set_fraction(Fraction *fract, long long num, long long denom){
    if(denom < 0){
        denom *= -1;
    }
    if(denom == 0){
        return FALSE;
    }
    fract -> denom = denom;
    fract -> num = num;
    return TRUE;
}
