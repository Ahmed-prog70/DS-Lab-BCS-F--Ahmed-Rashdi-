
#include <iostream>
using namespace std;

class treenode
{
public:
    int data;
    treenode* left;
    treenode* right;

    treenode(int d) : data(d), left(NULL), right(NULL) {}
};
class binarysearchtree
{
    treenode* root;

public:
    binarysearchtree() : root(NULL) {}
    treenode* findmin(treenode* curr)
    {
        while(curr && curr->left != NULL)
            curr = curr->left;

        return curr;
    }
    void constructbst(int arr[], int size)
    {
        root = NULL;

        for(int i = 0; i < size; i++)
            root = insertnode(root, arr[i]);
    }
    treenode* insertnode(treenode* curr, int val)
    {
        if(curr == NULL)
            return new treenode(val);
        if(val < curr->data)
            curr->left = insertnode(curr->left, val);
        else if(val > curr->data)
            curr->right = insertnode(curr->right, val);

        return curr;
    }
    void inorder(treenode* curr)
    {
        if(curr == NULL)
            return;

        inorder(curr->left);
        cout << curr->data << " ";
        inorder(curr->right);
    }
    void preorder(treenode* curr)
    {
        if(curr == NULL)
            return;

        cout << curr->data << " ";
        preorder(curr->left);
        preorder(curr->right);
    }
    void postorder(treenode* curr)
    {
        if(curr == NULL)
            return;
        postorder(curr->left);
        postorder(curr->right);
        cout << curr->data << " ";
    }
    treenode* searchnode(treenode* curr, int key)
    {
        if(curr == NULL)
            return NULL;

        if(curr->data == key)
            return curr;

        if(key < curr->data)
            return searchnode(curr->left, key);

        return searchnode(curr->right, key);
    }
    treenode* deletenode(treenode* curr, int key)
    {
        if(curr == NULL)
            return NULL;
        if(key < curr->data)
            curr->left = deletenode(curr->left, key);

        else if(key > curr->data)
            curr->right = deletenode(curr->right, key);

        else
        {
            if(curr->left == NULL)
            {
                treenode* temp = curr->right;
                delete curr;
                return temp;
            }
            if(curr->right == NULL)
            {
                treenode* temp = curr->left;
                delete curr;
                return temp;
            }
            treenode* minnode = findmin(curr->right);
            curr->data = minnode->data;
            curr->right = deletenode(curr->right, minnode->data);
        }

        return curr;
    }

    treenode* getroot()
    {
        return root;
    }
};


int main()
{
    int arr[50];
    int n;

    cout << "enter number of elements: ";
    cin >> n;

    cout << "enter numbers: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    binarysearchtree bst;
    bst.constructbst(arr, n);

    cout << endl << "preorder: ";
    bst.preorder(bst.getroot());

    cout << endl << "postorder: ";
    bst.postorder(bst.getroot());

    cout << endl << "inorder: ";
    bst.inorder(bst.getroot());
    int delval;
    cout << endl << "enter value to delete: ";
    cin >> delval;

    bst.deletenode(bst.getroot(), delval);
    cout << endl << "inorder after deletion: ";
    bst.inorder(bst.getroot());

    int value;
    cout << endl << "enter value to search: ";
    cin >> value;
    if(bst.searchnode(bst.getroot(), value))
        cout << "value found";
    else
        cout << "value not found";

    return 0;
}
