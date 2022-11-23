#include <stdlib.h>

/**
 * Takes in 2 doubles the max and min which act as bounds for what the double will be randomized to 
 * With the max and min a random double is generated
 * Returns the random double
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