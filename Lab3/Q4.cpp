#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};
class CircularList {
    Node *head;
public:
    CircularList() : head(nullptr) {}
    void buildCircle(int n) {
        if (n <= 0) return;

        head = new Node(1);
        Node *temp = head;

        for (int i = 2; i <= n; i++) {
            temp->next = new Node(i);
            temp = temp->next;
        }

        temp->next = head; 
    }

    int josephus(int k) {
        if (head == nullptr) return -1;
        Node *curr = head;
        Node *prev = nullptr;

     while (curr->next != head) {
            curr = curr->next;
        }
        prev = curr;
         curr = head;

        while (curr->next != curr) { 
            for (int i = 1; i < k; i++) {
                prev = curr;
                curr = curr->next;
            }
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }

        head = curr;
        return curr->data;
    }

    void print_list() {
        if (head == nullptr) {
            cout << "Empty List" << endl;
            return;
        }

        Node *temp = head;
        do {
            cout << temp->data << " => ";
            temp = temp->next;
        } while (temp != head);
        cout << "HEAD" << endl;
    }

    ~CircularList() {
        if (head == nullptr) return;
        Node *curr = head;
        Node *nextNode;

        do {
            nextNode = curr->next;
            delete curr;
            curr = nextNode;
        } while (curr != head);
    }
};

int main() {
    CircularList circle;
    int n = 7, k = 3;

    circle.buildCircle(n);
    cout << "Initial circle of " << n << " people: ";
    circle.print_list();

    int survivor = circle.josephus(k);
    cout << "The survivor is at position: " << survivor << endl;

    return 0;
}