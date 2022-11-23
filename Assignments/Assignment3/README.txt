Question 3 Reverse Records Explination: To reverse the records I looped through the number of records there were and through
every iteration I used fseek from SEEK_END and I moved backwards in the file with an offset of negative the value of a record.
I also had to use another counter variable j and set the loop counter i = 1 because if I didn't do this when i = 0 I would be trying
to get a record from the end of a file which is not possible.

Assumptions: I assumed a max size in Q2 for getting input from stdin 

Note: My chi squared values are a bit different from the examples the professor showed in his example however I tested them and they 
still work to find the encode shift of a file

Executing Code:
make all -> Makes frequency_table.c decode.c and copyrecords.c into executables
make frequency_table -> makes frequency table.c executable
make decode -> makes decode.c executable
make copyrecords -> makes copyrecords executable
make clean -> removes all .o files and executable files
