#include <bits/stdc++.h>
using namespace std;

string lonnhat, benhat;
int n, s, luu;

int main()
{
    cin >> n >> s;
    if (9 * n < s || s == 0 || n == 0)
    {
        cout << -1 << " " << -1;
        return 0;
    }
    int cs = 9;
    lonnhat = "";
    luu = s;
    for (int i = 1; i <= n; i++)
    {
        while (s < cs && cs > 0)
            cs--;
        lonnhat += ('0' + cs);
        s -= cs;
    }
    s = luu;
    s -= 1;
    benhat = '1';
    for (int i = 1; i < n; i++)
        benhat += '0';
    for (int i = n - 1; i >= 0; i--)
    {
        cs = benhat[i] - '0';
        if (s >= 9 - cs)
        {
            benhat[i] = '9';
            s -= (9 - cs);
        }
        else
        {
            benhat[i] = '0' + cs + s;
            s = 0;
        }
        if (s == 0)
            break;
    }
    cout << benhat << " " << lonnhat;
}