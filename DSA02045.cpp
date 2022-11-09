#include <bits/stdc++.h>
using namespace std;

int t, n;
string s;

void xuli(string x, int trc)
{
    if (x != "")
        cout << x << " ";
    if (trc == -1)
        for (int i = 0; i < s.size(); i++)
            xuli(x + s[i], i);
    else
        for (int i = trc + 1; i < s.size(); i++)
            xuli(x + s[i], i);
    return;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> s;
        xuli("", -1);
        cout << endl;
    }
}