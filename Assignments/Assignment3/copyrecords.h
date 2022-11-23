#define TRUE 1
#define FALSE 0
#define STRUCTSIZE 408
#define MAXSIZE 200

struct data{
    char string1[24];
    double decimal[24];
    char string2[144];
    int integers[12];
};

int encode_shift(int letterCount, int *frequency_table);
void add_letters(int *frequency_table, char *inputString);
int letter_count(char *inputString);
int * create_freq_table();
int to_decode(int shift);
int encode(char c, int shift);


