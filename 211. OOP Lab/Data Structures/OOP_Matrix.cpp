#include <iostream>
#include <functional>

using namespace std;

class Matrix {
private:
    int rows;
    int cols;
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
    void display();
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
            A.display();

            cout << "Enter details for Matrix B:\n";
            Matrix B = init();
            B.display();

            cout << "A + B =\n"; 
            A.add(B).display();

            break;
        }
        case 2:{
            cout << "Enter details for Matrix A:\n";
            Matrix A = init();
            A.display();

            cout << "Enter details for Matrix B:\n";
            Matrix B = init();
            B.display();

            cout << "A - B =\n";
            A.subtract(B).display();

            break;
        }
        case 3:{
            cout << "Enter details for Matrix A:\n";
            Matrix A = init();
            A.display();

            cout << "Enter details for Matrix B:\n";
            Matrix B = init();
            B.display();

            cout << "A x B =\n";
            A.multiply(B).display();

            break;
        }
        case 4:{
            cout << "Enter details for Matrix A:\n";
            Matrix A = init();
            A.display();

            cout << "Inverse of the matrix is:\n";
            A.inverse().display();

            break;
        }
        case 5:{
            cout << "Enter details for Matrix A:\n";
            Matrix A = init();
            A.display();

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

Matrix::Matrix(int row, int col) : rows(row), cols(col)
{
    // Allocate memory for the matrix
    matrix = new double*[row];
    for (int i = 0; i < row; ++i) {
        matrix[i] = new double[col]();
    }
}

Matrix::Matrix(const Matrix& copy) : rows(copy.rows), cols(copy.cols)
{
    matrix = new double*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new double[cols];
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = copy.matrix[i][j];
        }
    }
}

Matrix::~Matrix()
{
    // Deallocate memory for the matrix
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void Matrix::fill(function<double()> fillFunction)
{
    // fill the matrix according to the logic of the 
    // provided fillFunction
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            matrix[i][j] = fillFunction();
        }
    }
}

Matrix Matrix::add(const Matrix& other)
{
    if((rows != other.rows) || (cols != other.cols)) {
        cout << "Matrix addition is not possible.\n"
             << "Row and columns of both matrices must be same.\n";
        return Matrix(0, 0);
    }

    else {
        Matrix res(other);

        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                res.matrix[i][j] += matrix[i][j];
            }
        }

        return res;
    }
}

Matrix Matrix::subtract(const Matrix& other)
{
    if((rows != other.rows) || (cols != other.cols)) {
        cout << "Matrix subtraction is not possible.\n"
             << "Row and columns of both matrices must be same.\n";
        return Matrix(0, 0);
    }

    else {
        Matrix res(other);

        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                res.matrix[i][j] -= matrix[i][j];
            }
        }

        return res;
    }
}

Matrix Matrix::multiply(const Matrix& other)
{
    if(other.rows != cols) {
        cout << "Matrix multiplication is not possible.\n"
             << "Column of the first matrix must be equal to row of the second matrix.\n";
        return Matrix(0, 0);
    }

    else {
        Matrix res(rows, other.cols);

        for(int i = 0; i < res.rows; ++i) {
            for(int j = 0; j < res.cols; ++j) {
                for(int k = 0; k < cols; ++k) {
                    res.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
                }
            }
        }

        return res;
    }
}

double Matrix::determinant()
{
    if(rows != cols) {
        cout << "Can't calculate the determinant because the matrix is not square.\n";
        return 0.0;
    }

    if(rows == 1) {
        return matrix[0][0];

    } else if (rows == 2) {
        return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);

    } else {
        double det = 0.0;
        for(int j = 0; j < cols; ++j) {
            Matrix submatrix(rows-1, cols-1);

            for(int i = 1; i < rows; ++i) {
                int k = 0;
                for(int l = 0; l < cols; ++l) {
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
    if (rows != cols) {
        cout << "Matrix is not square. Inverse does not exist.\n";
        return Matrix(0, 0);
    }

    // augmented matrix [A | I] where A is the original matrix and I is the identity matrix
    Matrix augmented(rows, cols * 2);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            augmented.matrix[i][j] = matrix[i][j];
            augmented.matrix[i][j + cols] = (i == j) ? 1.0 : 0.0;
        }
    }

    // Apply Gauss-Jordan elimination to transform the augmented matrix into [I | A^-1]
    for (int i = 0; i < rows; ++i) {
        // Find the pivot element
        double pivot = augmented.matrix[i][i];
        if (pivot == 0.0) {
            cout << "Matrix is not invertible.";
            return Matrix(0, 0);
        }

        // Scale the pivot row to make the pivot element 1
        for (int j = 0; j < cols * 2; ++j) {
            augmented.matrix[i][j] /= pivot;
        }

        // Eliminate other rows
        for (int k = 0; k < rows; ++k) {
            if (k != i) {
                double factor = augmented.matrix[k][i];
                for (int j = 0; j < cols * 2; j++) {
                    augmented.matrix[k][j] -= factor * augmented.matrix[i][j];
                }
            }
        }
    }

    // Extract the inverse matrix from the augmented matrix
    Matrix inverse(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            inverse.matrix[i][j] = augmented.matrix[i][j + cols];
        }
    }

    return inverse;
}

Matrix Matrix::transpose()
{
    Matrix t(cols, rows);
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            t.matrix[j][i] = matrix[i][j];
        }
    }
    return t;
}

void Matrix::display()
{
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << "    ";
        }
        cout << "\n";
    }
    cout << "\n";
}

