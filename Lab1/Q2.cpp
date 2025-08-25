#include <iostream>
#include <cstring>
using namespace std;

class Exam {
private:
    char* studentName; 
    char* examDate;
    double score;

public:
    Exam(const char* n, const char* d, double eScore) {

        studentName = new char[strlen(n) + 1];
        strcpy(studentName, n);
        
        examDate = new char[strlen(d) + 1];
        strcpy(examDate, d);
        
        score = eScore;
        
        cout << "Constructor called for: " << studentName << endl;
    }

    ~Exam() {
        cout << "Destructor called for: " << studentName << endl;
        delete[] studentName;
        delete[] examDate;
    }

    void setStudentName(const char* name) {
        delete[] studentName;
        studentName = new char[strlen(name) + 1];
        strcpy(studentName, name);
    }

    void setExamDate(const char* date) {
        delete[] examDate;
        examDate = new char[strlen(date) + 1];
        strcpy(examDate, date);
    }

    void setScore(double examScore) {
        score = examScore;
    }
    void displayExamDetails() const {
        cout << "Student: " << studentName << endl;
        cout << "Exam Date: " << examDate << endl;
        cout << "Score: " << score << "/100" << endl;
        cout << "Memory address of studentName: " << (void*)studentName << endl;
        cout << "Memory address of examDate: " << (void*)examDate << endl;
    }
};

int main() {
    
    cout << "Creating original exam object..." << endl;
    Exam exam1("John Doe", "2024-03-15", 85.5);
    exam1.displayExamDetails();

    cout << "Creating shallow copy using copy constructor..." << endl;
    Exam exam2 = exam1;
    exam2.displayExamDetails();

    cout << "Modifying the copy..." << endl;
    exam2.setStudentName("Jane Smith");
    exam2.setScore(92.0);

    cout << "After modifying the copy:" << endl;
    cout << "Original object:" << endl;
    exam1.displayExamDetails();
    cout << "Copied object:" << endl;
    exam2.displayExamDetails();

    // both objects have the same memory addresses for studentName. This means they share the same dynamically allocated memory.

    return 0;
}