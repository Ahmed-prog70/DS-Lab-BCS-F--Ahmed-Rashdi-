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

    bool isPalindrome() {
        if (head == nullptr || head->next == nullptr)
            return true;
        Node *slow = head;
        Node *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node *secondHalf = reverseList(slow->next);
        Node *firstHalf = head;

        Node *temp = secondHalf;
        bool result = true;
        while (temp != nullptr) {
            if (firstHalf->data != temp->data) {
                result = false;
                break;
            }
            firstHalf = firstHalf->next;
            temp = temp->next;
        }

        slow->next = reverseList(secondHalf);
        return result;
    }

private:
    Node* reverseList(Node* node) {
        Node *prev = nullptr;
        Node *curr = node;
        while (curr != nullptr) {
            Node *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
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
    List l1, l2, l3;
    l1.push_back(3);
    l1.push_back(2);
    l1.push_back(9);
    l1.push_front(7);

    cout << "\n Printing List 1 \n";
    l1.print_list();
    cout << "Is List 1 a palindrome: " << (l1.isPalindrome() ? "Yes" : "No") << endl;

    cout << "\n Printing List 2 \n";
    l2.print_list();
    cout << "Is List 2 a palindrome: " << (l2.isPalindrome() ? "Yes" : "No") << endl;

    l3.push_front(9);
    cout << "\n Printing List 3 \n";
    l3.print_list();
    cout << "Is List 3 a palindrome: " << (l3.isPalindrome() ? "Yes" : "No") << endl;

    return 0;
}