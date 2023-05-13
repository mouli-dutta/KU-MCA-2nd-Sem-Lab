#include <stdio.h>
#include <math.h>

double f(double x) {
    // Define the function whose roots we want to find
    return x*x - 3*x - 10;
}

double regular_falsi(double a, double b, double tol) {
    // Implements the Regular Falsi method to find a root of f(x) between a and b
    // tol is the tolerance (i.e. the desired accuracy)

    double fa = f(a);
    double fb = f(b);
    double c, fc;
    int iter = 0;

    do {
        // Calculate the next approximation of the root
        c = a - fa * (b - a) / (fb - fa);
        fc = f(c);

        // Check if we have found a root
        if (fabs(fc) < tol) {
            printf("Root found at x = %f\n", c);
            return c;
        }

        // Update the interval [a, b]
        if (fc * fa < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }

        iter++;
    } while (iter < 100000); // set a very large number of iterations as a fallback

    printf("Regular Falsi method failed to converge within the maximum number of iterations\n");
    return NAN;
}

int main() {
    double a = 1.0;
    double b = 3.0;
    double tol = 1e-6;

    regular_falsi(a, b, tol);

    return 0;
}
