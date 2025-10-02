#include <iostream>
using namespace std;
const int SIZE = 9;

bool isValid(int grid[SIZE][SIZE], int row, int col, int num)
{
    for (int x = 0; x < SIZE; x++)
    {
        if (grid[row][x] == num) return false;
    }
    for (int x = 0; x < SIZE; x++)
    {
        if (grid[x][col] == num) return false;
    }
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[startRow + i][startCol + j] == num)  return false;
        }
    }

    return true;
}

bool solveSudoku(int grid[SIZE][SIZE])
{
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            if (grid[row][col] == 0)
            {
                for (int num = 1; num <= 9; num++)
                {
                    if (isValid(grid, row, col, num))
                    {
                        grid[row][col] = num;

                        if (solveSudoku(grid))
                            return true;
                        grid[row][col] = 0;
                    }
                }
                return false; /
            }
        }
    }
    return true; 
}

void printGrid(int grid[SIZE][SIZE])
{
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int grid[SIZE][SIZE] =
    {
        {0, 1, 0, 6, 0, 3, 0, 2, 0},
        {5, 8, 0, 0, 0, 9, 7, 0, 0},
        {0, 3, 0, 0, 4, 0, 0, 0, 0},
        {3, 7, 6, 0, 0, 0, 5, 0, 0},
        {6, 0, 9, 0, 0, 0, 0, 0, 4},
        {0, 0, 8, 0, 0, 0, 0, 1, 3},
        {0, 0, 0, 0, 9, 0, 0, 0, 0},
        {0, 0, 3, 8, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 5, 0, 9, 0}
    };

    cout << "Initial Sudoku Puzzle:\n";
    printGrid(grid);

    if (solveSudoku(grid))
    {
        cout << "\nSolved Sudoku Puzzle:\n";
        printGrid(grid);
    }
    else
    {
        cout << "No valid solution exists for this puzzle." << endl;
    }
    return 0;
}
