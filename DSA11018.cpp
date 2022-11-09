#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node(int x)
    {
        this->data = x;
        left = right = NULL;
    }
};

typedef node *tree;
int t, n;

void add(tree &T, int so)
{
    // cout << so << "////////////////////////\n";
    if (T == NULL)
    {
        T = new node(so);
    }
    else
    {
        tree cur = T;
        node *p = new node(so);
        while (true)
        {
            // cout << cur->data << endl;
            if (cur->left != NULL && cur->data > so)
                cur = cur->left;
            else if (cur->left == NULL && cur->data > so)
            {
                cur->left = p;
                break;
            }
            else if (cur->right != NULL && cur->data < so)
                cur = cur->right;
            else if (cur->right == NULL && cur->data < so)
            {
                cur->right = p;
                break;
            }
        }
    }
    return;
}

void load(tree T)
{
    if (T == NULL)
        return;
    cout << T->data << " ";
    load(T->left);
    load(T->right);
    return;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        tree T = NULL;
        for (int i = 1; i <= n; i++)
        {
            int so;
            cin >> so;
            add(T, so);
        }
        load(T);
        cout << endl;
    }
}