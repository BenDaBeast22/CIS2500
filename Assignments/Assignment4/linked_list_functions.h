#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "fraction_adt.h"

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

#define SUCCESS 1
#define FAILURE 0
#define SORTED_ORDER 1
#define INSERTED_ORDER 0

typedef struct NODE{

    value_type value;
    key_type key;
    struct NODE *next;
    struct NODE *sort;

}Node;

Node * add_front(Node **head, value_type storedValue, key_type keyValue);
void add_sorted_front(Node **head_sort, Node *newNode);
Node * find_gt(Node *head, key_type gt_key);
Node * find_lt(Node *head, key_type gt_key);
Node * find_second_last(Node *head);
Node * insert_value(Node *previousNode, value_type storedValue, key_type keyValue);
void insert_sorted_value(Node *previousNode, Node *newNode);
void add_sorted(Node **head, Node *Node, key_type keyValue);
void print_list(Node *head);
void print_sorted_list(Node *head);
Node *find_last(Node * node);
Node *find_tail(Node * node);
Node * find_prev(Node *head, Node *node);
void free_list(Node *head);
Node *findPrevious(Node *head, Node *node);
int chop(char *line);
int greatest_key(Node *tail_sort, Node *node);
void print_fract(Fraction *fract, int mode);
void print_list_fraction(Node *head, int mode, int order);
long long gcd(long long a, long long b);
void simplify(Fraction *fract);
