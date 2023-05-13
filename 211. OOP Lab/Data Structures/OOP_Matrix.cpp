#include <iostream>
#include <functional>

using namespace std;

class Matrix {
private:
    int row;
    int col;
    double **matrix;

public:
    Matrix(int row, int col);
    Matrix(const Matrix& copy);
    ~Matrix();

    void fill(function<double()> fillFunction);
    Matrix add(const Matrix &other);
    Matrix subtract(const Matrix& other);
    Matrix multiply(const Matrix& other);
    double determinant();
    Matrix inverse();
    Matrix transpose();
    void printMatrix();
};


double getUserInput() {
    cout << "Enter data: ";
    double data;
    cin >> data;
    return data;
}

Matrix init() {
    int row, col;
    cout << "Enter the rows and columns: \n";
    cin >> row >> col;

    Matrix matrix(row, col);
    cout << "Enter the elements (row-wise):\n";
    matrix.fill(getUserInput);
    return matrix;
}


int main() {
    cout << "Menu\n"
         << "Select an operation.\n"
         << "1. Add two matrices\n"
         << "2. Subtract two matrices.\n"
         << "3. Multiply two matrices.\n"
         << "4. Inverse of a matrix.\n"
         << "5. Determinant of a matrix\n"
         << "6. Exit.\n";

    while(1) {
        int choice;
        cout << "Enter your choice.\n";
        cin >> choice;

        switch (choice)
        {
        case 1: {
            cout << "Enter details for Matrix A:\n";
            Matrix A = init();
            A.printMatrix();

            cout << "Enter details for Matrix B:\n";
            Matrix B = init();
            B.printMatrix();

            cout << "A + B =\n"; 
            A.add(B).printMatrix();

            break;
        }
        case 2:{
            cout << "Enter details for Matrix A:\n";
            Matrix A = init();
            A.printMatrix();

            cout << "Enter details for Matrix B:\n";
            Matrix B = init();
            B.printMatrix();

            cout << "A - B =\n";
            A.subtract(B).printMatrix();

            break;
        }
        case 3:{
            cout << "Enter details for Matrix A:\n";
            Matrix A = init();
            A.printMatrix();

            cout << "Enter details for Matrix B:\n";
            Matrix B = init();
            B.printMatrix();

            cout << "A x B =\n";
            A.multiply(B).printMatrix();

            break;
        }
        case 4:{
            cout << "Enter details for Matrix A:\n";
            Matrix A = init();
            A.printMatrix();

            cout << "Inverse of the matrix is:\n";
            A.inverse().printMatrix();

            break;
        }
        case 5:{
            cout << "Enter details for Matrix A:\n";
            Matrix A = init();
            A.printMatrix();

            cout << "Determinant of the matrix is:\n" 
                 << A.determinant() << "\n";

            break;
        }
        case 6:
            cout << "Terminating the program\n";
            exit(0);
            break;   
        
        default:
            cout << "Invalid choice.\n";
            break;
        }
    }

    return 0;
}




// Implementation of Matrix class

Matrix::Matrix(int row, int col) : row(row), col(col)
{
    // Allocate memory for the matrix
    matrix = new double*[row];
    for (int i = 0; i < row; ++i) {
        matrix[i] = new double[col]();
    }
}

Matrix::Matrix(const Matrix& copy) : row(copy.row), col(copy.col)
{
    matrix = new double*[row];
    for (int i = 0; i < row; ++i) {
        matrix[i] = new double[col];
        for (int j = 0; j < col; ++j) {
            matrix[i][j] = copy.matrix[i][j];
        }
    }
}

Matrix::~Matrix()
{
    // Deallocate memory for the matrix
    for (int i = 0; i < row; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void Matrix::fill(function<double()> fillFunction)
{
    // fill the matrix according to the logic of the 
    // provided fillFunction
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            matrix[i][j] = fillFunction();
        }
    }
}

Matrix Matrix::add(const Matrix& other)
{
    if((row != other.row) || (col != other.col)) {
        cout << "Matrix addition is not possible.\n"
             << "Row and columns of both matrices must be same.\n";
        return Matrix(0, 0);
    }

    else {
        Matrix res(other);

        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                res.matrix[i][j] += matrix[i][j];
            }
        }

        return res;
    }
}

Matrix Matrix::subtract(const Matrix& other)
{
    if((row != other.row) || (col != other.col)) {
        cout << "Matrix subtraction is not possible.\n"
             << "Row and columns of both matrices must be same.\n";
        return Matrix(0, 0);
    }

    else {
        Matrix res(other);

        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                res.matrix[i][j] -= matrix[i][j];
            }
        }

        return res;
    }
}

Matrix Matrix::multiply(const Matrix& other)
{
    if(other.row != col) {
        cout << "Matrix multiplication is not possible.\n"
             << "Column of the first matrix must be equal to row of the second matrix.\n";
        return Matrix(0, 0);
    }

    else {
        Matrix res(row, other.col);

        for(int i = 0; i < res.row; ++i) {
            for(int j = 0; j < res.col; ++j) {
                for(int k = 0; k < col; ++k) {
                    res.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
                }
            }
        }

        return res;
    }
}

double Matrix::determinant()
{
    if(row != col) {
        cout << "Can't calculate the determinant because the matrix is not square.\n";
        return 0.0;
    }

    if(row == 1) {
        return matrix[0][0];

    } else if (row == 2) {
        return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);

    } else {
        double det = 0.0;
        for(int j = 0; j < col; ++j) {
            Matrix submatrix(row-1, col-1);

            for(int i = 1; i < row; ++i) {
                int k = 0;
                for(int l = 0; l < col; ++l) {
                    if(l != j) {
                        submatrix.matrix[i-1][k] = matrix[i][l];
                        k++;
                    }
                }
            }

            double cofactor = (j%2 == 0) ? matrix[0][j] : -matrix[0][j];
            det += cofactor * submatrix.determinant();
        }

        return det;
    }
}

Matrix Matrix::inverse()
{
    if (row != col) {
        cout << "Matrix is not square. Inverse does not exist.\n";
        return Matrix(0, 0);
    }

    // augmented matrix [A | I] where A is the original matrix and I is the identity matrix
    Matrix augmented(row, col * 2);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            augmented.matrix[i][j] = matrix[i][j];
            augmented.matrix[i][j + col] = (i == j) ? 1.0 : 0.0;
        }
    }

    // Apply Gauss-Jordan elimination to transform the augmented matrix into [I | A^-1]
    for (int i = 0; i < row; ++i) {
        // Find the pivot element
        double pivot = augmented.matrix[i][i];
        if (pivot == 0.0) {
            cout << "Matrix is not invertible.";
            return Matrix(0, 0);
        }

        // Scale the pivot row to make the pivot element 1
        for (int j = 0; j < col * 2; ++j) {
            augmented.matrix[i][j] /= pivot;
        }

        // Eliminate other rows
        for (int k = 0; k < row; ++k) {
            if (k != i) {
                double factor = augmented.matrix[k][i];
                for (int j = 0; j < col * 2; j++) {
                    augmented.matrix[k][j] -= factor * augmented.matrix[i][j];
                }
            }
        }
    }

    // Extract the inverse matrix from the augmented matrix
    Matrix inverse(row, col);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            inverse.matrix[i][j] = augmented.matrix[i][j + col];
        }
    }

    return inverse;
}

Matrix Matrix::transpose()
{
    Matrix t(col, row);
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            t.matrix[j][i] = matrix[i][j];
        }
    }
    return t;
}

void Matrix::printMatrix()
{
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            cout << matrix[i][j] << "    ";
        }
        cout << "\n";
    }
    cout << "\n";
}

