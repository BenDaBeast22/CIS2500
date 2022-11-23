all: a4q1a_char a4q1a_int a4q1b a4q2 a4q3

a4q3: a4q3.o linked_list_functions_fract.o list_adt_functions_fract.o fraction_adt.o
	gcc -ansi -Wall -o a4q3 a4q3.o linked_list_functions_fract.o list_adt_functions_fract.o fraction_adt.o

a4q2: a4q2.o linked_list_functions_int.o list_adt_functions_int.o recursion_functions.o recursion_adt.o
	gcc -ansi -Wall -o a4q2 a4q2.o linked_list_functions_int.o list_adt_functions_int.o recursion_functions.o recursion_adt.o

a4q1b: a4q1b.o linked_list_functions_int.o list_adt_functions_int.o map_reduce_functions.o map_reduce_adt.o
	gcc -ansi -Wall -o a4q1b a4q1b.o linked_list_functions_int.o list_adt_functions_int.o map_reduce_functions.o map_reduce_adt.o

a4q1a_int: a4q1a_int.o linked_list_functions_int.o list_adt_functions_int.o
	gcc -ansi -Wall -o a4q1a_int a4q1a_int.o linked_list_functions_int.o list_adt_functions_int.o

a4q1a_char: a4q1a_char.o linked_list_functions_char.o list_adt_functions_char.o
	gcc -ansi -Wall -o a4q1a_char a4q1a_char.o linked_list_functions_char.o list_adt_functions_char.o

a4q3.o: a4q3.c
	gcc -ansi -Wall -DFRACT -c a4q3.c

a4q2.o: a4q2.c
	gcc -ansi -Wall -DINT -c a4q2.c

a4q1b.o: a4q1b.c
	gcc -ansi -Wall -DINT -c a4q1b.c

a4q1a_int.o: a4q1a_int.c
	gcc -ansi -Wall -c a4q1a_int.c -DINT -o a4q1a_int.o

a4q1a_char.o: a4q1a_char.c
	gcc -ansi -Wall -c a4q1a_char.c -DCHAR -o a4q1a_char.o

fraction_adt.o: fraction_adt.c
	gcc -ansi -Wall -c -DINT fraction_adt.c

recursion_adt.o: recursion_adt.c
	gcc -ansi -Wall -c -DINT recursion_adt.c

recursion_functions.o: recursion_functions.c
	gcc -ansi -Wall -c -DINT recursion_functions.c

map_reduce_adt.o: map_reduce_adt.c
	gcc -ansi -Wall -c -DINT map_reduce_adt.c

map_reduce_functions.o: map_reduce_functions.c
	gcc -ansi -Wall -c -DINT map_reduce_functions.c

list_adt_functions_fract.o: list_adt_functions.c
	gcc -ansi -Wall -DFRACT -c list_adt_functions.c -o list_adt_functions_fract.o

list_adt_functions_int.o: list_adt_functions.c
	gcc -ansi -Wall -DINT -c list_adt_functions.c -o list_adt_functions_int.o

list_adt_functions_char.o: list_adt_functions.c
	gcc -ansi -Wall -DCHAR -c list_adt_functions.c -o list_adt_functions_char.o

linked_list_functions_fract.o: linked_list_functions.c
	gcc -ansi -Wall -DFRACT -c linked_list_functions.c -o linked_list_functions_fract.o

linked_list_functions_int.o: linked_list_functions.c
	gcc -ansi -Wall -DINT -c linked_list_functions.c -o linked_list_functions_int.o

linked_list_functions_char.o: linked_list_functions.c
	gcc -ansi -Wall -DCHAR -c linked_list_functions.c -o linked_list_functions_char.o

clean:
	rm *.o a4q1a_int a4q1a_char a4q1b a4q2 a4q3
