#include "a2.h"

/**
 * Creates a shallow copy of a pointer to a Double_Array struct
 */

struct Double_Array * shallow_copy(struct Double_Array *double_struct){

    struct Double_Array *struct_copy;

    struct_copy = double_struct;

    return struct_copy;
    
}