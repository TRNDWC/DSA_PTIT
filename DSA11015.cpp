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

int res;

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

int Load(tree T)
{
    if (!T)
        return 0;
    int sumLeft = Load(T->pLeft);
    int sumRight = Load(T->pRight);
    if (!T->pLeft && !T->pRight)
        return T->data;
    if (!T->pLeft)
        return sumRight + T->data;
    if (!T->pRight)
        return sumLeft + T->data;
    if (T->pLeft && T->pRight)
    {
        res = max(res, sumLeft + sumRight + T->data);
        return max(sumLeft, sumRight) + T->data;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n;
        tree T = NULL;
        for (int i = 0; i < n; i++)
        {
            int u, v;
            char c;
            cin >> u >> v >> c;
            add_Node(T, u, v, c);
        }
        res = INT_MIN;
        Load(T);
        cout << res << endl;
    }
    return 0;
}