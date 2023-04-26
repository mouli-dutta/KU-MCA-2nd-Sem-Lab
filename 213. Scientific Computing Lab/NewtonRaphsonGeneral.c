#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define E 0.00001

typedef struct  Polynomial
{
    int degree;
    float coefficient;
} Poly;


// build polynomial equation
Poly* takeInput(int degree) {
    int size = degree + 1;

    Poly *eqn = malloc(sizeof(Poly)*size);

    while(degree != -1) {
        printf("\nEnter the coefficient of x^%d\n", degree);
        float coeff;
        scanf("%f", &coeff);

        Poly node;
        node.degree = degree;
        node.coefficient = coeff;

        eqn[size-degree-1] = node;

        --degree;
    }

    return eqn;

}

// differentiate given polynomial
Poly* derivative(Poly *eqn, int size) {
    Poly *diffArr = malloc(sizeof(Poly)*size);

    for(int i = 0; i < size; ++i) {
        Poly diff;
        diff.degree = eqn[i].degree - 1;
        diff.coefficient = eqn[i].coefficient * eqn[i].degree;

        diffArr[i] = diff;
    }
    return diffArr;
}

float fx(float x, Poly *eqn, int size) {
    float sum;
    for(int i = 0; i < size; i++) {
        sum += eqn[i].coefficient * pow(x, eqn[i].degree);
        
    }
    return sum;
}

float newton(float x, int size, Poly *eqn, Poly* diff) {
    float h = fx(x, eqn, size) / fx(x, diff, size-1);
    while(fabs(h) >= E) {
        h = h = fx(x, eqn, size) / fx(x, diff, size-1);
        x = x - h;
    }
    return x;

}

void printPoly(Poly *eqn, int size) {
    printf("\n\nYour equation: ");

    for(int i = 0; i < size; i++) {
        if(eqn[i].coefficient > 0)
            printf(" + %.1fx^%d ", eqn[i].coefficient, eqn[i].degree);
        else
            printf(" %.1fx^%d ", eqn[i].coefficient, eqn[i].degree);
    }

    printf("\n\n");
}


// given function
double f(double x) {
    return x*x + 5*x - 2;
}

// derivative of the function
double df(double x) {
    return 2*x + 5;
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


    printf("\n\nEnter the degree of the equation.\n");
    int degree;
    scanf("%d", &degree);
    int size = degree + 1;
    Poly *eqn = takeInput(degree);
    printPoly(eqn, size);

    Poly *diff = derivative(eqn, size);
    printPoly(diff, size-1);

    float x1 = 1;
    float root1 = newton(x1, size, eqn, diff);
    printf("The value of approximate root upto 5 decimal places is: %0.5f", root1);

    free(eqn);
    free(diff);

    return 0;
}
