all: frequency_table decode copyrecords

frequency_table: frequency_table.c add_letters.o create_freq_table.o letter_count.o char_count.o 
	gcc -ansi -Wall frequency_table.c -o frequency_table add_letters.o create_freq_table.o letter_count.o char_count.o 

decode: decode.c observed_data.o offset.o encode.o encode_shift.o create_freq_table.o add_letters.o letter_count.o char_count.o chi_sq.o to_decode.o
	gcc -ansi -Wall decode.c -o decode observed_data.o offset.o encode.o encode_shift.o create_freq_table.o add_letters.o letter_count.o char_count.o chi_sq.o to_decode.o

copyrecords: copyrecords.c encode_shift.o add_letters.o letter_count.o create_freq_table.o to_decode.o encode.o chi_sq.o observed_data.o offset.o
	gcc -ansi -Wall copyrecords.c -o copyrecords encode_shift.o add_letters.o letter_count.o create_freq_table.o to_decode.o encode.o chi_sq.o observed_data.o offset.o

add_letters.o: add_letters.c 
	gcc -ansi -Wall -c add_letters.c

create_freq_table.o: create_freq_table.c 
	gcc -ansi -Wall -c create_freq_table.c

letter_count.o: letter_count.c	
	gcc -ansi -Wall -c letter_count.c 

char_count.o: char_count.c 
	gcc -ansi -Wall -c char_count.c

observed_data.o: observed_data.c 
	gcc -ansi -Wall -c observed_data.c

offset.o: offset.c 
	gcc -ansi -Wall -c offset.c

encode.o: encode.c 
	gcc -ansi -Wall -c encode.c

encode_shift.o: encode_shift.c 
	gcc -ansi -Wall -c encode_shift.c

chi_sq.o: chi_sq.c 
	gcc -ansi -Wall -c chi_sq.c

to_decode.o: to_decode.c 
	gcc -ansi -Wall -c to_decode.c

clean:
	rm to_decode.o chi_sq.o encode_shift.o encode.o offset.o observed_data.o char_count.o letter_count.o create_freq_table.o add_letters.o copyrecords frequency_table decode