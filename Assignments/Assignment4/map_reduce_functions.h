#ifdef INT
    typedef int value_type;
    typedef double key_type;
#endif
value_type add(value_type v1, value_type v2);
value_type mult(value_type v1, value_type v2);
value_type exp2(value_type value);
value_type subtract(value_type v1, value_type v2);
value_type mult_self(value_type value);
value_type add_square(value_type v1, value_type v2);
void print_array(value_type *array, value_type size);
