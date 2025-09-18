#include<iostream>
using namespace std;

void InsertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int binarySearch(int* arr, int size, int target) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid; 
        }
        else if (arr[mid] < target) {
            left = mid + 1; 
        }
        else {
            right = mid - 1; 
        }
    }
    
    return -1; 
}

void print(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }   
    cout<<endl;
}
    
int main(){
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    int* arr = new int[size];
    
    cout << "Enter " << size << " values:" << endl;
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    cout << "The unsorted Array:"<<endl;
    print(arr, size);

    InsertionSort(arr, size);
    cout << "The Sorted Array:"<<endl;
    print(arr, size);

    int target;
    cout << "\nEnter the integer to search: ";
    cin >> target;

    int result = binarySearch(arr, size, target);
    if (result != -1) {
        cout << "Integer " << target << " found at index " << result << endl;
    } else {
        cout << "Integer " << target << " is not in the array." << endl;
    }
    delete[] arr;
    return 0;
}