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

void addNODE(int n, tree &root)
{
    map<int, tree> m;
    for (int i = 0; i < n; i++)
    {
        int u, v;
        char c;
        cin >> u >> v >> c;
        if (m.find(u) == m.end())
        {
            (root) = new node(u);
            if (c == 'L')
            {
                (root)->pLeft = new node(v);
                m[v] = (root)->pLeft;
            }
            else
            {
                (root)->pRight = new node(v);
                m[v] = (root)->pRight;
            }
            m[u] = (root);
        }
        else
        {
            if (c == 'L')
            {
                m[u]->pLeft = new node(v);
                m[v] = m[u]->pLeft;
            }
            else
            {
                m[u]->pRight = new node(v);
                m[v] = m[u]->pRight;
            }
        }
    }
}

int Load(tree T)
{
    queue<pair<tree, char>> X;
    X.push({T, '_'});
    int ans = 0;
    while (X.size())
    {
        tree tmp = X.front().first;
        char kt = X.front().second;
        X.pop();
        if (tmp->pLeft == NULL && tmp->pRight == NULL && kt == 'r')
            ans += tmp->data;
        if (tmp->pLeft != NULL)
            X.push({tmp->pLeft, 'l'});
        if (tmp->pRight != NULL)
            X.push({tmp->pRight, 'r'});
    }
    return ans;
}

void Load_1(tree T)
{
    queue<tree> X;
    X.push(T);
    while (X.size())
    {
        tree tmp = X.front();
        X.pop();
        cout << tmp->data << " ";
        if (tmp->pLeft != NULL)
            X.push(tmp->pLeft);
        if (tmp->pRight != NULL)
            X.push(tmp->pRight);
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
        addNODE(n, T);
        cout << Load(T) << endl;
    }
    return 0;
}