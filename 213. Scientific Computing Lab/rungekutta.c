#include <stdio.h>

// A sample differential equation
float dydx(float x, float y) { return -(x*y); }

// Finds value of y for a given x
// using step size h
// and initial value y0 at x0.
float rungeKutta(float x0, float y0, float x, float h)
{
	// Count number of iterations
	// using step size or
	// step height h
	int n = (int)((x - x0) / h);

	float k1, k2;

	// Iterate for number of iterations
	float y = y0;
	for (int i = 1; i <= n; i++) {
		// Apply Runge Kutta Formulas
		// to find next value of y
		k1 = h * dydx(x0, y);
		k2 = h * dydx(x0 + 0.5 * h, y + 0.5 * k1);

		// Update next value of y
		y = y + (1.0 / 6.0) * (k1 + 2 * k2);

		// Update next value of x
		x0 = x0 + h;
	}
	return y;
}

// Driver Code
int main()
{
	float x0, y0, x, h;
	printf("Enter the value of x0.\n");
scanf("%f", &x0);
printf("Enter the value of y0.\n");
scanf("%f", &y0);
printf("Enter the value of x.\n");
scanf("%f", &x);
printf("Enter the value of h.\n");
scanf("%f", &h);

	printf("\nThe value of y at x is : %f\n",  rungeKutta(x0, y0, x, h));
	return 0;
}
