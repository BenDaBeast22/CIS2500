Compilation
make all -> makes a4q1a_int, a4q1a_char, a4q1b, a4q2, a4q3
make a4q1a_int -> makes executable a4q1a_int -> ./a4q1a_int (textfile or io redirect) to run
make a4q1a_char -> makes executable a4q1a_char -> ./a4q1a_int (textfile or io redirect) to run
make a4q1b -> makes executable a4q1b -> ./a4q1b (textfile) to run
make a4q2 -> makes executable a4q2 -> ./a4q2 (textfile) to run
make a4q3 -> makes executable a4q3 -> ./a4q3 (textfile) to run
make clean -> removes all .o files and executables

Limitations:
- I only finished half of question 3 as well as I did not finish the remove function from question 2
- Sometimes when applying the commands some of the files might run a command an extra time or 1 less time

Where Functions are Located:
- My linked_list_functions as well as some of the fraction functions are located in the linked_list_functions.c file
- My adt functions for a4q1a are in the list_adt_functions.c (as well as a function to print fractions)
- My map/reduce functions for a4q1b that do not use adt Sorted_List are located in map_reduce_functions.c and my map/reduce functions
that use the Sorted_List adt are in map_reduce_adt.c
- My recursive functions for a4q2 are in recursion_functions.c and the adt recursion_function using Sorted_List are Located
in recursion_adt_functions.c
- My fraction functions are mostly in linked_list_functions in order to used nodes however one fraction function is in the fraction_adt.c
