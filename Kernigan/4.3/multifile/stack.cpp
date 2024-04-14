#include <stdio.h>
#include <stdlib.h> /* для atof() */
#include "stack.h"

int sp = 0; /* следующая свободная позиция в стеке */
double val[MAXVAL]; /* стек */

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("ошибка: стек полон, %g не помещается\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf( "ошибка: стек пуст\n");
        return 0.0;
    }
}