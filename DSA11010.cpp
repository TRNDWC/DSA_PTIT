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

bool Load(tree T)
{
    queue<pair<tree, int>> X;
    X.push({T, 0});
    int ck = -1;
    while (X.size())
    {
        tree tmp = X.front().first;
        int le = X.front().second;
        //cout << tmp->data << " " << le << endl;
        X.pop();
        if (tmp->pLeft == NULL && tmp->pRight == NULL)
            if (ck == -1)
                ck = le;
            else if (ck != le)
                return false;
        if (tmp->pLeft == NULL && tmp->pRight != NULL)
            return false;
        if (tmp->pLeft != NULL && tmp->pRight == NULL)
            return false;
        if (tmp->pLeft != NULL)
            X.push({tmp->pLeft, le + 1});
        if (tmp->pRight != NULL)
            X.push({tmp->pRight, le + 1});
    }
    return true;
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
        if (Load(T))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}