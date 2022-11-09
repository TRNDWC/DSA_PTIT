#include <bits/stdc++.h>
using namespace std;
int t, n, k;
void sinh(string s, int len, int sl)
{
    if (len == n)
    {
        if (sl==k) 
            cout << s << endl;
        return;
    }
    if (sl > k)
        return;
    sinh(s + '0', len + 1, sl);
    sinh(s + '1', len + 1, sl + 1);
}
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        sinh("", 0, 0);
    }
}