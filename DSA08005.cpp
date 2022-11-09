#include <bits/stdc++.h>
using namespace std;

int n, t;

int main()
{
    cin >> t;
    while (t--)
    {
        queue<string> q;
        cin >> n;
        q.push("1");
        while (n--)
        {
            string ans = q.front();
            q.pop();
            cout << ans << " ";
            q.push(ans + "0");
            q.push(ans + "1");
        }
        cout<<endl;
    }
}