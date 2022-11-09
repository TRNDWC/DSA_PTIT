#include <bits/stdc++.h>
using namespace std;

int n, k, ans;
string a[50];
bool f[50];

void xuli(string so)
{
    int b[50] = {0};
    for (int i = 0; i < so.size(); i++)
    {
        int vt = so[i] - '0';
        for (int j = 1; j <= n; j++)
        {
            int gt = a[j][vt - 1] - '0';
            b[j] = b[j] * 10 + gt;
        }
    }
    int mi = b[1], ma = b[1];
    for (int i = 1; i <= n; i++)
    {
        mi = min(b[i], mi);
        ma = max(ma, b[i]);
    }
    if (ans == -1)
        ans = ma - mi;
    else
        ans = min(ma - mi, ans);
}

void sinh(string so, int sl)
{
    if (sl == k)
    {
        xuli(so);
        return;
    }
    for (int i = 1; i <= k; i++)
        if (f[i] == 0)
        {
            f[i] = 1;
            char x = '0' + i;
            sinh(so + x, sl + 1);
            f[i] = 0;
        }
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    memset(f, 0, sizeof(f));
    ans = -1;
    sinh("", 0);
    cout << ans << endl;
}