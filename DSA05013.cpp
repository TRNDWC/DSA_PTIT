#include <bits/stdc++.h>
using namespace std;

int t, n, k;
long long f[100001], MOD = 1e9 + 7;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        memset(f, 0, sizeof(f));
        // f[i] la so cach buoc tu bac 1 den bac i
        // f[i]=f[i-1]+f[i-2]+..+f[i-k];
        f[1] = 1;
        f[0] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
                if (i - j <= k)
                    f[i] += f[j],
                        f[i] = f[i] % MOD;
                else
                    break;
        }
        cout << f[n] << endl;
        // for (int i = 1; i <= n; i++)
        //     cout << f[i] << " ";
    }
}