#include <bits/stdc++.h>
using namespace std;

int t;
string s;

int main()
{
    cin >> t;
    while (t--)
    {
        stack<string> toantu;
        cin >> s;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                string kt = "";
                kt += s[i];
                toantu.push(kt);
            }
            else
            {
                string sh1 = toantu.top();
                toantu.pop();
                string sh2 = toantu.top();
                toantu.pop();
                string th = "(" + sh1 + s[i] + sh2 + ")";
                toantu.push(th);
                // cout << th << endl;
            }
        }
        if (!toantu.empty())
            cout << toantu.top() << endl;
    }
}