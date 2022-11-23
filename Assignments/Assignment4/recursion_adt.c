#include "list_adt.h"
#include "recursion_adt.h"
#include "recursion_functions.h"
#ifdef INT
    typedef int value_type;
    typedef double key_type;
#endif

/*Uses the recursive method "nth_recursive_method" to find and print the key and value of a node
this is an adt implementation of the function so that the node is not in main*/
int nth(Sorted_List *list, int n, double *key, int *value){
    int result = nth_recursive_method(list -> head, n, key, value);
    return result;
}
/*Uses the recursive method "nth_recursive_method_sorted" to find and print the key and value of a node
this is an adt implementation of the function so that the node is not in main*/
int nth_sorted(Sorted_List *list, int n, double *key, int *value){
    int result = nth_recursive_method_sorted(list -> head_sort, n, key, value);
    return result;
}

int remove_nth(Sorted_List *list, int n, double *key, int *value){
    int result = remove_nth_recursive_method(list -> head, n, key, value);
    return result;
}
/*
int remove_node(Sorted_List *list, Node *node){
    int result = FAILURE;
    Node *lastNode = find_last(node);
    Node *previousNode = findPrevious(node, );
    Node *previousNodeSort = find_lt(node);
    if(node != NULL){
        *value = node -> value;
        result = SUCCESS;
        if(node == list -> head) list -> head = node -> next;
        if(node == list -> head sort) list -> head_sort = node -> next;
        if(previousNode != NULL){
            previousNode -> next = node -> next;
        }
        if(find_lt != NULL){
            prevNode -> sort = node -> sort;
        }
        free(node);
        node == NULL;
    }
}
*/
