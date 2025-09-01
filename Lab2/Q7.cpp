#include <iostream>
using namespace std;

int main() {
    int numDepartments;
    
    cout << "Enter number of departments: ";
    cin >> numDepartments;
    
    if (numDepartments <= 0) {
        cout << "Invalid input" << endl;
        return 1;
    }
    
    double** salaries = new double*[numDepartments];
    int* numEmployees = new int[numDepartments];
    
    for (int i = 0; i < numDepartments; i++) {
        cout << "\nDepartment " << (i + 1) << ":\n";
        
        cout << "Enter number of employees: ";
        cin >> numEmployees[i];
        
        while (numEmployees[i] <= 0) {
            cout << "Invalid input ";
            cin >> numEmployees[i];
        }
        
        salaries[i] = new double[numEmployees[i]];
        
        cout << "Enter salaries for " << numEmployees[i] << " employees:\n";
        for (int j = 0; j < numEmployees[i]; j++) {
            cout << "Employee " << (j + 1) << " salary: ";
            cin >> salaries[i][j];
            
            while (salaries[i][j] < 0) {
                cout << "Salary cant be negative. Please re-enter: ";
                cin >> salaries[i][j];
            }
        }
    }

    double* maxSalaries = new double[numDepartments];
    double* avgSalaries = new double[numDepartments];
    
    for (int i = 0; i < numDepartments; i++) {
        double maxSalary = salaries[i][0];
        double total = salaries[i][0];
        
        for (int j = 1; j < numEmployees[i]; j++) {
            if (salaries[i][j] > maxSalary) {
                maxSalary = salaries[i][j];
            }
            total += salaries[i][j];
        }
        
        maxSalaries[i] = maxSalary;
        avgSalaries[i] = total / numEmployees[i];
    }
    
    cout << "Highest salary department wise: \n";
    cout << string(50, '=') << "\n";
    
    for (int i = 0; i < numDepartments; i++) {
        cout << "Department " << (i + 1) << ": $" << maxSalaries[i] << endl;
    }
    
    int maxAvgDept = 0;
    double maxAvgSalary = avgSalaries[0];
    
    for (int i = 1; i < numDepartments; i++) {
        if (avgSalaries[i] > maxAvgSalary) {
            maxAvgSalary = avgSalaries[i];
            maxAvgDept = i;
        }
    }
    
    cout << "Department with highest average salary: \n";
    cout << string(60, '=') << "\n";
    cout << "Department " << (maxAvgDept + 1) << " has the highest average salary: " << maxAvgSalary << endl;
    cout << "Number of employees: " << numEmployees[maxAvgDept] << endl;
    
    cout << "\nAverage salaries for all departments:\n";
    for (int i = 0; i < numDepartments; i++) {
        cout << "Department " << (i + 1) << ": $" << avgSalaries[i] << endl;
    }
    
    for (int i = 0; i < numDepartments; i++) {
        delete[] salaries[i];
    }
    delete[] salaries;
    delete[] numEmployees;
    delete[] maxSalaries;
    delete[] avgSalaries;
    
    return 0;
}
