#include <bits/stdc++.h>
using namespace std;

int t, n, ino[1001], ra[10001];

void in(int l, int r)
{
    if (l > r)
        return;
    if (l == r)
    {
        cout << ino[l] << " ";
        return;
    }
    int vt = l;
    for (int i = l; i <= r; i++)
        if (ra[ino[i]] < ra[ino[vt]])
            vt = i;
    in(l, vt - 1);
    in(vt + 1, r);
    cout << ino[vt] << " ";
    return;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> ino[i];
        for (int i = 1; i <= n; i++)
        {
            int so;
            cin >> so;
            ra[so] = i;
        }
        in(1, n);
        cout << endl;
    }
}