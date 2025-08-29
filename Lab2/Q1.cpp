#include<iostream>
using namespace std;

void printArray(int *arr, int size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i];
    }
}

void updateArray(int *arr, int size){
    int index , val;
    cout << "Enter the index: ";
    cin>> index;
    if (index>=0 && index < size)
    {
        cout << "Enter the value: ";
        cin >> arr[index];
    }
    else {
        cout << "Incorrrect index";
    }
    
}

int main(){
    int size;
    cout<<"Enter size of array: ";
    cin >> size;
    
    while (size <=0)
    {
        cout << "Invalid size";
        cout<<"Enter size of array: ";
        cin >> size;
    }

    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = 0;
    }
    
    updateArray(arr, size);
    printArray(arr, size);
    
    delete[] arr;
    return 0;
}
