typedef struct NODE{
    int value;
    double key1;
    double key2;
    struct NODE *next;
    struct NODE *sort1;
    struct NODE *sort2;
}Data;

Data * create_list(int num);
void print_list(Data *node);
Data * sort1(Data *node);
Data * sort2(Data *head);
void print_list_sort1(Data *node);
void print_list_sort2(Data *node);
Data * swap1(Data *sort1_head, double a, double b);
Data * swap2(Data *sort2_head, double a, double b);
double rand_double(double a, double b);
void free_linked_list(Data *head);