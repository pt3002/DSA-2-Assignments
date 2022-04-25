#include "postfix.h"
#include "stack.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int isOperand(char ch){
    if(ch>='0' && ch<='9'){
        return 1;
    }
    else if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
        return 1;
    }
    return 0;
}

int Precedence_check(char ch){
    switch (ch){
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;
    
    case '^':
        return 3;
    }
    return -1;
}

int infixToPostfix(char* exp){
    int i, k;
    stack* st = create(strlen(exp));
 
    for (i = 0, k = -1; exp[i]; ++i)
    {
        if (isOperand(exp[i]))
            exp[++k] = exp[i];
        else if (exp[i] == '(')
            push(st, exp[i]);
        else if (exp[i] == ')')
        {
            while (!isEmpty(st) && peek(st) != '(')
                exp[++k] = pop(st);
            if (!isEmpty(st) && peek(st) != '(')
                return -1;          
            else
                pop(st);
        }
        else 
        {
            while (!isEmpty(st) &&
                 Precedence_check(exp[i]) <= Precedence_check(peek(st)))
                exp[++k] = pop(st);
            push(st, exp[i]);
        }
 
    }
    while (!isEmpty(st))
        exp[++k] = pop(st);
 
    exp[++k] = '\0';
    printf("%s", exp);
}