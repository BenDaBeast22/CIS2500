#include "map_reduce_functions.h"
#include <stdio.h>

/*Adds 2 values together*/
value_type add(value_type v1, value_type v2){
    return v1 + v2;
}
/*Multipies 2 values together*/
value_type mult(value_type v1, value_type v2){
    return v1*v2;
}
/*Multiplies value by 2*/
value_type exp2(value_type value){
    return(2 * value);
}
/*Subtracts 2 values*/
value_type subtract(value_type v1, value_type v2){
    return v1-v2;
}
/*Multiplies value by itself(square)*/
value_type mult_self(value_type value){
    return value*value;
}
/*Adds the square of a value with another value*/
value_type add_square(value_type v1, value_type v2){
    return (v1*v1 + v2);
}
/*prints array from the map_2_array function*/
void print_array(value_type *array, value_type size){
    value_type i;

    for(i = 0; i < size; i++){
        printf("     %d\n", array[i]);
    }
}
