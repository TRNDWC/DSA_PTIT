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

void Load(tree T)
{
    stack<tree> s1, s2;
    s1.push(T);
    while (s1.size() || s2.size())
    {
        while (s1.size())
        {
            tree cur = s1.top();
            s1.pop();
            cout << cur->data << " ";
            if (cur->pRight != NULL)
                s2.push(cur->pRight);
            if (cur->pLeft != NULL)
                s2.push(cur->pLeft);
        }
        while (s2.size())
        {
            tree cur = s2.top();
            s2.pop();
            cout << cur->data << " ";
            if (cur->pLeft != NULL)
                s1.push(cur->pLeft);
            if (cur->pRight != NULL)
                s1.push(cur->pRight);
        }
    }
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        tree T = NULL;
        for (int i = 0; i < n; i++)
        {
            int u, v;
            char c;
            cin >> u >> v >> c;
            add_Node(T, u, v, c);
        }
        Load(T);
        cout << endl;
    }
    return 0;
}