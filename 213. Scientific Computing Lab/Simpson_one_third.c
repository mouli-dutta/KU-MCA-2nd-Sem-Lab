#include<stdio.h>
#include<math.h>

double f(double x) {
    return x * exp(2*x);
} 

void simpson(int n, double a, double b) {
    double h;
    double sum1 = 0, sum2 = 0, result;
    if(n%2==0) {
        h = (b-a)/n;
        for(int i = 1; i < n; i++) {
            if(i%2==0) {
                sum1 += f(a + i*h);
            
            } else {
                sum2 += f(a+i*h);
            }
        }
    
        result = (h/3) * (f(a) + f(b) + 2 * sum1 + 4 * sum2);

        printf("\n The result is: %f\n", result);

    } else {
        printf("\nNo. of intervals should be even.\n");
    }
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

    simpson(n, lower, upper);

    return 0;
}
