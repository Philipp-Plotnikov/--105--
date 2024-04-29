#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#include "calc.hpp"

#define MAXOP 100

using namespace std;

int main() {
    int type;
    double op1, op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push_stack(atof(s));
            break;
        case '+':
            push_stack(pop_stack() + pop_stack());
            break;
        case '*':
            push_stack(pop_stack() * pop_stack());
            break;
        case '-':
            op2 = pop_stack();
            push_stack(pop_stack() - op2);
            break;
        case '/':
            op2 = pop_stack();
            if (op2 != 0.0)
                push_stack(pop_stack() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            op2 = pop_stack();
            if (op2 != 0.0)
                push_stack(fmod(pop_stack(), op2)); // 
            else
                printf("error: zero divisor\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop_stack());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }

    return 0;
}