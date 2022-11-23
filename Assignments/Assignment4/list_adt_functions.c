#include "list_adt.h"

/*Mallocs space ind dynamic memory to create a sorted list
 *Returns NULL if malloc fails*/
Sorted_List * create_list(){

    Sorted_List * new_list = malloc(sizeof(Sorted_List));

    if(new_list == NULL){
        new_list -> head = NULL;
        new_list -> head_sort = NULL;
        new_list -> tail = NULL;
        new_list -> tail_sort = NULL;
        new_list -> size = 0;
    }

    return new_list;
}
/*Returns the size of a list using the size field of the Sorted_List*/
int size(Sorted_List *list){
    return(list -> size);
}
/*Pushes a node to the head of the linked list
 *Returns NULL upon failure (if malloc fails)*/
int push(Sorted_List * list, value_type storedValue, key_type keyValue){
    Node *node;
    node = add_front(&(list -> head), storedValue, keyValue);
    if(node != NULL){
        if(greatest_key(list -> head_sort, node) == SUCCESS){
            list -> tail_sort = node;
        }
        add_sorted(&(list -> head_sort), node, keyValue);
        if(size(list) == 0){
            list -> tail = list -> head;
            list -> tail_sort = list -> head;
        }
        list -> size++;
        return SUCCESS;
    }
    else{
        return FAILURE;
    }
}
/*Inserts a node to tail of the list
 *Returns NULL upon malloc failure*/
int append_list(Sorted_List *list, value_type storedValue, key_type keyValue){

    Node *insertNode;

    insertNode = insert_value(list -> tail, storedValue, keyValue);
    if(insertNode != NULL){
        list -> tail = list -> tail -> next;
        if(greatest_key(list -> head_sort, insertNode) == SUCCESS){
            list -> tail_sort = insertNode;
        }
        add_sorted(&(list -> head_sort), list -> tail, keyValue);
        list -> size++;
        return SUCCESS;
    }
    else{
        return FAILURE;
    }
}
/*Used to add node to the tail of the list via using the push function to add node to the head or insert it into the list if a head already exists*/
int append(Sorted_List *list, value_type storedValue, key_type keyValue){

    if(list -> head == NULL){
        return push(list, storedValue, keyValue);
    }

    else{
        return append_list(list, storedValue, keyValue);
    }
}
/*Prints the linked list in insertion order*/
void print_list_all(Sorted_List *list){
    print_list(list -> head);
}
/*Prints all of the elements in a linked list with fractions*/
void print_list_fract_all(Sorted_List *list, int mode, int order){
    if(order == INSERTED_ORDER){
        print_list_fraction(list -> head, mode, order);
    }
    else if(order == SORTED_ORDER){
        print_list_fraction(list -> head_sort, mode, order);
    }
}
/*Prints list in key sort order*/
void print_list_sort(Sorted_List *list){
    print_sorted_list(list -> head_sort);
}
/*Removes the first Node in the list in insertion order
 *Returns failure if there is no node to remove in the list*/
int remove_first(Sorted_List *list, value_type *storedValue, key_type *keyValue){

    Node *head = list -> head, *prevNodeSort = NULL;

    #ifdef INT
    *storedValue = head -> value;
    #endif

    #ifdef CHAR
    strcpy(*storedValue, head -> value);
    #endif

    *keyValue = head -> key;

    if(head == NULL){
        return FAILURE;
    }

    list -> head = head -> next;

    prevNodeSort = find_lt(list -> head_sort, *keyValue);

    if(prevNodeSort == NULL){
        list -> head_sort = head -> sort;
    }

    else{
        prevNodeSort -> sort = head -> sort;
    }

    free(head);
    head = NULL;
    list -> size--;
    return SUCCESS;

}
/*Removes the last node in insertion order of the list
 *Fails if there is no node to remove and returns FAILURE*/
int remove_last(Sorted_List *list, value_type *storedValue, key_type *keyValue){

    Node *lastNode = NULL, *secondLast = NULL, *secondLastSort = NULL;
    /*Find last node in list*/
    lastNode = find_last(list -> head);

    /*If there is nothing in the list then return Failure because there is nothing to remove*/
    if(lastNode == NULL){
        return FAILURE;
    }
    #ifdef INT
    *storedValue = lastNode-> value;
    #endif

    #ifdef CHAR
    strcpy(*storedValue, lastNode -> value);
    #endif

    *keyValue = lastNode -> key;

    /*Find second last node in list*/
    secondLast = find_second_last(list -> head);

    secondLastSort = find_lt(list -> head_sort, lastNode -> key);

    /*If second last node in insertion order exists then set pointing to NULL (end of the list)*/
    if(secondLast != NULL){
        secondLast -> next = NULL;
    }
    /*If the previous node to the last node in insertion order is not NULL then the previous sort order node should point to the next sort order node*/
    if(secondLastSort != NULL){
        secondLastSort -> sort = lastNode -> sort;
    }
    /*If the previous node in insertion order is NULL then previous node is the new head_sort*/
    else{
        list -> head_sort = lastNode;
    }

    free(lastNode);
    lastNode = NULL;
    list -> size--;
    return SUCCESS;
}
/*Removes node with the largest key in the list
 *Fails if there is no node to remove and returns FAILURE*/
int remove_largest_key(Sorted_List * list, value_type *storedValue, key_type *keyValue){

    Node *sortTail = find_tail(list -> head_sort), *secondLargest = NULL, *previousNode = NULL;

    /*Nothing to remove in the list*/
    if(sortTail == NULL){
        return FAILURE;
    }
    /*Assigning removed values*/
    #ifdef INT
    *storedValue = sortTail -> value;
    #endif

    #ifdef CHAR
    strcpy(*storedValue, sortTail -> value);
    #endif
    *keyValue = sortTail -> key;

    /*Finds second largest node by sort order*/
    secondLargest = find_lt(list -> head_sort, sortTail -> key);
    /*Finds previous insertion node behind sortTail and if there is no previous insertion node returns NULL*/
    previousNode = findPrevious(list -> head, sortTail);
    /*If the second largest node by sort order is not NULL then it should now become the sortTail and point to NULL*/
    if(secondLargest -> sort != NULL){
        secondLargest -> sort = NULL;
        list -> tail_sort = secondLargest;
    }
    /*If the previousNode in insertion order is not NULL than it should point to the node sortTail is pointing to*/
    if(previousNode != NULL){
         previousNode -> next = sortTail -> next;
    }
    /*If previousNode in insertion order is NULL then the sortTail becomes the new head*/
    else{
        list -> head = sortTail;
    }

    free(sortTail);
    sortTail = NULL;
    list -> size--;
    return SUCCESS;
}
/*Removes node with the smallest key in the list
 *Fails if there is no node to remove and returns FAILURE*/
int remove_smallest_key(Sorted_List * list, value_type *storedValue, key_type *keyValue){

    Node *sortHead = list -> head_sort, *head = list -> head, *prev = head;

    /*Nothing to remove in the list*/
    if(sortHead == NULL){
        return FAILURE;
    }

    #ifdef INT
    *storedValue = sortHead -> value;
    #endif

    #ifdef CHAR
    strcpy(*storedValue, sortHead -> value);
    #endif
    *keyValue = sortHead -> key;
    /*Head points to next element in the list*/
    list -> head_sort = sortHead -> sort;

    prev = findPrevious(head, sortHead);

    if(prev == NULL){
        list -> head = head -> next;
    }

    else{
        prev -> next = sortHead -> next;
    }

    free(sortHead);
    sortHead = NULL;
    list -> size--;
    return SUCCESS;
}
/*Goes to a certain location in the list as specified by the functioin pointer parameter*/
void within(Sorted_List *list, void(*fn_ptr)(value_type)){
    Node *node = list -> head;
    while(node != NULL){
        (*fn_ptr)(node -> value);
        node = node -> next;
    }

}
/*Iterates through the list and frees all of the nodes from memory*/
void empty_list(Sorted_List *list){
    free_list(list -> head);
    list -> head = NULL;
}
/*Frees the Sorted_List from memory*/
void destroy_list(Sorted_List *list){
    empty_list(list);
    free(list);
    list = NULL;
}
