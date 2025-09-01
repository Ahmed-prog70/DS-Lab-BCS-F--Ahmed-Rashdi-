#include <iostream>
using namespace std;

class safePtr {
private:
    int* ptr;
    bool isReleased;

public:
    safePtr() : ptr(nullptr), isReleased(true) {}
    
    safePtr(int size) {
        ptr = new int[size];
        isReleased = false;
    }
    

    ~safePtr() {
        release();
    }
    void setValue(int index, int value) {
        if (isReleased) {
            cout << "Error: Pointer has been released!\n";
            return;
        }
        if (ptr == nullptr) {
            cout << "Error: Pointer is null!\n";
            return;
        }
        ptr[index] = value;
    }
    int getValue(int index) {
        if (isReleased) {
            cout << "Error: Pointer has been released! Returning -1.\n";
            return -1;
        }
        if (ptr == nullptr) {
            cout << "Error: Pointer is null! Returning -1.\n";
            return -1;
        }
        return ptr[index];
    }
    void release() {
        if (!isReleased && ptr != nullptr) {
            delete[] ptr;
            ptr = nullptr;
            isReleased = true;
            cout << "Memory released successfully.\n";
        }
    }
    
    bool isValid() const {
        return !isReleased && ptr != nullptr;
    }
    string getStatus() const {
        if (isReleased) return "Released";
        if (ptr == nullptr) return "Null";
        return "Active";
    }
};

int main() {
    const int studentNum = 5;
    safePtr marks(studentNum);
    
    cout << "Pointer status: " << marks.getStatus() << endl;
    cout << "Is valid: " << (marks.isValid() ? "Yes" : "No") << endl;
    cout << endl;
    cout << "Enter marks for " << studentNum << " students:\n";
    
    
    for (int i = 0; i < studentNum; i++) {
        int mark;
        cout << "Student " << (i + 1) << " marks: ";
        cin >> mark;
        marks.setValue(i, mark);
    }
    
    cout << endl;
    cout << "Student Marks:\n";
    for (int i = 0; i < studentNum; i++) {
        cout << "Student " << (i + 1) << ": " << marks.getValue(i) << endl;
    }
    
    cout << endl;
    cout << "Releasing memory.\n";
    marks.release();
    
    cout << "Pointer status after release: " << marks.getStatus() << endl;
    cout << "Is valid after release: " << (marks.isValid() ? "Yes" : "No") << endl;
    
    return 0;
}
