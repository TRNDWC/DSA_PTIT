#include <bits/stdc++.h>
using namespace std;

long long n, a[20][20], ans;
bool f[20];

void dfs(int start_city, int city_count, long long price)
{
    // cout << start_city << " " << city_count << " " << price << " " << ans << endl;
    if (city_count == n)
    {
        ans = min(ans, price + a[start_city][1]);
        return;
    }
    if (price > ans)
        return;
    for (int i = 2; i <= n; i++)
        if (f[i] == 0)
        {
            f[i] = 1;
            dfs(i, city_count + 1, price + a[start_city][i]);
            f[i] = 0;
        }
    return;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            f[j] = 0;
            cin >> a[i][j];
            ans += a[i][j];
        }
    f[1] = 1;
    dfs(1, 1, 0);
    cout << ans << endl;
}