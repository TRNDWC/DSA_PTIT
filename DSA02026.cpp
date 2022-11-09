#include <bits/stdc++.h>
using namespace std;

int t, a[50], n;
string s;
vector<string> ans;

bool xuli(string &s)
{
    string s1, s2, s3, kq;
    s1 = s.substr(0, 2);
    s2 = s.substr(5, 2);
    int so1, so2, so3;
    stringstream ss;
    ss << s1;
    ss >> so1;
    ss.clear();
    ss << s2;
    ss >> so2;
    if (s[3] == '+')
        so3 = so1 + so2;
    else if (s[3] == '-')
        so3 = so1 - so2;
    else if (s[3] == '*')
        so3 = so1 * so2;
    else if (s[3] == '/')
        if (so1 % so2 != 0)
            return false;
        else
            so3 = so1 / so2;
    if (so3 <= 9 || so3 >= 100)
        return false;
    ss.clear();
    ss << so3;
    ss >> s3;
    kq = s.substr(10, 2);
    for (int i = 0; i <= 1; i++)
        if (kq[i] == '?')
        {
            kq[i] = s3[i];
            continue;
        }
        else if (kq[i] != s3[i])
            return false;
    s.erase(10, 2);
    s = s + kq;
    // cout << s << endl;
    return true;
}

void sinh(string cal, int sl)
{
    if (sl == n + 1)
    {
        if (xuli(cal) == true)
        {
            ans.push_back(cal);
            // if (cal[3] == '*' || cal[3] == '/')
            //     cout << cal << endl;
        }
        return;
    }
    if (a[sl] == 3)
    {
        cal[a[sl]] = '+';
        sinh(cal, sl + 1);
        cal[a[sl]] = '-';
        sinh(cal, sl + 1);
        cal[a[sl]] = '*';
        sinh(cal, sl + 1);
        cal[a[sl]] = '/';
        sinh(cal, sl + 1);
    }
    else if (a[sl] == 0 || a[sl] == 5)
    {
        for (char k = '1'; k <= '9'; k++)
        {
            cal[a[sl]] = k;
            sinh(cal, sl + 1);
        }
    }
    else
    {
        for (char k = '0'; k <= '9'; k++)
        {
            cal[a[sl]] = k;
            sinh(cal, sl + 1);
        }
    }
}

int main()
{
    cin >> t;
    while (t--)
    {
        scanf("\n");
        getline(cin, s);
        n = 0;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '?')
            {
                n++;
                a[n] = i;
            }
            else if (s[i] == '=')
                break;
        ans.clear();
        sinh(s, 1);
        if (ans.empty())
            cout << "WRONG PROBLEM!\n";
        else
        {
            sort(ans.begin(), ans.end());
            cout << ans[0] << endl;
        }
    }
}
