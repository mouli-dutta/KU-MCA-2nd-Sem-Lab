#include <stdio.h>
#include <math.h>

#define E 0.00001

// given function
double f(double x) {
    return x*x*x - cos(x);
}

// derivative of the function
double df(double x) {
    return 3*x*x + sin(x);
}

double newton_raphson(double x) {
    double h = f(x) / df(x);
    while(fabs(h) >= E) {
        h = f(x) / df(x);
        x = x - h;
    }
    return x;
}

int main() {
    double x = 1;
    double root = newton_raphson(x);
    printf("The value of approximate root upto 5 decimal places is: %0.5lf", root);
    printf("\nValue of the function at root %lf", f(root));
    return 0;
}