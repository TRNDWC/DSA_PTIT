#include <bits/stdc++.h>
using namespace std;

int t, n;

int main()
{
    cin >> t;
    while (t--)
    {
        queue<long long> q;
        q.push(9);
        cin >> n;
        long long ans;
        while (true)
        {
            ans = q.front();
            q.pop();
            //cout << ans << endl;
            if (ans != 0 && ans % n == 0)
                break;
            q.push(ans * 10 + 0);
            q.push(ans * 10 + 9);
        }
        cout << ans << endl;
    }
}