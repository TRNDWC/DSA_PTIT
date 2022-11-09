#include <bits/stdc++.h>
using namespace std;

int n, ans;
string a[1001];
bool f[1001];

int tinh(int x, int y)
{
    int d = 0;
    for (int i = 0; i < a[x].size(); i++)
        for (int j = 0; j < a[y].size(); j++)
            if (a[x][i] == a[y][j])
            {
                d++;
                break;
            }
    return d;
}

void xuli(int sl, int trc, int dif)
{
    if (sl == n)
    {
        if (ans != -1)
            ans = min(ans, dif);
        else
            ans = dif;
        return;
    }
    if (ans != -1 && dif > ans)
        return;
    for (int i = 1; i <= n; i++)
        if (f[i] == 0)
        {
            f[i] = 1;
            if (sl == 0)
                xuli(sl + 1, i, dif);
            else
            {
                int dif_val = tinh(i, trc);
                xuli(sl + 1, i, dif + dif_val);
            }
            f[i] = 0;
        }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    memset(f, 0, sizeof(f));
    ans = -1;
    xuli(0, 0, 0);
    cout << ans << endl;
}