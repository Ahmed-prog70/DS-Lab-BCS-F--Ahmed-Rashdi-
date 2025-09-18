#include<iostream>
using namespace std;

void BubbleSort(int arr[], int size){
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size -i - 1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
            
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

    BubbleSort(arr,size);
    cout << "The Sorted Array:"<<endl;
    print(arr, size);
    
    delete[] arr;
    return 0;

}