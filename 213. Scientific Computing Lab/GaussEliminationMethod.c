#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// takes a double value as input from the user
double getInput() {
    printf("Enter data: ");
    double input;
    scanf("%lf", &input);
    return input;
}

// fills the given matrix
// requires external fill function pointer
void fillMatrix(int size, double matrix[][size], double (*fillFunction)()) {
    for(int i = 0; i < size; i++) 
        for(int j = 0; j < size; j++)
            matrix[i][j] = fillFunction();
}

// fills the given vector
// requires external fill function pointer
void fillVecotr(int size, double vector[size], double (*fillFunction)()) {
    for(int i = 0; i < size; i++) 
        vector[i] = fillFunction();
}

// output the matrix in formatted form
void printMatrix(int size, double matrix[][size]) {
    for(int i = 0; i < size; i++) {
        putc('|', stdout);
        for(int j = 0; j < size; j++)
            printf(" %.2lf ", matrix[i][j]);
        puts("|");
    }
}

// output the vector in formatted form
void printVector(int size, double vector[size]) {
    putc('|', stdout);
    for(int i = 0; i < size; i++) 
        printf(" %.2lf ", vector[i]);
    puts("|");
}

// function for backward substitution
double* backwardSubstitute(int size, double matrix[][size], double vector[size]) {
    double *solutionVector = malloc(size * sizeof(double));
    for(int i = size-1; i >= 0; i--) {
        double sum = 0.0;
        for(int j = i+1; j < size; j++) {
            sum += matrix[i][j] * solutionVector[j];
        }
        solutionVector[i] = (vector[i]-sum) / matrix[i][i];
    }
    return solutionVector;
}

// Gauss Elimination method
void solve(int size, double matrix[][size], double vector[size]) {
    
    for(int i = 0; i < size; i++) {
        int maxRow = i;
        double maxElement = matrix[maxRow][i];

        // loop for finding the max row
        for(int j = i+1; j < size; j++) {
            double currentElement = matrix[j][i];
            if(fabs(currentElement) > fabs(maxElement))
                maxRow = j;
        }

        // swap current row with max row
        for (int j = i; j < size; j++) {
            double tmp = matrix[maxRow][j];
            matrix[maxRow][j] = matrix[i][j];
            matrix[i][j] = tmp;
        }

        //printMatrix(size, matrix);

        // swap vecotr row with the max row
        double v = vector[i];
        vector[i] = vector[maxRow];
        vector[maxRow] = v;

        //printVector(size, vector);

        // No solution when matrix is singular
        if(fabs(matrix[i][i]) <= 0.00001) {
            printf("No solution because Matrix is Singular.\n");
            exit(1);
        }

        // loop for generating the upper triangular matrix
        for (int j = i + 1; j < size; j++) {
            // pivoting start
            double alpha = matrix[j][i] / matrix[i][i];
            vector[j] -= alpha * vector[i];

            for (int k = i; k < size; k++) {
                matrix[j][k] -= alpha * matrix[i][k];
            }
            // pivoting end
        }
    }

    //printMatrix(size, matrix);

    // backward substitution
    double *solutionVector = backwardSubstitute(size, matrix, vector);

    // print solution
    printVector(size, solutionVector);

    // free up space
    free(solutionVector);
}


// driver (main) function
int main() {
    printf("Enter the size: ");
    int size;
    scanf("%d", &size);

    double matrix[size][size];
    double vector[size];

    double getInput(); // function pointer

    puts("\nEnter data to fill matrix:");
    fillMatrix(size, matrix, getInput);
    printMatrix(size, matrix);

    puts("\nEnter data to fill vector:");
    fillVecotr(size, vector, getInput);
    printVector(size, vector);

    puts("\nSolution vectors is: ");
    solve(size, matrix, vector);

    return 0;
}