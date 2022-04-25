#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "postfix.h"
#include "expressiontree.h"

int main(){
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);
    et t1;
    init_tree(&t1, exp);
    return 0;
}
