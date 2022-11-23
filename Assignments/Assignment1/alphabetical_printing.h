#define MAXLETTERS 46
#define TRUE 1
#define FALSE 0

int file_size(FILE *fp);
char ** read_words(FILE *fp);
void print_words(char **sptr);
int * alphabetical_word_count(char **sptr);
void print_alphabetical_word_count(int *);
char *** create_alphabetical_array(char **sptr, int *alphabetCount);
void free_alphabetical_array(char ***alphabetical_array);
void print_words_alphabetically(char ***alphabetical_array);
void free_alphabetical_word_count(int *alphabetCount);
void free_sptr(char **sptr);