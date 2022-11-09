#include <bits/stdc++.h>
using namespace std;

char c;
int k;

void xuli(string s, int sl, int trc)
{
    if (sl == k)
    {
        cout << s << endl;
        return;
    }
    for (int i = trc; i <= c - 'A'; i++)
    {
        char kt = char('A' + i);
        xuli(s + kt, sl + 1, i);
    }
}
int main()
{
    cin >> c >> k;
    xuli("", 0, 0);
}