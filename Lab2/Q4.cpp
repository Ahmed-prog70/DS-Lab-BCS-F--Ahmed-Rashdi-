#include <iostream>
using namespace std;

void expenses(double *arr, int n);
double *resizeArr(double *arr, int n, int moreMonths);
void totalAndAvg(double *arr, int n);

int main()
{
    int months;
    while (true)
    {
        cout << "Enter no of months: ";
        cin >> months;

        if (months > 0)
            break;
        cout << "Invalid input" << endl;
    }

      cout << endl;
    double *arr = new double[months];
    expenses(arr, months);
    while (true)
    {
       char choice;
        int moreMonths;
        cout << "Add more monthly expenses (Y/N)? ";
        cin >> choice;

         if (choice == 'N' || choice == 'n')
            break;

        while (true)
        {
            cout << "Enter no of months to add: ";
            cin >> moreMonths;

            if (moreMonths > 0)
                break;
            cout << "Invalid input" << endl;
        }

    arr = resizeArr(arr, months, moreMonths);
        months += moreMonths;
    }

     totalAndAvg(arr, months);
     delete[] arr;
    return 0;
}

void expenses(double *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
  while (true)
      {
             cout << "Enter expenses for month " << (i + 1)<<": ";
            cin >> arr[i];

            if (arr[i] >= 0.0)
                break;
            cout << "Invalid input" << endl;
        }
        cout << endl;
    }
}

double *resizeArr(double *arr, int n, int moreMonths)
{
    double *newArr = new double[n + moreMonths];
    for (int i = 0; i < n; i++)
        newArr[i] = arr[i];

    for (int i = n; i < (n + moreMonths); i++)
    {
        while (true)
        {
            cout << "Enter expenses for month " << (i + 1) << ": ";
            cin >> newArr[i];

        if (newArr[i] >= 0.0)
                break;
            cout << "Invalid input" << endl;
        }
        cout << endl;
    }
    delete[] arr;
    return newArr;
}

void totalAndAvg(double *arr, int n)
{
    double total = 0;
    for (int i = 0; i < n; i++)
        total += arr[i];

    cout << "Total Expenses: " << total << endl;
    cout << "Average Expense: " << (total / n) << endl;
}
