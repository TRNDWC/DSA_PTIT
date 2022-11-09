#include <bits/stdc++.h>
using namespace std;

int t, n, a[20];

void xuli(int n)
{
    cout << "[";
    for (int i = 1; i <= n; i++)
        if (i == n)
            cout << a[i];
        else
            cout << a[i] << " ";
    cout << "]\n";
    if (n == 1)
        return;
    for (int i = 1; i < n; i++)
        a[i] += a[i + 1];
    xuli(n - 1);
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        xuli(n);
    }
}