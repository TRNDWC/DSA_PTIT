#include <bits/stdc++.h>
using namespace std;

char c;
bool ck[50];

void xuli(string s, int len)
{
    if (len >= 3)
    {
        if (s[len - 2] == 'A' && s[len - 1] != 'E' && s[len - 3] != 'E')
            return;
        if (s[len - 2] == 'E' && s[len - 1] != 'A' && s[len - 3] != 'A')
            return;
    }
    if (len == int(c - 'A') + 1)
    {
        cout << s << endl;
        return;
    }
    for (int i = 0; i <= int(c - 'A'); i++)
        if (ck[i] == 0)
        {
            char kt = 'A' + i;
            ck[i] = 1;
            xuli(s + kt, len + 1);
            ck[i] = 0;
        }
}

int main()
{
    cin >> c;
    memset(ck, 0, sizeof(ck));
    xuli("", 0);
}