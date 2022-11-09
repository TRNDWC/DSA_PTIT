#include <bits/stdc++.h>
using namespace std;

long long t, n, MOD = 1e9 + 7;
vector<long long> a;

int main()
{
    cin >> t;
    while (t--)
    {
        a.clear();
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            long long so;
            cin >> so;
            a.push_back(so);
        }
        sort(a.begin(), a.end());
        long long t = 0;
        for (int i = 1; i < a.size(); i++)
            t = (t + (a[i] * i)) % MOD;
        cout << t << endl;
    }
}