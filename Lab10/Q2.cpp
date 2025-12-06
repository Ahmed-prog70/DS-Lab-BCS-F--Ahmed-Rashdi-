#include <iostream>
using namespace std;

int left(int i) {
    return 2 * i + 1;
}

int right(int i) {
    return 2 * i + 2;
}

bool checkmaxheap(int* arr, int size) {

    for (int i = 0; i < size / 2; i++) {

        int p = arr[i];
        int l = left(i);
        int r = right(i);

        if (l < size && p < arr[l]) 
            return false;

        if (r < size && p < arr[r]) 
            return false;
    }

    return true;
}

int main() {

    int arr[] = {8, 7, 5, 4, 6};

    if (checkmaxheap(arr, 5))
        cout << "it is heap";
    else
        cout << "it is not a heap";

    return 0;
}
