#include <bits/stdc++.h>
using namespace std;

long long k, f[50];
int t, n;

char tim(long long k, int n)
{
    if (n == 0)
        return 'A';
    if (k <= f[n - 1])
        return tim(k, n - 1);
    else if (k == f[n - 1] + 1)
        return char('A' + n);
    else
        return tim(k - f[n - 1] - 1, n - 1);
}

int main()
{
    f[0] = 1;
    for (int i = 1; i <= 25; i++)
        f[i] = f[i - 1] * 2 + 1;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        cout << tim(k, n) << endl;
    }
}