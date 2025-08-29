#include<iostream>
using namespace std;

void printArray(int **arr, int rows, int cols){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }
}

void updateArray(int **arr, int rows, int cols){
    int r, c;
    cout << "Enter the bench to fill: ";
    cin >> r;
    while (r<0 || r>= rows)
    {
        cout<<"Invalid bench"<< endl;
        cout << "Enter the bench: ";
        cin >> r;
    }
    cout << "Enter the seat number to fill: ";
    cin >> c;
      while (c<0 || c >= cols)
    {
        cout<<"Invalid seat"<<endl;
        cout << "Enter the seat number: ";
        cin >> c;
    }
    arr[r][c]= 1;
   
    
}

int main(){
    int rows, cols;
    cout << "Enter number of benches: ";
    cin >> rows;
        while (rows<=0)
    {
        cout<<"Invalid benches",,ENDL;
        cout << "Enter number of benches: ";
        cin >> rows;
    }
    cout << "Enter number of seats on each bench: ";
    cin >> cols;
       while (cols<=0)
    {
        cout<<"Invalid seats"<<ENDL;
        cout << "Enter number of seats on each bench: ";
        cin >> cols;
    }

    int **arr = new int*[rows];
    
    for(int i = 0; i< rows; i++){
        arr[i]= new int[cols];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j]=0;
        }
    }
    
    updateArray(arr, rows , cols);
    printArray(arr, rows, cols);

    return 0;

}
