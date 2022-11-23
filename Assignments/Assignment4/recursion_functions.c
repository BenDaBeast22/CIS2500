#include "linked_list_functions.h"
#include "recursion_functions.h"
#ifdef INT
    typedef int value_type;
    typedef double key_type;
#endif
/*Counts up from n to m and prints each number*/
int countup(int n, int m){
    if(n == m){
        printf("%d\n",n);
        return 0;
    }
    else{
        printf("%d ",n);
        return(countup(n+1,m));
    }
}
/*Counts down from the integer n to 0 and prints out every number*/
int countdown(int n){
    if(n == 0){
        printf("%d\n",n);
        return 0;
    }
    else if(n <= 0){
        return 0;
    }
    else{
        printf("%d ",n);
        return(countdown(n-2));
    }
}

/*Uses recursion to find the nth node and print out it's key and value
 *Returns the node number found or if the node points to NULL in the case that a negative n is inputted or n is not a node in the list then
 returns -1*/
int nth_recursive_method(Node *node, int n, double *key, int *value){
    if(node != NULL){
        if(n == 0){
            *key = node -> key;
            *value = node -> value;
            return(0);
        }
        else{
            node = node -> next;
            return(nth_recursive_method(node,n - 1,key,value));
        }
    }
    else{
        return -1;
    }
}
/*Uses recursion to find the nth node and print out it's key and value using sorted order
 *Returns the node number found or if the node points to NULL in the case that a negative n is inputted or n is not a node in the list then
 returns -1*/
int nth_recursive_method_sorted(Node *node, int n, double *key, int *value){
    if(node != NULL){
        if(n == 0){
            *key = node -> key;
            *value = node -> value;
            return(0);
        }
        else{
            node = node -> sort;
            return(nth_recursive_method_sorted(node,n - 1,key,value));
        }
    }
    else{
        return -1;
    }
}
/*removes n recursively from the method*/
int remove_nth_recursive_method(Node *node, int n, double *key, int *value){
    if(node != NULL){
        if(n == 0){
            printf("\n     %g  %d\n", node -> key, node -> value);
            return(0);
        }
        else{
            node = node -> sort;
            return(nth_recursive_method_sorted(node,n - 1,key,value));
        }
    }
    else{
        return -1;
    }
}
