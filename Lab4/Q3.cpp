#include<iostream>
using namespace std;

void SelectionSort(int arr[], int size){
    int smallest;
    for (int i = 0; i < size -1; i++)
    {
        smallest = i;
        for (int k = i + 1; k < size; k++)
        {
            if (arr[k]< arr[smallest])
            {
                smallest = k;
            }
        }
        if (smallest!=i){
            int temp = arr[smallest];
                arr[smallest] = arr[i];
                arr[i] = temp;
        }
    }
    
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

    SelectionSort(arr, size);
    cout << "The Sorted Array:"<<endl;
    print(arr, size);
    
    delete[] arr;
    return 0;

}