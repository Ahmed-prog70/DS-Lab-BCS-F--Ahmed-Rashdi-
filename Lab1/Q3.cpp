#include <iostream>
using namespace std;

class Box {
private:
    int* data; 
public:
    Box(int value) {
        data = new int;
        *data = value;
        cout << "Constructor called. Value: " << value << endl;
    }

    ~Box() {
        cout << "Destructor called. Deleting value: " << *data << endl;
        delete data;
    }

    Box(const Box& other) {
        data = new int;  
        *data = *other.data; 
        cout << "Deep Copy Constructor called. Copied value: " << *data << endl;
    }

    Box& operator=(const Box& other) {
        if (this != &other) {  
            *data = *other.data;  
            cout << "Deep Copy Assignment called. New value: " << *data << endl;
        }
        return *this;
    }

   
    int getValue() const {
        return *data;
    }

  
    void setValue(int value) {
        *data = value;
    }

    void showMemoryAddress() const {
        cout << "Memory address: " << data << endl;
    }
};


void shallowCopyDemo() {
    cout << "\nshallow copy demo" << endl;
    
    Box original(100);
    cout << "Original Value: " << original.getValue();
    original.showMemoryAddress();

}

void deepCopyDemo() {
    cout << "\ndeep copy demo" << endl;
    
    Box box1(50);
    cout << "Box1 Value: " << box1.getValue();
    box1.showMemoryAddress();

    Box box2 = box1; 
    cout << "Box2 Value: " << box2.getValue();
    box2.showMemoryAddress();

    box2.setValue(75);
    cout << "After modifying Box2:" << endl;
    cout << "Box1 value: " << box1.getValue() << endl;
    cout << "Box2 value: " << box2.getValue() << endl;

    Box box3(10);
    box3 = box1;  
    cout << "Box3 after assignment. Value: " << box3.getValue();
    box3.showMemoryAddress();
}

int main() {
    cout << "Box class with rules of three" << endl;
    
    deepCopyDemo();
    
    return 0;
}