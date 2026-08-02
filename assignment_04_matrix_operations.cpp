// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
void readMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// ------------------------------------------------------------
// Function to display a matrix in a neat, aligned grid
// ------------------------------------------------------------
void displayMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(6) << matrix[i][j];
        }
        cout << "\n";
    }
}

// ------------------------------------------------------------
// PART A - Transpose a Matrix
// ------------------------------------------------------------
void transposeMatrix() {
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int matrix[10][10];
    int result[10][10];

    readMatrix(matrix, rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }

    cout << "\nOriginal Matrix:\n";
    displayMatrix(matrix, rows, cols);

    cout << "\nTransposed Matrix:\n";
    displayMatrix(result, cols, rows);
}

// ------------------------------------------------------------
// PART B - Add Two Matrices
// ------------------------------------------------------------
void addMatrices() {
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int matrixA[10][10];
    int matrixB[10][10];
    int result[10][10];

    cout << "\nEnter values for Matrix A:\n";
    readMatrix(matrixA, rows, cols);

    cout << "\nEnter values for Matrix B:\n";
    readMatrix(matrixB, rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    cout << "\nSum of Matrix A and Matrix B:\n";
    displayMatrix(result, rows, cols);
}

// ------------------------------------------------------------
// PART C - Multiply Two Matrices
// ------------------------------------------------------------
void multiplyMatrices() {
    int rowsA, colsA, rowsB, colsB;

    cout << "Enter rows of Matrix A: ";
    cin >> rowsA;
    cout << "Enter columns of Matrix A: ";
    cin >> colsA;

    cout << "Enter rows of Matrix B: ";
    cin >> rowsB;
    cout << "Enter columns of Matrix B: ";
    cin >> colsB;

    if (colsA != rowsB) {
        cout << "Error: Number of columns in A must equal number of rows in B.\n";
        return;
    }

    int matrixA[10][10];
    int matrixB[10][10];
    int result[10][10];

    cout << "\nEnter values for Matrix A:\n";
    readMatrix(matrixA, rowsA, colsA);

    cout << "\nEnter values for Matrix B:\n";
    readMatrix(matrixB, rowsB, colsB);

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    cout << "\nProduct of Matrix A and Matrix B:\n";
    displayMatrix(result, rowsA, colsB);
}

// ------------------------------------------------------------
// Main menu loop
// ------------------------------------------------------------
int main() {
    int choice;

    do {
        cout << "\n====================================\n";
        cout << "   MATRIX OPERATIONS MENU\n";
        cout << "====================================\n";
        cout << "1. Transpose a Matrix\n";
        cout << "2. Add Two Matrices\n";
        cout << "3. Multiply Two Matrices\n";
        cout << "4. Quit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                transposeMatrix();
                break;
            case 2:
                addMatrices();
                break;
            case 3:
                multiplyMatrices();
                break;
            case 4:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }

    } while (choice != 4);

    return 0;
}

