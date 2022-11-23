#include "map_reduce_functions.h"
#ifdef INT
    typedef int value_type;
    typedef double key_type;
#endif
Sorted_List * map(Sorted_List *list, value_type(*fn_ptr)(value_type));
value_type reduce(Sorted_List *list, value_type(*reduce)(value_type, value_type), value_type init, int order);
value_type map_reduce(Sorted_List *list, value_type(*fn_ptr)(value_type), value_type(*reduce)(value_type, value_type), value_type init, int order);
value_type * map_2_array(Sorted_List *list1, Sorted_List *list2, value_type(*fn_ptr)(value_type, value_type), int order);
value_type map_2_reduce(Sorted_List *list1, Sorted_List *list2, value_type(*fn_ptr)(value_type, value_type),value_type(*reduce)(value_type, value_type), value_type init, int order);
value_type sum(Sorted_List *list);
value_type sum_sq(Sorted_List *list);
value_type *diff(Sorted_List *list1, Sorted_List *list2, int order);
Sorted_List * square(Sorted_List *list);
value_type sum_of_sq_diff(Sorted_List *list1, Sorted_List *list2, int order);
