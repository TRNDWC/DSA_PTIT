#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

typedef node *tree;
int t, n, ans, a[2001];

void add(tree &T, int u)
{
    if (T == NULL)
    {
        T = new node(u);
    }
    else if (u > T->data)
        add(T->right, u);
    else
        add(T->left, u);
}

void Build(tree &T, int M[], int left, int right)
{
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    // cout << M[mid] << endl;
    add(T, M[mid]);
    Build(T, M, mid + 1, right);
    Build(T, M, left, mid);
}

void load(tree T)
{
    if (T == NULL)
        return;
    if (T->left == NULL && T->right == NULL)
        ans++;
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
            cin >> a[i];
        sort(a + 1, a + n + 1, greater<>());
        Build(T, a, 1, n + 1);
        ans = 0;
        load(T);
        cout << ans << endl;
    }
}