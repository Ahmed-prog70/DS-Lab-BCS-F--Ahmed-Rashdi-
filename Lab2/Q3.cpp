#include <iostream>
using namespace std;

int main() {
    int studentNum;
    cout << "Enter number of students: ";
    cin >> studentNum;
    
    while (studentNum <= 0) {
        cout << "Invalid Input. ";
        cin >> studentNum;
    }
    int* numCourses = new int[studentNum];
    double** studentMarks = new double*[studentNum];
    for (int i = 0; i < studentNum; i++) {
         cout << "\nStudent " << (i + 1) << ":\n";
         cout << "Enter number of courses: ";
         cin >> numCourses[i];
    while (numCourses[i] <= 0) {
            cout << "Invalid input ";
            cin >> numCourses[i];
        }
        
        studentMarks[i] = new double[numCourses[i]];
        
cout << "Enter marks for " << numCourses[i] << " courses:\n";
    for (int j = 0; j < numCourses[i]; j++) {
         cout << "Course " << (j + 1) << ": ";
         cin >> studentMarks[i][j];
            
            while (studentMarks[i][j] < 0 || studentMarks[i][j] > 100) {
                cout << "Marks can only be between 0 and 100. ";
                cin >> studentMarks[i][j];
            }
        }
    }
    
    cout << "Report card\n";

    for (int i = 0; i < studentNum; i++) {
        double sum = 0.0;
        
        for (int j = 0; j < numCourses[i]; j++) {
            sum += studentMarks[i][j];
        }
        
        double average = (numCourses[i] > 0) ? sum / numCourses[i] : 0.0;
        
    cout << "Student " << (i + 1) << ": ";
     cout << numCourses[i] << " courses, ";
     cout << "Average = " << average;
     cout << " Marks: ";
        
  for (int j = 0; j < numCourses[i]; j++) {
            cout << studentMarks[i][j];
            if (j < numCourses[i] - 1) cout << ", ";
        }
           cout << endl;
    }
    
    for (int i = 0; i < studentNum; i++) {
        delete[] studentMarks[i];
    }
    delete[] studentMarks;
    delete[] numCourses;
    
    return 0;
}
