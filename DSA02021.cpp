#include <bits/stdc++.h>
using namespace std;

long long t, k;
long long f[1001];
string s;

char timkiem(long long n, long long i)
{
    if (n <= s.size())
        return s[n - 1];
    if (n <= f[i - 1])
        return timkiem(n, i - 1);
    else if (n == f[i - 1] + 1)
        return timkiem(f[i - 1], i - 1);
    if (n > f[i - 1] + 1)
        return timkiem(n - f[i - 1] - 1, i - 1);
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> s >> k;
        int i;
        f[1] = s.length();
        for (i = 2;; i++)
        {
            f[i] = f[i - 1] * 2;
            if (f[i] > k)
                break;
        }
        cout << timkiem(k, i) << endl;
    }
}
