main: main.c rand_double.o rand_foobarbaz.o many_foobarbaz.o print_many_foobarbaz.o swap_structures.o free_many_foobarbaz.o
	gcc -ansi -Wall main.c -ggdb3 -o main rand_double.o rand_foobarbaz.o many_foobarbaz.o print_many_foobarbaz.o swap_structures.o free_many_foobarbaz.o

rand_double.o: rand_double.c
	gcc -ansi -Wall -ggdb3 -c rand_double.c

rand_foobarbaz.o: rand_foobarbaz.c
	gcc -ansi -Wall -ggdb3 -c rand_foobarbaz.c

many_foobarbaz.o: many_foobarbaz.c
	gcc -ansi -Wall -ggdb3 -c many_foobarbaz.c

print_many_foobarbaz.o: print_many_foobarbaz.c
	gcc -ansi -Wall -ggdb3 -c print_many_foobarbaz.c

swap_structures.o: swap_structures.c
	gcc -ansi -Wall -ggdb3 -c swap_structures.c

free_many_foobarbaz.o: free_many_foobarbaz.c
	gcc -ansi -Wall -ggdb3 -c free_many_foobarbaz.c

clean:
	rm main rand_double.o many_foobarbaz.o print_many_foobarbaz.o swap_structures.o free_many_foobarbaz.o