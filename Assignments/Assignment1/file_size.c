#include <stdio.h>

/**
 * Calculating the number of bytes in a file for an estimate of how much dynamic memory to allocate per word
 */

int file_size(FILE *fp)
{
    int sz = 0;
    fseek(fp, 0L, SEEK_END);
    sz = ftell(fp);
    rewind(fp);
    return sz;
}








