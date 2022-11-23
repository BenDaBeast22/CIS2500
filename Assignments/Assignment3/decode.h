#define EF {0.08167, 0.01429, 0.02782, 0.04253, 0.12702, 0.0228, 0.02015, 0.06094, 0.06966, 0.00153, 0.00772, 0.04025, 0.02406, 0.06749, 0.07707, 0.01929, 0.00095, 0.05987, 0.06327, 0.09056, 0.02758, 0.00978, 0.02360, 0.00150, 0.01974, 0.00074}
#define ALPHABET_LENGTH 26
#define TRUE 1
#define FALSE 0

int letter_count(char *);
int * create_freq_table();
void add_letters(int *frequency_table, char *input);
double observed_data(char c, int letterCount);
int encode_shift(int letterCount, int *frequency_table);
int encode(char c, int shift);
int offset(char c);
int char_count(char *);
double chi_sq(int letterCount, int *frequeny_table, int shift);
int to_decode(int shift);



