#include <bits/stdc++.h>
using namespace std;

int t, n;
int f[10001];

int main()
{
    for (int i = 1; i <= 10000; i++)
        f[i] = 1000000000;
    f[1] = 1;
    for (int i = 2; i <= 10000; i++)
    {
        for (int j = 1; j * j <= i; j++)
            if (i - j * j >= 0)
                f[i] = min(f[i], f[i - j * j] + 1);
    }
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << f[n] << endl;
    }
}