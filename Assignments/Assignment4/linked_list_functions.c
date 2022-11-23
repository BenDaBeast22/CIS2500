#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linked_list_functions.h"

/**
Adds Node to the front of linked list and returns NULL upon failure if node being added is Null*/
Node * add_front(Node **head, value_type storedValue, key_type keyValue){

    /*Create a new node*/
    Node *newNode = malloc(sizeof(Node));


    if(newNode != NULL){
        /*Set value of new node*/
        #ifdef INT
        newNode -> value = storedValue;
        #endif

        #ifdef CHAR
        strcpy(newNode -> value, storedValue);
        #endif

        #ifdef FRACT
        newNode -> value = storedValue;
        #endif

        newNode -> key = keyValue;

        /*Set new node to point to what head is pointing to (previous first node in list or NULL if there are no elements in list*/
        newNode -> next = *head;

        /*Set head to point to the new first node in the list*/
        *head = newNode;
    }

    return newNode;

}
/**
Maintains the key sort order when node is added to the front of the list in insertion order*/
void add_sorted_front(Node **head_sort, Node *newNode){

        /*Set new node to point to what head is pointing to (previous first node in list or NULL if there are no elements in list*/
        newNode -> sort = *head_sort;

        /*Set head to point to the new first node in the list*/
        *head_sort = newNode;

}

/*Iterates through linked list and returns node that has a larger key than the key user inputted
 *If there is no key larger than the key inputted returns NULL*/
Node * find_gt(Node *head, key_type gt_key){

    Node *node = head;

    while(node != NULL && node -> key < gt_key){
        node = node -> sort;
    }

    return node;
}
/*Iterates through linked list and returns node that has a smaller key than user inputted
 *If there is no key smaller than the key inputted function returns NULL*/
Node * find_lt(Node *head, key_type gt_key){

    Node *node = head;
    Node *prev = NULL;

    while(node != NULL && node -> key < gt_key){
        prev = node;
        node = node -> sort;
    }
    return prev;
}
/*Finds the second last Node via insertion order in a linked list
 *Upon failure to find second last Node (there is no seocond last node) returns NULL*/
Node * find_second_last(Node * node){

    Node *prev = NULL;

    if(node != NULL){
        while(node -> next != NULL){
            prev = node;
            node = node -> next;
        }
    }
    return prev;
}
/*Inserts a node into the linked list
 *Does not work to insert at the head of a linked list (use add front)
 *Returns NULL if malloc fails and returns NULL*/
Node * insert_value(Node *previousNode, value_type storedValue, key_type keyValue){

    Node *newNode = malloc(sizeof(Node));

    if(newNode != NULL){
        #ifdef CHAR
        strcpy(newNode -> value, storedValue);
        #endif

        #ifdef FRACT
        newNode -> value = storedValue;
        #endif

        #ifdef INT
        newNode -> value = storedValue;
        #endif
        newNode -> key = keyValue;
        newNode -> next = previousNode -> next;
        previousNode -> next = newNode;
    }

    return newNode;

}
/**Maintains the sort key order when a node is inserted in Insertion order*/
void insert_sorted_value(Node *previousNode, Node *newNode){

    if(newNode != NULL){
        newNode -> sort = previousNode -> sort;
        previousNode -> sort = newNode;
    }

}
/*Maintains sort order when node is inserted into the list via insert_node*/
void add_sorted(Node **head_sort, Node *newNode, key_type keyValue){
    Node *insertNode;
    Node *nextNode = NULL;

    insertNode = find_lt(*head_sort, keyValue);

    /*If insertNode is Null that means it should become the new head*/
    if(insertNode == NULL){
        add_sorted_front(head_sort, newNode);
    }

    /*Else it should be inserted between a node that is smaller and node that is larger than num*/
    else{
        nextNode = insertNode -> sort;
        if(nextNode == NULL || nextNode -> key >= keyValue){
            insert_sorted_value(insertNode, newNode);
        }
    }

}
/*Iterates through the linked list and prints all nodes*/
void print_list(Node *node){
    #ifdef INT
    while(node != NULL){
        printf("     %.6g  %d\n", node -> key, node -> value);
        node = node -> next;
    }
    #endif

    #ifdef CHAR
    while(node != NULL){
        printf("     %d  %s\n", node -> key, node -> value);
        node = node -> next;
    }
    #endif
}
/*Iterates throught linked list and prints all nodes for fractions
 *Paramater mode is used to specify whether to print fraction as simple or MIXED
 *Parameter order is used to specify whether to print in key sort order or insertion order*/
void print_list_fraction(Node *node, int mode, int order){
    #ifdef FRACT
    while(node != NULL){
        printf("     %lf  ", node -> key);
        if(mode == SIMPLE){
            simplify(&(node -> value));
            print_fract(&(node -> value), SIMPLE);
        }
        else if(mode == MIXED){
            print_fract(&(node -> value), MIXED);
        }
        if(order == INSERTED_ORDER){
            node = node -> next;
        }
        else if(order == SORTED_ORDER){
            node = node -> sort;
        }
    }
    #endif
}
/*Iterates through list to print all nodes following key sort order*/
void print_sorted_list(Node *node){

    #ifdef INT
    while(node != NULL){
        printf("     %.6g  %d\n", node -> key, node -> value);
        node = node -> sort;
    }
    #endif

    #ifdef CHAR
    while(node != NULL){
        printf("     %d  %s\n", node -> key, node -> value);
        node = node -> sort;
    }
    #endif


}
/*Simplifies a fraction into lowest terms by dividing numerator and denominator by the gcd*/
void simplify(Fraction *fract){
    long long num = fract -> num;
    long long denom = fract -> denom;
    long long g = gcd(num, denom);
    long long simpNum = num/g;
    long long simpDenom = denom/g;
    fract -> num = simpNum;
    fract -> denom = simpDenom;
    /*printf("simpNum = %lli  simpDenom = %lli\n", simpNum, simpDenom);*/
}
/*Finds the gcd of two long long integers a and b*/
long long gcd(long long a, long long b){
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}
/*Prints a fraction as mixed or simple specified by the mode specified (mixed or simple)*/
void print_fract(Fraction *fract, int mode){
    long long num = fract -> num;
    long long denom = fract -> denom;
    long long wholeNumber;
    long long remainder;
    if(mode == SIMPLE){
        printf("%lli/%lli\n",num, denom);
    }
    else if(mode == MIXED){

        wholeNumber = num / denom;
        remainder = num % denom;
        if(remainder == 0 || num == denom){
            printf("%lli\n", wholeNumber);
        }
        else if(num < denom){
            printf("%lli/%lli\n", remainder, denom);
        }
        else{
            printf("%lli %lli/%lli\n", wholeNumber, remainder, denom);
        }
    }
}
/*FInds last node following insertion order of list*/
Node *find_last(Node * node){
    if(node != NULL){
        while(node -> next != NULL){
            node = node -> next;
        }
    }
    return node;
}
/*Finds the tail of a node*/
Node *find_tail(Node * node){
    if(node != NULL){
        while(node -> sort != NULL){
            node = node -> sort;
        }
    }
    return node;
}

/*Iterates through linked list and frees all of the nodes*/
void free_list(Node *head){
    Node *new_head = head, *old_node = NULL;

    while(new_head != NULL){
        old_node = new_head;
        new_head = new_head -> next;
        free(old_node);
    }
}
/*Finds the node with the greatest key and returns the node*/
int greatest_key(Node *tail_sort, Node *node){
    int value = 0;
    if(tail_sort != NULL){
        if(node -> key >= tail_sort -> key){
            value = 1;
        }
        else{
            value = 0;
        }
    }
    return value;
}
/*Finds the previous node of node inputted by iterating through the list
 *Returns NULL if there is no previous node behind the node*/
Node *findPrevious(Node *head, Node *node){
    Node *prev = head;
    while(prev != NULL && prev -> next != node){
        prev = prev -> next;
    }
    return prev;
}
/*Used with fgets to get rid of annoying \n char*/
int chop(char *line){
  int length;

  length = strlen(line);
  if(line[length-1]=='\n'){
    line[length-1] = '\0';
  }
  if(line == NULL){
    return(-1);
  }
  else{
    return(0);
  }

}
