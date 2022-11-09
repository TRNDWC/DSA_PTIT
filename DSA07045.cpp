#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
    cin >> s;
    stack<char> a, b;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '<')
        {
            if (a.size())
            {
                b.push(a.top());
                a.pop();
            }
        }
        else if (s[i] == '>')
        {
            if (b.size())
            {
                a.push(b.top());
                b.pop();
            }
        }
        else if (s[i] == '-')
        {
            if (a.size())
                a.pop();
        }
        else
            a.push(s[i]);
    }
    while (a.size())
    {
        b.push(a.top());
        a.pop();
    }
    while (b.size())
    {
        cout<<b.top();
        b.pop();
    }
}
