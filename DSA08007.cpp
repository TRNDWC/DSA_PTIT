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
        ans = 0;
        queue<string> q;
        q.push("1");
        while (q.size())
        {
            string tam = q.front();
            q.pop();
            if (tam.size() < s.size() || tam.size() == s.size() && tam <= s)
                ans++;
            else
                break;
            ;
            q.push(tam + '0');
            q.push(tam + '1');
        }
        cout << ans << endl;
    }
}