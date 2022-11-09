#include <bits/stdc++.h>
using namespace std;

int t, ans;
string s;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> s;
        stack<int> vt;
        vt.push(-1);
        ans=0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                vt.push(i);
            else
            {
                vt.pop();
                if (vt.size() != 0)
                {
                    ans = max(ans, i - vt.top());
                }
                if (vt.size() == 0)
                    vt.push(i);
            }
        }
        cout<<ans<<endl;
    }
}