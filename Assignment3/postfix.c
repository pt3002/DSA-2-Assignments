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

char* infixToPostfix(char* exp){
    int i, k;
    stack* st = create(strlen(exp));
    char *ans;
    ans = (char *)malloc(sizeof(char)*200);
    for (i = 0, k = -1; exp[i]; ++i)
    {
        if(isOperand(exp[i])){
                ans[++k] = exp[i];
                if((i+1)<strlen(exp) && isOperand(exp[i+1])){
                    ans[++k] = exp[i+1];
                    ++i;
                }
                ans[++k] = ' ';
        }
        else if(exp[i] == '(')
            push(st, exp[i]);
        else if (exp[i] == ')')
        {
            while (!isEmpty(st) && peek(st) != '('){
                ans[++k] = pop(st);
                ans[++k] = ' ';
            }
            if (!isEmpty(st) && peek(st) != '(')
                return "";          
            else
                pop(st);
        }
        else 
        {
            while (!isEmpty(st) &&
                 Precedence_check(exp[i]) <= Precedence_check(peek(st))){
                ans[++k] = pop(st);
                ans[++k] = ' ';
                }
            push(st, exp[i]);
        }
    }
    while (!isEmpty(st)){
        ans[++k] = pop(st);
        ans[++k] = ' ';
    }
    ans[++k] = '\0';
    return ans;
}