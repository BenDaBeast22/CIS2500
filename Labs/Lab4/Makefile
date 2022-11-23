main: main.c create_list.o print_list.o sort1.o sort2.o print_list_sort1.o print_list_sort2.o swap1.o swap2.o rand_double.o free_linked_list.o
	gcc -ansi -Wall main.c -o main create_list.o print_list.o sort1.o sort2.o print_list_sort1.o print_list_sort2.o swap1.o swap2.o rand_double.o free_linked_list.o

create_list.o: create_list.c
	gcc -ansi -Wall -c create_list.c 

print_list.o: print_list.c 
	gcc -ansi -Wall -c print_list.c 

sort1.o: sort1.c 
	gcc -ansi -Wall -c sort1.c

sort2.o: sort2.c 
	gcc -ansi -Wall -c sort2.c

print_list_sort1.o: print_list_sort1.c 
	gcc -ansi -Wall -c print_list_sort1.c

print_list_sort2.o: print_list_sort2.c 
	gcc -ansi -Wall -c print_list_sort2.c

swap1.o: swap1.c 
	gcc -ansi -Wall -c swap1.c 

swap2.o: swap2.c 
	gcc -ansi -Wall -c swap2.c

rand_double.o: rand_double.c 
	gcc -ansi -Wall -c rand_double.c

free_linked_list.o: free_linked_list.c 
	gcc -ansi -Wall -c free_linked_list.c

clean:
	rm create_list.o print_list.o sort1.o sort2.o print_list_sort1.o print_list_sort2.o swap1.o swap2.o rand_double.o free_linked_list.o main 