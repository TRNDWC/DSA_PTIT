#include <bits/stdc++.h>
using namespace std;

int n, k, a[1001], ans, gt, f[1001];

void check(string s)
{
    int vtc = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '1')
        {
            int vt = i + 1;
            int t_tam = f[vt] - f[vtc];
            if (t_tam != gt)
                return;
            else
                vtc = vt;
        }
    ans++;
    return;
}

void sinh(string s, int sl, int sl1)
{
    if (sl == n - 1)
    {
        if (sl1 == k - 1)
            check(s);
        //cout << s << " " << ans << endl;
        return;
    }
    sinh(s + '0', sl + 1, sl1);
    if (sl1 < k - 1)
        sinh(s + '1', sl + 1, sl1 + 1);
}

int main()
{
    cin >> n >> k;
    f[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
    }
    gt = f[n] / k;
    if (f[n] % k != 0)
        cout << 0;
    else
    {
        ans = 0;
        sinh("", 0, 0);
        cout << ans;
    }
}
