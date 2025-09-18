#include <iostream>
using namespace std;

int linearSearch(int* arr, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1;
}

int main() {
    int size, target;
    cout << "Enter size of array: ";
    cin >> size;
    int* arr = new int[size];
    
    cout << "Enter " << size << " values:" << endl;
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    cout << "Enter the integer to search for: ";
    cin >> target;
    int result = linearSearch(arr, size, target);

    if (result != -1) {
        cout << "Integer " << target << " found at index: " << result ;
    } else {
        cout << "Integer " << target << " is not in the array." ;
    }
    delete[] arr;
    return 0;
}