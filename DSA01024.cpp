#include <bits/stdc++.h>
using namespace std;

int n, k, d;
string a[101], b[101];

void sinh(string s, int sl, int vt_trc)
{
    if (sl == k)
    {
        cout << s << endl;
        return;
    }
    for (int i = vt_trc + 1; i <= d; i++)
        sinh(s + b[i] +" ", sl + 1, i);
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    d = 1;
    b[1] = a[1];
    for (int i = 2; i <= n; i++)
        if (a[i] != a[i - 1])
        {
            d++;
            b[d] = a[i];
        }
    //cout << d << endl;
    sinh("", 0, 0);
}