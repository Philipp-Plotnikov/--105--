#include <stdio.h>
#include <stack>
#include "calc.hpp"

#define MAXVAL 100

std::stack<double> st;

void push_stack(double f)
{
    if (st.size() < MAXVAL)
        st.push(f);
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop_stack(void)
{
    if (st.size() > 0) {
        double t = st.top();
        st.pop();
        return t;
    }
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}