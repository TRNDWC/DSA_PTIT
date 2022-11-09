#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *pLeft;
    node *pRight;
    node(int x)
    {
        this->data = x;
        pLeft = pRight = NULL;
    }
};
typedef node *tree;

void add_Node(tree &T, int u, int v, char c)
{
    if (T == NULL)
    {
        T = new node(u);
        node *p = new node(v);
        if (c == 'L')
            T->pLeft = p;
        else
            T->pRight = p;
    }
    else
    {
        if (T->data == u)
        {
            node *p = new node(v);
            if (c == 'L')
                T->pLeft = p;
            else
                T->pRight = p;
        }
        else
        {
            if (T->pLeft != NULL)
                add_Node(T->pLeft, u, v, c);
            if (T->pRight != NULL)
                add_Node(T->pRight, u, v, c);
        }
    }
}

bool Load(tree T1, tree T2)
{
    queue<tree> X1;
    queue<tree> X2;
    X1.push(T1);
    X2.push(T2);
    while (X1.size() || X2.size())
    {
        tree tmp1 = X1.front();
        X1.pop();
        tree tmp2 = X2.front();
        X2.pop();
        //cout << tmp1->data << " " << tmp2->data << endl;
        if (tmp1->data != tmp2->data)
            return false;
        if (tmp1->pLeft != NULL)
            X1.push(tmp1->pLeft);
        if (tmp1->pRight != NULL)
            X1.push(tmp1->pRight);
        if (tmp2->pLeft != NULL)
            X2.push(tmp2->pLeft);
        if (tmp2->pRight != NULL)
            X2.push(tmp2->pRight);
    }
    if (X1.size() != X2.size())
        return false;
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n;
        tree T1 = NULL;
        for (int i = 0; i < n; i++)
        {
            int u, v;
            char c;
            cin >> u >> v >> c;
            add_Node(T1, u, v, c);
        }
        cin >> m;
        tree T2 = NULL;
        for (int i = 0; i < m; i++)
        {
            int u, v;
            char c;
            cin >> u >> v >> c;
            add_Node(T2, u, v, c);
        }
        cout << Load(T1, T2) << endl;
    }
    return 0;
}