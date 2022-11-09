#include <bits/stdc++.h>
using namespace std;

int t, n, a[1001];

void xuli(string s)
{
    // /cout << s << endl;
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
    if (tong % 2 == 0)
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
    sinh(s+'0', sl + 1);
    sinh(s+'1', sl + 1);
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