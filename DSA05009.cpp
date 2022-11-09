#include <bits/stdc++.h>
using namespace std;

int t, n, a[1001], tong;
bool ck[1001], kt;

void xuli(int val)
{
    if (val > tong / 2)
        return;
    if (kt == true)
        return;
    if (val == tong / 2)
    {
        kt = true;
        return;
    }
    for (int i = 1; i <= n; i++)
        if (ck[i] == 0)
        {
            ck[i] = 1;
            xuli(val + a[i]);
            ck[i] = 0;
        }
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        tong = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            tong += a[i];
        }
        if (tong % 2 != 0)
            cout << "NO\n";
        else
        {
            memset(ck, 0, sizeof(ck));
            kt = false;
            xuli(0);
            if (kt == false)
                cout << "NO\n";
            else
                cout << "YES\n";
        }
    }
}