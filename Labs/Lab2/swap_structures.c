#include "main.h"

void swap_structures(struct foobarbaz **many_foobarbaz, int num1, int num2){
    
    int foo1;
    double bar1;
    int baz1;

    int foo2;
    double bar2;
    int baz2;

    /*Extracting values from struct1 to be swapped*/
    foo1 = many_foobarbaz[num1] -> foo;
    bar1 = many_foobarbaz[num1] -> bar;
    baz1 = many_foobarbaz[num1] -> baz;

    /*Extracting values from struct2 to swapperd*/
    foo2 = many_foobarbaz[num2] -> foo;
    bar2 = many_foobarbaz[num2] -> bar;
    baz2 = many_foobarbaz[num2] -> baz;
    
    /*struct2 variables set equal to struct1 variables*/
    many_foobarbaz[num2] -> foo = foo1;
    many_foobarbaz[num2] -> bar = bar1;
    many_foobarbaz[num2] -> baz = baz1;

    /*struct 1 variables set equal to struct2 variables thus completing the swap*/
    many_foobarbaz[num1] -> foo = foo2;
    many_foobarbaz[num1] -> bar = bar2;
    many_foobarbaz[num1] -> baz = baz2;

}