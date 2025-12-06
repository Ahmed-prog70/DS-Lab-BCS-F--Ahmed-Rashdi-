#include <iostream>
using namespace std;
void swapnum(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

int partitionfunc(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swapnum(arr[i], arr[j]);
        }
    }

    swapnum(arr[i + 1], arr[high]);
    return i + 1;
}

void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partitionfunc(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

int main()
{
    int arr[] = {10, 7, 8, 9, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: ";

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
    quicksort(arr, 0, n - 1);
    cout << "After sorting:  ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
    return 0;
}
