#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class fighternode
{
public:
    int id;
    string name;
    int hp;
    int ap;
    fighternode* left;
    fighternode* right;

    fighternode(int i, string n, int h, int a) : id(i), name(n), hp(h), ap(a), left(NULL), right(NULL) {}
};
class fighterbst
{
    fighternode* root;


    fighternode* getmin(fighternode* node)
    {
        while(node && node->left)
            node = node->left;

        return node;
    }
    void inorderprint(fighternode* node)
    {
        if(!node)
            return;

        inorderprint(node->left);
        cout << "\nid: " << node->id << ", name: " << node->name << ", hp: " << node->hp << ", ap: " << node->ap;
        inorderprint(node->right);
    }
    fighternode* insertnode(fighternode* node, int i, string n, int h, int a)
    {
        if(!node)
            return new fighternode(i, n, h, a);

        if(i < node->id)
            node->left = insertnode(node->left, i, n, h, a);

        else if(i > node->id)
            node->right = insertnode(node->right, i, n, h, a);

        return node;
    }

    fighternode* deletenode(fighternode* node, int i)
    {
        if(!node)
            return NULL;

        if(i < node->id)
            node->left = deletenode(node->left, i);

        else if(i > node->id)
            node->right = deletenode(node->right, i);
        else
        {
            if(!node->left)
            {
                fighternode* temp = node->right;
                delete node;
                return temp;
            }
            if(!node->right)
            {
                fighternode* temp = node->left;
                delete node;
                return temp;
            }
            fighternode* m = getmin(node->right);
            node->id = m->id;
            node->name = m->name;
            node->hp = m->hp;
            node->ap = m->ap;

            node->right = deletenode(node->right, m->id);
        }

        return node;
    }
public:

    fighterbst() : root(NULL) {}
    void addfighter(int i, string n, int h, int a)
    {
        root = insertnode(root, i, n, h, a);
    }
    void removefighter(int i)
    {
        root = deletenode(root, i);
    }

    fighternode* getfirst()
    {
        fighternode* t = root;

        if(!t)
            return NULL;

        while(t->left)
            t = t->left;

        return t;
    }
    void showteam()
    {
        if(!root)
        {
            cout << "\n(team empty)";
            return;
        }

        inorderprint(root);
        cout << endl;
    }


    fighternode* getroot()
    {
        return root;
    }
};
void fightround(fighterbst& teama, fighterbst& teamb, int round)
{
    cout << "\n========================\n";
    cout << "       round " << round << "\n";
    cout << "========================\n";

    cout << "\n--- team a ---";
    teama.showteam();

    cout << "\n--- team b ---";
    teamb.showteam();
    cout << endl;

    fighternode* a = teama.getfirst();
    fighternode* b = teamb.getfirst();

    if(!a || !b)
        return;

    cout << "\nteam a frontline: " << a->name << " (hp: " << a->hp << ")";
    cout << "\nteam b frontline: " << b->name << " (hp: " << b->hp << ")\n";

    int da = a->ap + (rand() % 5);
    b->hp -= da;

    cout << "team a " << a->name << " hits " << b->name << " for " << da << " damage\n";
    if(b->hp <= 0)
    {
        cout << "team b " << b->name << " has fallen\n";
        teamb.removefighter(b->id);
        return;
    }

    int db = b->ap + (rand() % 5);
    a->hp -= db;
    cout << "team b " << b->name << " hits back for " << db << " damage\n";
    if(a->hp <= 0)
    {
        cout << "team a " << a->name << " is defeated\n";
        teama.removefighter(a->id);
    }
}


void battle(fighterbst& teama, fighterbst& teamb)
{
    int r = 1;
    while(teama.getroot() && teamb.getroot())
    {
        fightround(teama, teamb, r);
        r++;
    }
    if(!teamb.getroot())
        cout << "\nteam a wins\n";
    else
        cout << "\nteam b wins\n";
}
int main()
{
    srand(time(NULL));
    fighterbst teama, teamb;

    teama.addfighter(10, "warrior", 45, 8);
    teama.addfighter(5, "sniper", 30, 7);
    teama.addfighter(15, "sorcerer", 25, 10);
    teama.addfighter(3, "guardian", 50, 6);
    teama.addfighter(8, "assassin", 28, 9);

    teamb.addfighter(12, "ogre", 22, 5);
    teamb.addfighter(6, "berserker", 35, 8);
    teamb.addfighter(18, "necromancer", 30, 9);
    teamb.addfighter(1, "zombie", 20, 4);
    teamb.addfighter(9, "behemoth", 55, 7);

    cout << "\n==== battle begins ====\n";
    battle(teama, teamb);

    return 0;
}
