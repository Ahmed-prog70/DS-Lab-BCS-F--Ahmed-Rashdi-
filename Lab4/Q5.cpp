#include<iostream>
using namespace std;

int interpolationSearch(int* arr, int size, int x) {
    int low = 0, high = size - 1;
    while (low <= high && x >= arr[low] && x <= arr[high]) {
        if (low == high) {
            if (arr[low] == x) {
                return low;
            } return -1;
        }
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]));
        
        if (pos < low || pos > high) 
            break;
        
        if (arr[pos] == x) 
            return pos; 
        
        else if (arr[pos] < x)  
         low = pos + 1; 
        
        else 
            high = pos - 1; 
         }
    return -1; 
}

int main(){
    int size, x;
    cout << "Enter size of array: ";
    cin >> size;
    int* arr = new int[size];
    
    cout << "Enter " << size << " sorted integers with uniform distribution:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    cout << "\nEnter integer to search: ";
    cin >> x;

    int result= interpolationSearch(arr, size,x);

    if (result != -1) {
        cout << "Integer " << x << " found at index: " << result ;
    } else {
        cout << "Integer " << x << " is not in the array." ;
    }
    delete[] arr;
    return 0;
}
