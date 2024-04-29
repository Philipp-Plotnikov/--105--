#include <stdio.h>
#include <stdlib.h> /* для atof() */
#include <ctype.h>
#include <math.h>

#define MAXOP 3 /* макс. размер операнда или оператора */
#define NUMBER '0' /* признак числа */
#define MAXVAL 100 /* максимальная глубина стека */
#define BUFSIZE 100

int sp = 0; /* следующая свободная позиция в стеке */
double val[MAXVAL]; /* стек */

void push_stack(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("ошибка: стек полон, %g не помещается\n", f);
}

double pop_stack(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf( "ошибка: стек пуст\n");
        return 0.0;
    }
}

/* getop: получает следующий оператор или операнд */
int getop(char s[])
{   
    if (MAXOP < 1) {
        printf( "Error: reach the MAXOP\n");
        exit (1);
    } 
    int i, c;
    int isMinus = 0;
    while ((s[0] = c = getchar()) == ' ' || c == '\t');
    if (c == '-') {
        isMinus = 1;
        c = getchar();
    }
    s[1] = '\0';
    // if (isMinus == 1) {
    //     s[1] = '-';
    // } 
    // s[0] = '-';
    if (!isdigit(c) && c != '.')
        if (isMinus == 1) {
            return '-';
        } 
        return c; /* не число */
    i = 0;
    // if (isMinus == 1) {
    //     s[++i] = c;
    // }
    if (isdigit(c)) /* накапливаем целую часть */
        while (isdigit(s[++i] = c = getchar())) {
            if (MAXOP < i + 1) {
                printf( "Error: reach the MAXOP\n");
                exit (1);
            } 
        }
    if (c == '.') /* накапливаем дробную часть */
        while (isdigit(s[++i] = c = getchar())) {
            if (MAXOP < i + 1) {
                printf( "Error: reach the MAXOP\n");
                exit (1);
            } 
        }
    s[i] = '\0';
    return NUMBER;
}

/* калькулятор с обратной польской записью */
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