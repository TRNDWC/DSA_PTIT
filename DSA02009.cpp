#include <bits/stdc++.h>
using namespace std;

int n, k, a[21], t, gt;
bool kt, f[21];

void xuli(int so_nhom, int tong)
{
    cout << so_nhom << " " << tong << endl;
    if (kt == true)
        return;
    if (so_nhom == k - 1)
    {
        kt = true;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (f[i] == 0)
        {
            f[i] = 1;
            if (tong + a[i] == gt)
                xuli(so_nhom + 1, 0);
            else if (tong + a[i] < gt)
                xuli(so_nhom, tong + a[i]);
            else
                return;
        }
        f[i] = 0;
    }
    return;
}
int main()
{
    cin >> t;
    while (t--)
    {
        int tong = 0;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            tong += a[i];
        }
        if (tong % k != 0)
            cout << 0 << endl;
        else
        {
            gt = tong / k;
            kt = false;
            memset(f, 0, sizeof(f));
            xuli(0, 0);
            if (kt == false)
                cout << 0 << endl;
            else
                cout << 1 << endl;
        }
    }
}