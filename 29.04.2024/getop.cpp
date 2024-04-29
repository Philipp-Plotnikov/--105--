#include <stdio.h>
#include <ctype.h>
#include "calc.hpp"

int getop(char s[]) {
    int i = 0, c, next;
    while ((s[i] = c = getch()) == ' ' || c == '\t');
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
    if (isdigit(c)) /* накапливаем целую часть */
        while (isdigit(s[++i] = c = getch()));
    if (c == '.')    /* накапливаем дробную часть */
        while (isdigit(s[++i] = c = getch()));
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}