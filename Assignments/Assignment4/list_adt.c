#include "linked_list_functions.h"
/**Sorted_List struct which holds the head, tail and the head with the greatest key and tail with the smallest key
 *Also holds an int for the size of the list which is incremented everytime a node is appended or pushed to the list*/
typedef struct{

    Node *head;
    Node *head_sort;
    Node *tail;
    Node *tail_sort;
    int size;


}Sorted_List;
