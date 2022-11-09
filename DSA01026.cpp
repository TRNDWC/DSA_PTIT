#include <bits/stdc++.h>
using namespace std;

int n, t;

void sinh(string s, int sl)
{
    // cout << s << " " << sl << endl;
    if (sl >= 5 && s[sl - 1] == '6' && s[sl - 2] == '6' && s[sl - 3] == '6' && s[sl - 4] == '6')
        return;
    if (sl >= 2 && s[sl - 1] == '8' && s[sl - 2] == '8')
        return;
    if (sl == n - 1)
    {
        if (s[sl - 1] == '6' && s[sl - 2] == '6' && s[sl - 3] == '6')
            return;
        cout << s << '6' << endl;
        return;
    }
    sinh(s + '6', sl + 1);
    sinh(s + '8', sl + 1);
}

int main()
{
    cin >> n;
    sinh("8", 1);
}