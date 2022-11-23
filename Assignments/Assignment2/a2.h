struct Double_Array{

    double **array;
    int rows;
    int cols;

};

struct Double_Array * double_array(int row, int col);
double rand_double(double, double);
void randomize_array(struct Double_Array *double_struct, double min, double max);
void print_array(struct Double_Array *double_struct);
void free_array(struct Double_Array *double_struct);
int swap_rows(struct Double_Array *double_struct, int num1, int num2);
int swap_columns(struct Double_Array *double_struct, int num1, int num2);
struct Double_Array * shallow_copy(struct Double_Array *double_struct);
struct Double_Array * deep_copy(struct Double_Array *double_struct);
void print_struct(struct Double_Array *double_struct, char *header_string);
