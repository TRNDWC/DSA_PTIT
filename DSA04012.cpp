#include <bits/stdc++.h>
using namespace std;

int t, n, m;
long long a[101], b[101], ans[10001];

int main()
{
    cin >> t;
    while (t--)
    {
        memset(ans,0,sizeof(ans));
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                ans[i + j] += a[i] * b[j];
                //cout << i + j << " " << a[i] * b[j] << endl;
            }
        for (int i = 0; i <= (m - 1) + (n - 1); i++)
            cout << ans[i] << " ";
        cout << endl;
    }
}