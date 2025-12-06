#include <iostream>
usingg namespace std;

#define tablesize 100

int hashh(string input)
{
    int len = input.length();
    int sum = 0;

    for (int i = 0; i < len; i++)
        sum += input[i];

    return sum % tablesize;
}

class node
{
public:
    string value;
    node* next = NULL;

    node() {}
    node(string value) : value(value) {}
};

class hashtable
{
public:
    node* arr[tablesize];

    hashtable()
    {
        for (int i = 0; i < tablesize; i++)
            arr[i] = NULL;
    }

    void add_record(string key, string value)
    {
        int hv = hashh(key);

        if (!arr[hv])
            arr[hv] = new node(value);
        else
        {
            node* cur = arr[hv];

            while (cur->next && cur->value != value)
                cur = cur->next;

            if (!cur->next && cur->value != value)
                cur->next = new node(value);
        }
    }

    int word_search(string key, string value)
    {
        int hv = hashh(key);

        if (!arr[hv])
        {
            cout << "not found\n";
            return 0;
        }
        else
        {
            node* cur = arr[hv];

            while (cur->next && cur->value != value)
                cur = cur->next;

            if (cur->value == value)
            {
                cout << "found\n";
                return 1;
            }
            else
            {
                cout << "not found\n";
                return 0;
            }
        }
    }

    void print_dictionary()
    {
        for (int i = 0; i < tablesize; i++)
        {
            node* cur = arr[i];

            while (cur)
            {
                cout << cur->value << " ";
                cur = cur->next;
            }
        }
    }
};

int main()
{
    hashtable mytable;

    mytable.add_record("A", "first");
    mytable.add_record("E", "second");
    mytable.add_record("A", "third");
    mytable.add_record("A", "fourth");

    mytable.word_search("A", "eleventh");
    mytable.word_search("A", "third");
    mytable.word_search("E", "second");
    mytable.word_search("C", "first");

    mytable.print_dictionary();
}
