#include <bits/stdc++.h>
using namespace std;

int s, n, k, d;

void sinh(int sl, int tong, int so_trc)
{
    if (tong > s)
        return;
    if (sl == k)
    {
        if (tong == s)
            d++;
        return;
    }
    for (int i = so_trc + 1; i <= n; i++)
        sinh(sl + 1, tong + i, i);
}

int main()
{
    while (true)
    {
        cin >> n >> k >> s;
        if (n == 0 && k == 0 && s == 0)
            break;
        d = 0;
        sinh(0, 0, 0);
        cout << d << endl;
    }
}
