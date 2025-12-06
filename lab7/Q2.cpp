#include <iostream>
#include <string>
using namespace std;

class participant
{
public:
    string name;
    int time;

    participant(string n = "", int t = 0)
    {
        name = n;
        time = t;
    }
};
void merge_arr(participant arr[], int l, int m, int r)
{
    int i = l;
    int j = m + 1;
    int k = l;

    participant temp[10];
    while (i <= m && j <= r)
    {
        if (arr[i].time < arr[j].time)
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= m)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= r)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (int x = l; x <= r; x++)
    {
        arr[x] = temp[x];
    }
}
void mergesort(participant arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);

        merge_arr(arr, l, m, r);
    }
}

void display_top5(participant arr[], int size)
{
    cout << "Top 5 Fastest Runners:\n";
    for (int i = 0; i < 5 && i < size; i++)
    {
        cout << (i + 1) << ": " << arr[i].name << " " << arr[i].time << " seconds\n";
    }
}

int main()
{
    int size = 10;
    participant p[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter name of participant " << (i + 1) << ": ";
        cin >> p[i].name;

        cout << "Enter finish time for " << p[i].name << ": ";
        cin >> p[i].time;
    }
    mergesort(p, 0, size - 1);
    display_top5(p, size);

    return 0;
}
