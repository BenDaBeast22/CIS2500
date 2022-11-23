all: copy_text rot13 encode

copy_text: copy_text.c 
	gcc -ansi -Wall copy_text.c -o copy_text

rot13: rot13.c 
	gcc -ansi -Wall rot13.c -o rot13

encode: encode.c
	gcc -ansi -Wall encode.c -o encode

clean:
	rm copy_text rot13 encode 