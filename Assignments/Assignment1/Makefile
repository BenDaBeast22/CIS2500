alphabetical_printing: alphabetical_printing.c read_words.o print_words.o file_size.o alphabetical_word_count.o print_alphabetical_word_count.o create_alphabetical_array.o free_alphabetical_array.o print_words_alphabetically.o free_alphabetical_word_count.o free_sptr.o
	gcc -ansi -Wall alphabetical_printing.c -o alphabetical_printing read_words.o print_words.o file_size.o alphabetical_word_count.o print_alphabetical_word_count.o create_alphabetical_array.o free_alphabetical_array.o print_words_alphabetically.o free_alphabetical_word_count.o free_sptr.o 

free_sptr.o: free_sptr.c
	gcc -ansi -Wall -c free_sptr.c
free_alphabetical_word_count.o: free_alphabetical_word_count.c
	gcc -ansi -Wall -c free_alphabetical_word_count.c

print_words_alphabetically.o: print_words_alphabetically.c
	gcc -ansi -Wall -c print_words_alphabetically.c

free_alphabetical_array.o: free_alphabetical_array.c
	gcc -ansi -Wall -c free_alphabetical_array.c

create_alphabetical_array.o: create_alphabetical_array.c
	gcc -ansi -Wall -c create_alphabetical_array.c

print_alphabetical_word_count.o: print_alphabetical_word_count.c
	gcc -ansi -Wall -c print_alphabetical_word_count.c

alphabetical_word_count.o: alphabetical_word_count.c
	gcc -ansi -Wall -c alphabetical_word_count.c

print_words.o: print_words.c
	gcc -ansi -Wall -c print_words.c

read_words.o: read_words.c
	gcc -ansi -Wall -c read_words.c

file_size.o: file_size.c
	gcc -ansi -Wall -c file_size.c

clean:
	rm alphabetical_printing file_size.o print_words.o read_words.o alphabetical_word_count.o print_alphabetical_word_count.o create_alphabetical_array.o free_alphabetical_array.o print_words_alphabetically.o free_alphabetical_word_count.o free_sptr.o