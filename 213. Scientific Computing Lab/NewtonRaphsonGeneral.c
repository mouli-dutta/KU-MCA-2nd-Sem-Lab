#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define E 0.00001

typedef struct  Polynomial
{
    int degree;
    float coefficient;
    struct Polynomial *next;
} Poly;

Poly *newNode(int degree, float coeff) {
    Poly *new_poly = malloc(sizeof(Poly));
    new_poly->degree = degree;
    new_poly->coefficient = coeff;
    new_poly->next = NULL;
    return new_poly;
}

void insert(Poly **head, int degree, float coeff) {
    Poly *new_poly = newNode(degree, coeff);
    if (!head || !(*head))
    {
        *head = new_poly;
    }
    else {
        new_poly->next = *head;
        *head = new_poly;
    }
}

// build polynomial equation
Poly* takeInput(int degree) {
    int size = degree + 1;

    Poly *eqn = NULL;

    for(int i = 0; i < degree+1; i++) {
        printf("\nEnter the coefficient of x^%d\n", i);
        float coeff;
        scanf("%f", &coeff);
        insert(&eqn, i, coeff);
    }

    return eqn;

}

// differentiate given polynomial
Poly* derivative(Poly *eqn) {
    Poly *diff = NULL;

    while(eqn) {
        if (eqn->degree > 0)
            insert(&diff, eqn->degree - 1, eqn->coefficient * eqn->degree);

        eqn = eqn->next;
    }

    return diff;
}

// sum the polynomial with given x value
float fx(float x, Poly *eqn) {
    float sum = 0.0;

    while(eqn) {
        sum += eqn->coefficient * pow(x, eqn->degree);
        eqn = eqn->next;
    }

    return sum;
}

float newton_raphson(float x, Poly *eqn, Poly* diff) {
    float h = fx(x, eqn) / fx(x, diff);

    printf("\n\tx\t|\tf(x)\t|\tf`(x)\t|\th");

    while(fabs(h) >= E) {

        printf("\n\t%.5f\t|\t%.5f\t|\t%.5f\t|\t%.5f\t", x, fx(x, eqn), fx(x, diff), h);

        h = fx(x, eqn) / fx(x, diff);
        x = x - h;
    }

    printf("\n\n");

    return x;

}

void printPoly(Poly *eqn) {
    printf("\nYour equation: ");

    while(eqn) {
        if (eqn->coefficient > 0)
        {
            printf(" + %.1fx^%d ", eqn->coefficient, eqn->degree);
        } else {
            printf(" %.1fx^%d ", eqn->coefficient, eqn->degree);
        }
        eqn = eqn->next;
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

double newton(double x) {
    double h = f(x) / df(x);

    printf("\n\tx\t|\tf(x)\t|\tf`(x)\t|\th");

    while(fabs(h) >= E) {
        printf("\n\t%.5lf\t|\t%.5lf\t|\t%.5lf\t|\t%.5lf\t", x, f(x), df(x), h);

        h = f(x) / df(x);
        x = x - h;
    }

    printf("\n\n");

    return x;
}

int main() {
    double x = 1;
    double root = newton(x);
    printf("The value of approximate root upto 5 decimal places is: %0.5lf", root);
    printf("\nValue of the function at root %lf", f(root));


    printf("\n\nEnter the degree of the equation.\n");
    int degree;
    scanf("%d", &degree);
    Poly *eqn = takeInput(degree);
    printPoly(eqn);

    Poly *diff = derivative(eqn);
    printPoly(diff);

    float x1 = 1;
    float root1 = newton_raphson(x1, eqn, diff);
    printf("The value of approximate root upto 5 decimal places is: %0.5f", root1);

    free(eqn);
    free(diff);

    return 0;
}
