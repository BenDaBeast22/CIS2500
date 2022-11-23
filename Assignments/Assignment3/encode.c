#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Encodes text in a ceasar cipher 
 * Parameters: Takes shift number, -O flag(output file) and -F flag(input file)
 * The shiftNumber determines the shift of the cipher and if not provided the shift number is 13, the -F flag takes input from an input file and if not provided input comes from stdin and -O flag outputs encoded text to the output file specified and if no-O flag is provided then output goes to stdin
 */

int encode(int c, int shift){

    int oldc;

    if(shift > 0){
        if(((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 90))){
            oldc = c;
            c = shift + c;

            if((c > 90) && (oldc >= 65) && (oldc <= 90)){
                c = 64 + (c-90);
            }

            else if((c > 122) && (oldc >= 97) && (oldc <= 122)){
                c = 96 + (c-122);
            } 
        }    
    }

    else if(shift < 0){

        if(((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122))){

            oldc = c;
            c = shift + c;

            if((oldc >= 65) && (oldc <=90) && (c < 65)){
                c = oldc + (26 + shift);
            }

            else if((oldc >= 97) && (oldc <= 122) && (c < 97)){
                c = oldc + (26 + shift);
            }
        }
    }

    return c;
}
