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

    void push_back(int value) {
        Node *newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

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
void reverseInGroups(int k) {
        head = reverseGroup(head, k);
    }

private:
    Node* reverseGroup(Node *start, int k) {
        Node *curr = start;
        Node *prev = nullptr;
        Node *next = nullptr;
        int count = 0;

        Node *temp = start;
        for (int i = 0; i < k; i++) {
            if (temp == nullptr) {
                return start; 
            }
            temp = temp->next;
        }
        while (curr != nullptr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if (next != nullptr) 
            start->next = reverseGroup(next, k);

        return prev;
    }

public:
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
    List list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    list.push_back(7);
    list.push_back(8);

    cout << "Original List: ";
    list.print_list();

    int k = 3;
    list.reverseInGroups(k);

    cout << "After reversing in groups of " << k << ": ";
    list.print_list();

    return 0;
}