#include <iostream>
using namespace std;

class SNode {
public:
    int data;
    SNode *next;

    SNode(int value) : data(value), next(nullptr) {}
};
class DNode {
public:
    int data;
    DNode *prev;
    DNode *next;

    DNode(int value) : data(value), prev(nullptr), next(nullptr) {}
};
class SList {
    SNode *head;
public:
    SList() : head(nullptr) {}
    void push_back(int value) {
        SNode *newNode = new SNode(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        SNode *temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = newNode;
    }
  void push_front(int value) {
        SNode *newNode = new SNode(value);
          if (head == nullptr) {
            head = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;  }

    SNode* getHead() { return head; }

   
    void print_list() {
        SNode *temp = head;

        while (temp != nullptr) {
            cout << temp->data << " => ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    ~SList() {
        SNode *temp = head;
        while (temp != nullptr) {
            SNode *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

// Doubly Linked List
class DList {
    DNode *head;

public:
    DList() : head(nullptr) {}

    void push_back(int value) {
        DNode *newNode = new DNode(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        DNode *temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    void push_front(int value) {
        DNode *newNode = new DNode(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    DNode* getHead() { return head; }

    void print_forward() {
        DNode *temp = head;

        while (temp != nullptr) {
            cout << temp->data << " <=> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void print_backward() {
        if (head == nullptr) return;

        DNode *temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        while (temp != nullptr) {
            cout << temp->data << " <=> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }

    ~DList() {
        DNode *temp = head;
        while (temp != nullptr) {
            DNode *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};
class CList {
    SNode *head;

public:
    CList() : head(nullptr) {}

    void push_back(int value) {
        SNode *newNode = new SNode(value);
      if (head == nullptr) {
             head = newNode;
            newNode->next = head;
            return;
        }

     SNode *temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
         newNode->next = head;   }

    void push_front(int value) {
        SNode *newNode = new SNode(value);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            return;
        }

 SNode *temp = head;
        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        head = newNode;
        temp->next = head;
    }

    SNode* getHead() { return head; }

    void print_list() {
        if (head == nullptr) {
            cout << "Empty List" << endl;
            return;
        }

        SNode *temp = head;
        do {
            cout << temp->data << " => ";
            temp = temp->next;
        } while (temp != head);
        cout << "HEAD" << endl;
    }

    ~CList() {
        if (head == nullptr) return;

        SNode *curr = head;
        SNode *nextNode;

        do {
            nextNode = curr->next;
            delete curr;
            curr = nextNode;
        } while (curr != head);
    }
};
DList* convertSinglyToDoubly(SList &sList) {
    DList *dList = new DList();
    SNode *sTemp = sList.getHead();

    while (sTemp != nullptr) {
        dList->push_back(sTemp->data);
        sTemp = sTemp->next;
    }

    return dList;
}

CList* convertSinglyToCircular(SList &sList) {
    CList *cList = new CList();
    SNode *sTemp = sList.getHead();

    while (sTemp != nullptr) {
        cList->push_back(sTemp->data);
        sTemp = sTemp->next;
    }

    return cList;
}

int main() {
    SList sList;
    sList.push_back(1);
    sList.push_back(2);
    sList.push_back(3);
    sList.push_back(4);

    cout << "Original Singly Linked List: ";
    sList.print_list(); 
    DList *dList = convertSinglyToDoubly(sList);
    cout << "\nConverted Doubly Linked List (Forward): ";
    dList->print_forward();
    cout << "Converted Doubly Linked List (Backward): ";
    dList->print_backward();

    CList *cList = convertSinglyToCircular(sList);
    cout << "\nConverted Circular Linked List: ";
    cList->print_list();
    delete dList;
    delete cList;

    return 0;
}