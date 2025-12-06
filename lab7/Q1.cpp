#include <iostream>
#include <string>
using namespace std;

struct student
{
    string name;
    int score;
};

struct node
{
    student s;
    node *next;

    node(student st, node *n = nullptr)
    {
        s = st;
        next = n;
    }
};

void insertnode(node *&head, const student &s)
{
    node *newnode = new node(s);

    if (!head)
    {
        head = newnode;
        return;
    }

    node *curr = head;

    while (curr->next != nullptr)
        curr = curr->next;

    curr->next = newnode;
}

void displaylist(node *head)
{
    node *curr = head;

    while (curr != nullptr)
    {
        cout << "Student Name: " << curr->s.name << " | Student Score: " << curr->s.score << endl;
        curr = curr->next;
    }

    cout << endl;
}

void clearbucket(node *&head)
{
    node *temp;

    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

void radixsort(node *&head, int n)
{
    if (!head || !head->next)
        return;

    int maxnum = 100;
    int exp = 1;

    node *buckets[10];

    while (maxnum / exp > 0)
    {
        for (int i = 0; i < 10; i++)
            buckets[i] = nullptr;

        node *curr = head;

        for (int i = 0; i < n; i++)
        {
            int digit = (curr->s.score / exp) % 10;
            insertnode(buckets[digit], curr->s);
            curr = curr->next;
        }

        clearbucket(head);

        for (int i = 0; i < 10; i++)
        {
            node *temp = buckets[i];

            while (temp != nullptr)
            {
                insertnode(head, temp->s);
                temp = temp->next;
            }

            clearbucket(buckets[i]);
        }

        exp *= 10;
    }
}

student *tolist(node *head, int n)
{
    student *arr = new student[n];

    node *curr = head;
    int idx = 0;

    while (curr != nullptr)
    {
        arr[idx++] = curr->s;
        curr = curr->next;
    }

    return arr;
}

int binarysearch(student *arr, int n, const string &name, int score)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid].score == score)
        {
            if (arr[mid].name == name)
                return mid;

            int i = mid - 1;

            while (i >= left && arr[i].score == score)
            {
                if (arr[i].name == name)
                    return i;
                i--;
            }

            i = mid + 1;

            while (i <= right && arr[i].score == score)
            {
                if (arr[i].name == name)
                    return i;
                i++;
            }

            return -1;
        }

        else if (arr[mid].score < score)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

void deleterec(node *&head, const string &name, int score)
{
    node *curr = head;
    node *prev = nullptr;

    while (curr)
    {
        if (curr->s.name == name && curr->s.score == score)
        {
            if (!prev)
                head = curr->next;
            else
                prev->next = curr->next;

            delete curr;
            cout << "Record deleted successfully." << endl;
            return;
        }

        prev = curr;
        curr = curr->next;
    }

    cout << "Record not found." << endl;
}

int main()
{
    int n;

    cout << "Enter the number of students: ";
    cin >> n;
    cin.ignore();
    cout << endl;

    node *head = nullptr;

    for (int i = 0; i < n; i++)
    {
        student s;

        cout << "Enter the name of student " << (i + 1) << ": ";
        getline(cin, s.name);
        do
        {
            cout << "Enter the score out of 100 of student " << (i + 1) << ": ";
            cin >> s.score;
            cin.ignore();

            if (s.score < 0 || s.score > 100)
                cout << "Invalid score entered!" << endl;

        } while (s.score < 0 || s.score > 100);

        insertnode(head, s);
        cout << endl;
    }

    cout << "------------------ Displaying the original list ------------------\n";
    displaylist(head);
    radixsort(head, n);

    cout << "------------------ Displaying the sorted list ------------------\n";
    displaylist(head);
    string name;
    int score;

    cout << "Enter name & score to search and delete: ";
    getline(cin, name);
    cin >> score;

    student *arr = tolist(head, n);
    int idx = binarysearch(arr, n, name, score);

    if (idx != -1)
    {
        deleterec(head, name, score);
        cout << "------------------ Updated List ------------------\n";
        displaylist(head);
    }
    else
    {
        cout << "Record not found. No deletion performed." << endl;
    }
    return 0;
}
