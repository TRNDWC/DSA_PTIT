#include <bits/stdc++.h>
using namespace std;

int dout(char k)
{
    if (k == '^')
        return 3;
    else if (k == '*' || k == '/')
        return 2;
    else if (k == '+' || k == '-')
        return 1;
    else
        return 0;
}

int t;
string s;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> s;
        stack<char> a;
        vector<char> kq;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                // cout << s[i] << " ";
                a.push(s[i]);
            }
            else if (s[i] <= 'z' && s[i] >= 'a')
            {
                // cout << s[i] << " ";
                cout << s[i];
                continue;
            }
            else if (s[i] <= 'Z' && s[i] >= 'A')
            {
                // cout << s[i] << " ";
                cout << s[i];
                continue;
            }
            else if (s[i] == ')')
            {
                // cout << s[i] << " ";
                while (a.size() != 0)
                {
                    char dau = a.top();
                    // cout << dau << endl;
                    a.pop();
                    if (dau == '(')
                        break;
                    cout << dau;
                }
            }
            else
            {
                // cout << s[i] << " ";
                char dau = a.top();
                while (a.size() != 0)
                {
                    dau = a.top();
                    if (dout(dau) >= dout(s[i]))
                    {
                        a.pop();
                        cout << dau;
                    }
                    else
                        break;
                }
                a.push(s[i]);
            }
        }
        while (a.size() != 0)
        {
            if (a.top() == '(')
                a.pop();
            else
            {
                cout << a.top();
                a.pop();
            }
        }
        cout << endl;
    }
}