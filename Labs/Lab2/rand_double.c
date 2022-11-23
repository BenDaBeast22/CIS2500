#include <stdlib.h>

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