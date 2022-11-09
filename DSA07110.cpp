#include <bits/stdc++.h>
using namespace std;

int t;
string s;

bool check(char m, char n)
{
    if (m == '(' && n == ')')
        return true;
    else if (m == '[' && n == ']')
        return true;
    else if (m == '{' && n == '}')
        return true;
    return false;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> s;
        stack<char> a;
        string ans = "YES";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ')' || s[i] == ']' || s[i] == '}')
            {
                char k = '&';
                if (a.size() > 0)
                    k = a.top();
                bool kt = check(k, s[i]);
                //cout << k << " " << s[i] << endl;
                if (kt == false)
                {
                    ans = "NO";
                    break;
                }
                a.pop();
            }
            else
                a.push(s[i]);
        }
        cout << ans << endl;
    }
}