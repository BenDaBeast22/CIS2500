#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linked_list_functions.h"

#ifdef INT
    typedef int value_type;
    typedef double key_type;
#endif

#ifdef CHAR
    typedef char value_type[80];
    typedef int key_type;
#endif

#ifdef FRACT
    typedef Fraction value_type;
    typedef double key_type;
#endif

typedef struct{

    Node *head;
    Node *head_sort;
    Node *tail;
    Node *tail_sort;
    int size;

}Sorted_List;

Sorted_List * create_list();
int size(Sorted_List *list);
int push(Sorted_List *list, value_type storedValue, key_type keyValue);
int append_list(Sorted_List *list, value_type storedValue, key_type keyValue);
int append(Sorted_List *list, value_type storedValue, key_type keyValue);
void print_list_all(Sorted_List *list);
void print_list_sort(Sorted_List *sortedList);
int remove_first(Sorted_List *list, value_type *storedValue, key_type *keyValue);
int remove_last(Sorted_List *list, value_type *storedValue, key_type *keyValue);
int remove_smallest_key(Sorted_List * list, value_type *storedValue, key_type *keyValue);
void empty_list(Sorted_List *list);
void destroy_list(Sorted_List *list);
int remove_largest_key(Sorted_List * list, value_type *storedValue, key_type *keyValue);
void within(Sorted_List *list, void(*fn_ptr)(value_type));
void print_list_fract_all(Sorted_List *list, int mode, int order);
void simplify(Fraction *fract);
