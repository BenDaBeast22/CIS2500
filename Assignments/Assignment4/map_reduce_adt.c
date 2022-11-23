#include "list_adt.h"
#include "map_reduce_adt.h"

/*Used to map nodes in the list to an adjusted value  using fn_ptr (Ex each number squared)
 *Creates a new list in dynamic memory to store the mapped values
 *Returns the newList
*/
Sorted_List * map(Sorted_List *list, value_type(*fn_ptr)(value_type)){
    Node *node = list -> head;
    int i;
    Sorted_List * newList = create_list();

    for(i = 0; i < size(list); i++){
        append(newList, (*fn_ptr)(node -> value), node -> key);
        node = node -> next;
    }
    return newList;

}
/*Used to appply an accumalitive operation on the list such as find the sum of all of the elements in the list
 *init specifies the starting value
 *order specifies the order operations should be applied
 *the function pointer reduce is applied(operation)
 *the result is accumalaated in result variable and returned
 */
value_type reduce(Sorted_List *list, value_type(*reduce)(value_type, value_type), value_type init, int order){
    Node *node = list -> head;

    if(order == SORTED_ORDER){
        node = list -> head_sort;
    }

    int i;
    value_type result = init;
    for(i = 0; i < size(list); i++){
        result = (*reduce)(node -> value, result);
        if(order == INSERTED_ORDER){
            node = node -> next;
        }
        else if(order == SORTED_ORDER){
            node = node -> sort;
        }
    }
    return result;
}
/*Maps an operation to the list using the fn_ptr and then after the operation is applied it is accumulated just like in reduce function above
 *Returns final result*/
value_type map_reduce(Sorted_List *list, value_type(*fn_ptr)(value_type), value_type(*reduce)(value_type, value_type), value_type init, int order){
    Node *node = list -> head;

    if(order == SORTED_ORDER){
        node = list -> head_sort;
    }

    int i;
    value_type map;
    value_type result = init;

    for(i = 0; i < size(list); i++){
        map = (*fn_ptr)(node -> value);
        result = (*reduce)(map, result);
        if(order == INSERTED_ORDER){
            node = node -> next;
        }
        else if(order == SORTED_ORDER){
            node = node -> sort;
        }
    }
    return result;
}
/*Performs an operation using 2 lists such as addition or subtraction and stores the result in an array
 *the array is returned*/
value_type * map_2_array(Sorted_List *list1, Sorted_List *list2, value_type(*fn_ptr)(value_type, value_type), int order){
    Node *node1 = list1 -> head;
    Node *node2 = list2 -> head;

    if(order == SORTED_ORDER){
        node1 = list1 -> head_sort;
        node2 = list2 -> head_sort;
    }

    int i;
    value_type result;
    value_type *array = malloc(sizeof(value_type) * size(list1));

    for(i = 0; i < size(list1); i++){
        result = (*fn_ptr)(node1 -> value, node2 -> value);

        array[i] = result;

        if(order == INSERTED_ORDER){
            node1 = node1 -> next;
            node2 = node2 -> next;
        }
        else if(order == SORTED_ORDER){
            node1 = node1 -> sort;
            node2 = node2 -> sort;
        }
    }
    return array;

}
/*Applies an operation using fn_ptr to 2 lists and then accumalates the result and returns the result*/
value_type map_2_reduce(Sorted_List *list1, Sorted_List *list2, value_type(*fn_ptr)(value_type, value_type),value_type(*reduce)(value_type, value_type), value_type init, int order){

    Node *node1 = list1 -> head;
    Node *node2 = list2 -> head;

    if(order == SORTED_ORDER){
        node1 = list1 -> head_sort;
        node2 = list2 -> head_sort;
    }

    int i;
    value_type map;
    value_type result = init;

    for(i = 0; i < size(list1); i++){

        map = (*fn_ptr)(node1 -> value, node2 -> value);

        result = (*reduce)(map, result);

        if(order == INSERTED_ORDER){
            node1 = node1 -> next;
            node2 = node2 -> next;
        }
        else if(order == SORTED_ORDER){
            node1 = node1 -> sort;
            node2 = node2 -> sort;
        }
    }

    return result;
}
/*Finds the sum of the nodes of a list*/
value_type sum(Sorted_List *list){
  return reduce(list, add, 0, INSERTED_ORDER);
}
/*Finds the sum squared of nodes in the list*/
value_type sum_sq(Sorted_List *list){
    return reduce(list, mult, 1, INSERTED_ORDER);
}
/*Finds the differance betweens 2 nodes in a list and returns an array with the result of the differance between each node*/
value_type *diff(Sorted_List *list1, Sorted_List *list2, int order){
    if(size(list1) == size(list2)){
      return map_2_array(list1, list2, subtract, order);
    }
    else{
        return NULL;
    }
}
/*Squares every node in the list*/
Sorted_List * square(Sorted_List *list){
    return map(list, mult_self);
}
/*Finds the sum of the squares of 2 nodes and then finds the diff between the two lists*/
value_type sum_of_sq_diff(Sorted_List *list1, Sorted_List *list2, int order){
    if(size(list1) == size(list2)){
        return map_2_reduce(list1, list2, subtract, add_square,0, order);
    }
    else{
        return FAILURE;
    }
}
