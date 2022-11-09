#include <bits/stdc++.h>
using namespace std;

int t, n;
long long kq;

void sinh(long long ans, int scs)
{
    if (scs >= 15)
        return;
    if (ans % n == 0)
        kq = min(kq, ans);
    sinh(ans * 10 + 0, scs + 1);
    sinh(ans * 10 + 9, scs + 1);
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        kq = 1000000000000000000;
        sinh(9, 1);
        cout << kq << endl;
    }
}