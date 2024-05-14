#include <math.h>
#include <stdio.h>
#include "stack.h"
#include "getop.h"

int main ()
{
    int type;
    double op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push_stack (atof(s));
                break;
            case '+':
                push_stack (pop_stack() + pop_stack());
                break;
            case '*':
                push_stack (pop_stack() * pop_stack());
                break;
            case '-':
                op2 = pop_stack();
                push_stack (pop_stack() - op2);
                break;
            case '/':
                op2 = pop_stack();
                if (op2 != 0.0)
                    push_stack (pop_stack() / op2);
                else
                    printf("ошибка: деление на нуль\n");
                break;
            case '%':
                op2 = pop_stack();
                push_stack(fmod(pop_stack(), op2));
                break;
            case '\n' :
                printf("\t%.8g\n", pop_stack());
                break;
            default:
                printf("ошибка: неизвестная операция %s\n", s);
                break;
        }
    }
    return 0;
}