#include <stdio.h>
#include <math.h>

#define E 0.00001

float f(float x) {
    return x*x*x - 4*x - 9;
}

float bisection(float a, float b) {
    if(f(a) * f(b) < 0) {
        float mid = a;
        while(fabs(b-a) >= E) {
            mid = (a+b)/2;
            if(f(mid) == 0) return mid;
            else if(f(a) * f(mid) < 0) b = mid;
            else a = mid;
        }
        return mid;

    } else {
        printf("Invalid initial guess.\n");
        return -1.0;
    }
}

int main()
{
    float a, b;
    printf("Enter the value of a (lower bound)\n");
    scanf("%f", &a);

    printf("Enter the value of b (upper bound)\n");
    scanf("%f", &b);

    float root = bisection(a, b);
    printf("Root = %.5f\n", root);
    printf("Value of the function at root is %.5f\n", f(root));

    return 0;
}