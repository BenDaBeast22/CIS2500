#define FALSE 0
#define TRUE 1
#define MIXED 10
#define SIMPLE 5

typedef struct{
    long long num;
    long long denom;
}Fraction;

Fraction * create_fraction();
int set_fraction(Fraction *fract, long long num, long long denom);
