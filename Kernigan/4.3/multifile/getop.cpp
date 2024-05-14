#include <stdio.h>
#include "stack.h"
#include <stdlib.h> /* для atof() */
#include <ctype.h>

char buf[BUFSIZE];
int bufp = 0;
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* getop: получает следующий оператор или операнд */
int getop(char s[]) {
    int i = 0, c, next;
    while ((s[i] = c = (getch())) == ' ' || c == '\t');
    if (!isdigit(c) && c != '.') {
        if (c == '-') {
            if (isdigit(next = getch()) ) {
                c = next;
                s[++i] = c;
            }
            else {
                ungetch(next);
                return c;  // не число 
            }
        }
        else {
            return c;      // не число 
        }
    }
    if (isdigit(c)) /* накапливаем целую часть /
        while (isdigit(s[++i] = c = getch()));
    if (c == '.')    / накапливаем дробную часть */
        while (isdigit(s[++i] = c = getch()));
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}