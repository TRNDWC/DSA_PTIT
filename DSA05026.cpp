#include <bits/stdc++.h>
using namespace std;

long long n, w[101], c;
bool f[101][25001];

int main()
{
    cin >> c >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i];

    memset(f, 0, sizeof(f));

    // goi f[i][j] la co hoac khong neu ton tai 1 day con bo co tong bang k
    // f[0][0]=1;
    // f[i]=f[j]+w[i] (f[j]+w[i]<=c);

    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        f[i][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            f[i][j] = f[i - 1][j];
            if (j - w[i] >= 0)
                f[i][j] = max(f[i][j], f[i - 1][j - w[i]]);
        }
    }
    long long ans = -1;
    for (int i = c; i >= 1; i--)
        if (f[n][i] == 1)
        {
            ans = i;
            break;
        }
    cout << ans << endl;
}