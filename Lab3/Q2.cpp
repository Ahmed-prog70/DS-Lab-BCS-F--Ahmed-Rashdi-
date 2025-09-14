#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};
class List {
    Node *head;
public:
    List() : head(nullptr) {}

    void push_back  (int value)
      {
        Node *newNode =   new Node(value);

        if (head == nullptr)
         {
            head = newNode;
            return;}
        Node *temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = newNode;
    }

    void push_front(int value) {
        Node *newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void mergeSorted(List &otherList) {
        Node *a = head;
        Node *b = otherList.head;
        Node *dummy = new Node(-1);
        Node *tail = dummy;

        while (a != nullptr && b != nullptr) {
            if (a->data <= b->data) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        if (a != nullptr) {
            tail->next = a;
        } else {
            tail->next = b;
        }
     head = dummy->next;
        delete dummy;
        otherList.head = nullptr;
    }

    void print_list() {
        Node *temp = head;

        while (temp != nullptr) {
            cout << temp->data << " => ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    ~List() {
        Node *temp = head;
        while (temp != nullptr) {
            Node *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main() {
    List listA, listB;
    listA.push_back(1);
    listA.push_back(3);
    listA.push_back(5);

    listB.push_back(2);
    listB.push_back(4);
    listB.push_back(6);

    cout << "List A: ";
    listA.print_list();
    cout << "List B: ";
    listB.print_list();

    listA.mergeSorted(listB);

    cout << "After merging:" << endl;
    cout << "Merged List: ";
    listA.print_list();
    return 0;
}