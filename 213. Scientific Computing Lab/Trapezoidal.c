#include<stdio.h>
#include<math.h>

double f(double x) {
    return x * exp(2*x);
} 

void trapezoidal(int n, double a, double b) {
    double h = (b-a)/n;
    double sum = 0, result;

    for(int i = 1; i < n; i++) {
        sum += f(a+i*h);
    }

    result = (h/2) * (f(a) + f(b) + 2 * sum);
    printf("\n The result is: %f\n", result);
}
int main() {
    int n;
    double lower, upper;
    printf("Enter the number of interval.\n");
    scanf("%d", &n);

    printf("Enter the lower limit.\n");
    scanf("%lf", &lower);

    printf("Enter the upper limit.\n");
    scanf("%lf", &upper);

    trapezoidal(n, lower, upper);
    return 0;
}
