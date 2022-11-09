#include <bits/stdc++.h>
using namespace std;

int a, b, c, f[10001], t, n;

int main()
{
    int a = 1, b = 1, c = 1;
    f[1] = 1;
    for (int i = 2; i <= 10000; i++)
    {
        f[i] = min(f[a] * 2, min(f[b] * 3, f[c] * 5));
        if (f[i] == f[a] * 2)
            a++;
        if (f[i] == f[b] * 3)
            b++;
        if (f[i] == f[c] * 5)
            c++;
    }
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << f[n] << endl;
    }
}