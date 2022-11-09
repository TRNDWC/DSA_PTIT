#include <bits/stdc++.h>
using namespace std;

int n;

string dao(string s)
{
    string ans = "";
    for (int i = 0; i < s.size(); i++)
        ans = s[i] + ans;
    return ans;
}

void sinh(string s, int sl)
{
    if (sl == n / 2)
    {
        s.erase(s.size() - 1, 1);
        string x = dao(s);
        if (n % 2 == 0)
        {
            cout << s << " " << x << endl;
            return;
        }
        else
        {
            cout << s << " 0 " << x << endl;
            cout << s << " 1 " << x << endl;
            return;
        }
    }
    sinh(s + "0 ", sl + 1);
    sinh(s + "1 ", sl + 1);
}

int main()
{
    cin >> n;
    sinh("", 0);
}