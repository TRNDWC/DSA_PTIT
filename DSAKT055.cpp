#include <bits/stdc++.h>
using namespace std;

long long n, w[1001], c[1001], k, t;
long long f[1001][1001];

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> w[i];
        for (int i = 1; i <= n; i++)
            cin >> c[i];
        memset(f, 0, sizeof(f));

        // goi f[i][j] la gia tri lon nhat khi xet den phan tu thu i va co khoi luong la j
        // f[0][0]=1;
        // f[i]=f[j]+w[i] (f[j]+w[i]<=c);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                if (j - w[i] >= 0)
                    f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i]] + c[i]);
                else
                    f[i][j] = f[i - 1][j];
            }
        }
        cout<<f[n][k]<<endl;
    }
}