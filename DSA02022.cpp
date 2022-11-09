#include <bits/stdc++.h>
using namespace std;

bool check(string s)
{
    if (s[4] == '0')
        return false;
    if (s[2] == '2' && s[3] == '2')
        return false;
    if (s[2] == '2' && s[3] == '0')
        return false;
    if (s[0] == '0' && s[1] == '0')
        return false;
    if (s[2] == '0' && s[3] == '0')
        return false;
    return true;
}

void in(string s)
{
    cout << s[0] << s[1] << "/" << s[2] << s[3] << "/" << s[4] << s[5] << s[6] << s[7] << endl;
}

void sinh(string s, int sl)
{
    if (sl == 8)
    {
        if (check(s))
            in(s);
        return;
    }
    sinh(s + '0', sl + 1);
    sinh(s + '2', sl + 1);
}
int main()
{
    sinh("", 0);
}