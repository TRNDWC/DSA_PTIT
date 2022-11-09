#include <bits/stdc++.h>
using namespace std;

int t, n;

void sinh(string s, int len, char duoi)
{
    if (len == n - 1)
    {
        cout << s << 'A' << endl;
        return;
    }
    if (duoi == 'H')
    {
        sinh(s + "A", len + 1, 'A');
    }
    else
    {
        sinh(s + "A", len + 1, 'A');
        sinh(s + "H", len + 1, 'H');
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        sinh("H", 1, 'H');
    }
}