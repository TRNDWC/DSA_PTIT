#include <bits/stdc++.h>
using namespace std;

long long f[101], k;
int t,n;

char tim(long long k, int n)
{
    if (n == 1)
        return 'A';
    if (n == 2)
        return 'B';
    if (k <= f[n - 2])
        return tim(k, n - 2);
    else
        return tim(k - f[n - 2], n - 1);
}

int main()
{
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i <= 93; i++)
        f[i] = f[i - 1] + f[i - 2];
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        cout << tim(k, n) << endl;
    }
}