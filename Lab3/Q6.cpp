#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node *next;
    Node *child;

    Node(int value) : data(value), next(nullptr), child(nullptr) {}
};

class MultilevelList {
    Node *head;
public:
    MultilevelList() : head(nullptr) {}
    void push_next(int value) {
        Node *newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;}
        Node *temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = newNode;
    }
    void addChild(int parentData, MultilevelList &childList) {
        Node *temp = head;
     while (temp != nullptr) {
            if (temp->data == parentData) {
                  temp->child = childList.head;
                return;
            }
            temp = temp->next; }
    }

    void flatten() {
        if (head == nullptr) return;

        Node *curr = head;
        while (curr != nullptr) {
            if (curr->child != nullptr) {
                Node *nextNode = curr->next;
                Node *childTail = curr->child;
                while (childTail->next != nullptr)
                    childTail = childTail->next;

                curr->next = curr->child;
                curr->child = nullptr;
                childTail->next = nextNode;
            }
            curr = curr->next;  }
    }

    void print_list() {
        Node *temp = head;

        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    ~MultilevelList() {
        Node *temp = head;
        while (temp != nullptr) {
            Node *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main() {
    MultilevelList list;
    list.push_next(1);
    list.push_next(2);
    list.push_next(3);
    MultilevelList childList;
    childList.push_next(4);
    childList.push_next(5);
    list.addChild(3, childList);

    cout << "Original Multilevel List:" << endl;
    cout << "1 -> 2 -> 3" << endl;
    cout << "          |" << endl;
    cout << "          4 -> 5" << endl;

    list.flatten();
    cout << "\nFlattened List: ";
    list.print_list();

    return 0;
}