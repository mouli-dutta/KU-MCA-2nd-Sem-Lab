#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_SIZE = 10;

class Matrix {
private:
    int rows, cols;
    double matrix[MAX_SIZE][MAX_SIZE];

public:
    void readRow();
    void readCol();
    void readMatrix();
    void display();
    friend Matrix add(const Matrix A, const Matrix B);
    friend Matrix subtract(const Matrix A, const Matrix B);
    friend Matrix multiply(const Matrix A, const Matrix B);

};


int main() {
    Matrix A, B, result;
    
    cout << "Matrix1:\n";
    A.readRow();
    A.readCol();
    A.readMatrix();
    A.display();

    cout << "\nMatrix2:\n";
    B.readRow();
    B.readCol();
    B.readMatrix();
    B.display();

    cout << "\nMenu\n"
         << "Select an operation.\n"
         << "1. Add two matrices\n"
         << "2. Subtract two matrices.\n"
         << "3. Multiply two matrices.\n"
         << "4. Exit.\n";

    while(1) {
        int choice;
        cout << "Enter your choice.\n";
        cin >> choice;

        switch (choice)
        {
        case 1: {
            cout << "A + B =\n"; 
            result = add(A, B);
            result.display();
            break;
        }
        case 2:{
            cout << "A - B =\n";
            result = subtract(A, B);
            result.display();
            break;
        }
        case 3:{
            cout << "A x B =\n";
            result = multiply(A, B);
            result.display();
            break;
        }
        case 4:
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

void Matrix::readRow()
{
    cout << "Enter the number of rows: ";
    cin >> this->rows;
}

void Matrix::readCol() 
{
    cout << "Enter the number of columns: ";
    cin >> this->cols;
}

void Matrix::readMatrix()
{
    cout << "Enter the matrix elements:\n";
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            cout << "Element [" << i << "," << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void Matrix::display()
{
    cout << "Matrix:\n";
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            cout << setw(4) << matrix[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}


Matrix add(const Matrix A, const Matrix B)
{
    if((A.rows != B.rows) || (A.cols != B.cols)) {
        cout << "Dimension mismatch.\nMatrix addition is not possible.\n";
        return A;
    }

    Matrix result;
    result.rows = A.rows;
    result.cols = B.cols;

    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < B.cols; j++) {
            result.matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
        }
    }

    return result;
}

Matrix subtract(const Matrix A, const Matrix B)
{
    if((A.rows != B.rows) || (A.cols != B.cols)) {
        cout << "Dimension mismatch.\nMatrix subtraction is not possible.\n";
        return A;
    }

    Matrix result;
    result.rows = A.rows;
    result.cols = A.cols;

    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < A.cols; j++) {
            result.matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
        }
    }

    return result;

}

Matrix multiply(const Matrix A, const Matrix B)
{
    if(B.rows != A.cols) {
        cout << "Dimension mismatch.\nMatrix addition is not possible.\n";
        return A;
    }

    Matrix result;
    result.rows = A.rows;
    result.cols = B.cols;

    for (int i = 0; i < A.rows; i++) {
        for (int j = 0; j < B.cols; j++) {
            result.matrix[i][j] = 0;
            for (int k = 0; k < A.cols; k++) {
                result.matrix[i][j] += A.matrix[i][k] * B.matrix[k][j];
            }
        }
    }

    return result;
}
