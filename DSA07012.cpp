#include <bits/stdc++.h>
using namespace std;

int t;
string s;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> s;
        stack<string> a;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                string x = "";
                x += s[i];
                a.push(x);
            }
            else
            {
                string sh2 = a.top();
                a.pop();
                string sh1 = a.top();
                a.pop();
                string x = '(' + sh1 + s[i] + sh2 + ')';
                a.push(x);
            }
        }
        cout << a.top() << endl;
    }
}