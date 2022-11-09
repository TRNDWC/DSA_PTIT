#include <bits/stdc++.h>
using namespace std;

int t, n, a[1001];

bool ktnt(int so)
{
    if (so <= 1)
        return false;
    if (so == 2)
        return true;
    for (int i = 2; i * i <= so; i++)
    {
        if (so % i == 0)
            return false;
    }
    return true;
}

void xuli(string s)
{
    // cout << s << endl;
    int vt_trc = -1;
    int tong = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            if (vt_trc == -1)
                vt_trc = i;
            else if (a[vt_trc + 1] < a[i + 1])
                return;
            tong += a[i + 1];
        }
    }
    // cout << tong << endl;
    if (ktnt(tong) == false)
        return;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '1')
            cout << a[i + 1] << " ";
    cout << endl;
    return;
}

void sinh(string s, int sl)
{
    if (sl == n)
    {
        xuli(s);
        return;
    }
    sinh(s + '0', sl + 1);
    sinh(s + '1', sl + 1);
}

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1, cmp);
        sinh("", 0);
    }
}