#include <stdlib.h>

/**
 * Takes in 2 double a and b where a is the lower bound and b is the upper bound
 * Generates a random double between a and b and returns the number
 */

double rand_double(double a, double b){
    double randDouble;
    double oldA;
    if(b>a){
        randDouble = ((double) rand() / (double) RAND_MAX) * (b-a) + a;
    }
    else if(b<a){
        oldA = a;
        a = b;
        b = oldA;
        randDouble = ((double) rand() / (double) RAND_MAX) * (b-a) + a;
    }
    else{
        randDouble = a;
    }

    return randDouble;

    
}