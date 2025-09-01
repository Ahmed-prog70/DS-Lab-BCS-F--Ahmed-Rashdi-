#include <iostream>
using namespace std;

int** createMatrix(int rows, int cols) {
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

void deleteMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void inputMatrix(int** matrix, int rows, int cols, string name) {
    cout << "Enter elements for matrix " << name << ":\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << name << "[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(int** matrix, int rows, int cols, string name) {
    cout << "\nMatrix " << name << ":\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int** addMatrices(int** matrixA, int** matrixB, int rows, int cols) {
    int** result = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    return result;
}

int** subtractMatrices(int** matrixA, int** matrixB, int rows, int cols) {
    int** result = createMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
    return result;
}

int main() {
    int rows, cols;
    
    cout << "Enter no of rows: ";
    cin >> rows;
    cout << "Enter no of columns: ";
    cin >> cols;
    
    if (rows <= 0 || cols <= 0) {
        cout << "Invalid input\n";
        return 1;
    }
    
    int** matrixA = createMatrix(rows, cols);
    int** matrixB = createMatrix(rows, cols); 
    inputMatrix(matrixA, rows, cols, "A");
    inputMatrix(matrixB, rows, cols, "B");
    
    displayMatrix(matrixA, rows, cols, "A");
    displayMatrix(matrixB, rows, cols, "B");
    
    int** sum = addMatrices(matrixA, matrixB, rows, cols);
    displayMatrix(sum, rows, cols, "A + B");
    int** difference = subtractMatrices(matrixA, matrixB, rows, cols);
    displayMatrix(difference, rows, cols, "A - B");
    
    deleteMatrix(matrixA, rows);
    deleteMatrix(matrixB, rows);
    deleteMatrix(sum, rows);
    deleteMatrix(difference, rows);
    return 0;
}
