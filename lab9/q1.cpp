#include <iostream>
using namespace std;

struct treenode
{
    int value;
    treenode *leftchild;
    treenode *rightchild;
    int heightlevel;

    treenode(int v)
    {
        value = v;
        leftchild = nullptr;
        rightchild = nullptr;
        heightlevel = 1;
    }
};

class avltree
{
private:

    treenode *rootnode;

    int getheight(treenode *node)
    {
        if(node == nullptr) return 0;
        return node->heightlevel;
    }

    void refreshheight(treenode *node)
    {
        int lefth = getheight(node->leftchild);
        int righth = getheight(node->rightchild);

        if(lefth > righth)
            node->heightlevel = lefth + 1;
        else
            node->heightlevel = righth + 1;
    }

    treenode* rotateleft(treenode *oldroot)
    {
        treenode *newroot = oldroot->rightchild;
        treenode *temp = newroot->leftchild;

        newroot->leftchild = oldroot;
        oldroot->rightchild = temp;

        refreshheight(oldroot);
        refreshheight(newroot);

        return newroot;
    }

    treenode* addnode(treenode *current, int val)
    {
        if(current == nullptr)
            return new treenode(val);

        if(val < current->value)
            current->leftchild = addnode(current->leftchild, val);

        else if(val > current->value)
            current->rightchild = addnode(current->rightchild, val);

        else
            return current;

        refreshheight(current);
        return current;
    }
    void showinorder(treenode *node)
    {
        if(node == nullptr) return;

        showinorder(node->leftchild);
        cout << node->value << " ";
        showinorder(node->rightchild);
    }

public:
    avltree()
    {
        rootnode = nullptr;
    }

    void insertvalue(int v)
    {
        rootnode = addnode(rootnode, v);
    }

    void applyleftrotation()
    {
        rootnode = rotateleft(rootnode);
    }
    void printtree()
    {
        showinorder(rootnode);
        cout << endl;
    }
};
int main()
{
    avltree mytree;
    int items[] = {50, 30, 70, 20, 40, 60, 80, 55};
    int n = 8;

    for(int i = 0; i < n; i++)
        mytree.insertvalue(items[i]);
    mytree.applyleftrotation();
  mytree.printtree();
 return 0;
}
