#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    if (rows <= 0 || cols <= 0) {
        cout << "Invalid matrix dimensions!" << endl;
        return 1;
    }
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    cout << "\nEnter matrix elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    int nonZeroCount = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                nonZeroCount++;
            }
        }
    }
    if (nonZeroCount > 0) {
        int** compressed = new int*[nonZeroCount];
        for (int i = 0; i < nonZeroCount; i++) {
            compressed[i] = new int[3]; 
        }

        int index = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] != 0) {
                    compressed[index][0] = i;      
                    compressed[index][1] = j;      
                    compressed[index][2] = matrix[i][j]; 
                    index++;
                }
            }
        }

        cout << "Matrix n compressed form (Row, Column, Value)\n";
        cout << string(50, '=') << "\n";
        cout << "Row\tColumn\tValue\n";
        
        for (int i = 0; i < nonZeroCount; i++) {
            cout << compressed[i][0] << "\t" 
                 << compressed[i][1] << "\t" 
                 << compressed[i][2] << endl;
        }
        
        int originalSize = rows * cols;
        int compressedSize = nonZeroCount * 3;
        double compressionRatio = (1.0 - (double)compressedSize / originalSize) * 100;
        
        cout << "\nCompression Statistics:\n";
        cout << "Original size: " << originalSize << " elements\n";
        cout << "Compressed size: " << compressedSize << " elements (" << nonZeroCount << " triples)\n";
        cout << "Compression ratio: " << compressionRatio << "% space saved\n";
        cout << "Non-zero elements: " << nonZeroCount << " / " << originalSize << " (" 
             << (double)nonZeroCount / originalSize * 100 << "%)" << endl;
        
        for (int i = 0; i < nonZeroCount; i++) {
            delete[] compressed[i];
        }
        delete[] compressed;
    } else {
        cout << "\nThe matrix contains only zero elements (completely sparse)!\n";
        cout << "Compressed form would be empty.\n";
    }
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    
    return 0;
}
