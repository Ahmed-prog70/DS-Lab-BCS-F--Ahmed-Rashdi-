#include <iostream>
using namespace std;

struct avlnode
{
    int key;
    int heightval;
    avlnode *leftptr;
    avlnode *rightptr;

    avlnode(int k)
    {
        key = k;
        heightval = 1;
        leftptr = nullptr;
        rightptr = nullptr;
    }
};

int getheight(avlnode *n)
{
    if(n == nullptr) return 0;
    return n->heightval;
}

int getbf(avlnode *n)
{
    if(n == nullptr) return 0;
    return getheight(n->leftptr) - getheight(n->rightptr);
}

void refreshheight(avlnode *n)
{
    int lefth = getheight(n->leftptr);
    int righth = getheight(n->rightptr);

    if(lefth > righth)
        n->heightval = lefth + 1;
    else
        n->heightval = righth + 1;
}

avlnode* rotateright(avlnode *y)
{
    avlnode *x = y->leftptr;
    avlnode *t = x->rightptr;

    x->rightptr = y;
    y->leftptr = t;

    refreshheight(y);
    refreshheight(x);

    return x;
}

avlnode* rotateleft(avlnode *x)
{
    avlnode *y = x->rightptr;
    avlnode *t = y->leftptr;

    y->leftptr = x;
    x->rightptr = t;

    refreshheight(x);
    refreshheight(y);

    return y;
}

avlnode* addvalue(avlnode *node, int val)
{
    if(node == nullptr)
        return new avlnode(val);

    if(val < node->key)
        node->leftptr = addvalue(node->leftptr, val);

    else if(val > node->key)
        node->rightptr = addvalue(node->rightptr, val);

    else
        return node;

    refreshheight(node);

    int bf = getbf(node);

    if(bf > 1 && val < node->leftptr->key)
        return rotateright(node);

    if(bf < -1 && val > node->rightptr->key)
        return rotateleft(node);

    if(bf > 1 && val > node->leftptr->key)
    {
        node->leftptr = rotateleft(node->leftptr);
        return rotateright(node);
    }

    if(bf < -1 && val < node->rightptr->key)
    {
        node->rightptr = rotateright(node->rightptr);
        return rotateleft(node);
    }

    return node;
}

void showinorder(avlnode *root)
{
    if(root == nullptr) return;

    showinorder(root->leftptr);
    cout << root->key << " ";
    showinorder(root->rightptr);
}

void showbalance(avlnode *root)
{
    if(root == nullptr) return;

    showbalance(root->leftptr);
    cout << "node " << root->key << " bf = " << getbf(root) << endl;
    showbalance(root->rightptr);
}

int main()
{
    avlnode *root = nullptr;

    int arr[] = {40, 20, 10, 25, 50, 45, 60, 55};
    int n = 8;

    for(int i = 0; i < n; i++)
        root = addvalue(root, arr[i]);

    showbalance(root);

    cout << endl << "height = " << getheight(root) << endl;

    showinorder(root);
    cout << endl;

    return 0;
}
