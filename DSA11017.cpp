#include <bits/stdc++.h>
using namespace std;

int t, n, a[1001];

void in(int l, int r)
{
    if (l > r)
        return;
    if (l == r)
    {
        cout << a[l] << " ";
        return;
    }
    int i;
    for (i = l + 1; i <= r; i++)
        if (a[i] > a[l])
            break;
    in(l + 1, i - 1);
    in(i, r);
    cout << a[l] << " ";
    return;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        in(1, n);
        cout<<endl;
    }
}