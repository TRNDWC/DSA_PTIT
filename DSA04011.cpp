#include <bits/stdc++.h>
using namespace std;

int t;
string s1,s2;

long long chuyen1(string n)
{
    long long res = 0;
    for (int i = 0; i < n.length(); i++)
    {
        res = res * 2 + n[i] - '0';
    }
    return res;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> s1 >> s2;
        long long so1 = chuyen1(s1);
        long long so2 = chuyen1(s2);
        long long ans = 1ll * so1 * so2;
        cout << ans << endl;
    }
}