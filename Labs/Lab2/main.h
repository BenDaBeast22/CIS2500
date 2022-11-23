struct foobarbaz{
    int foo;
    int baz;
    double bar;
};
double rand_double(double a, double b);
struct foobarbaz * rand_foobarbaz();
struct foobarbaz ** many_foobarbaz();
void print_many_foobarbaz(struct foobarbaz **many_foobarbaz);
void swap_structures(struct foobarbaz **many_foobarbaz, int num1, int num2);
void free_many_foobarbaz(struct foobarbaz **many_foobarbaz);

