#include <bits/stdc++.h>
using namespace std;

struct kdl
{
    int so = 0;
    int buoc = 0;
};

bool kt[100001];
int s, t;

int main()
{
    int k;
    cin >> k;
    while (k--)
    {
        memset(kt, 0, sizeof(kt));
        cin >> s >> t;
        queue<kdl> q;
        q.push({s, 0});
        int ans = 1000000001;
        while (q.size())
        {
            kdl f = q.front();
            q.pop();
            if (kt[f.so] == 1)
                continue;
            kt[f.so] = 1;
            if (f.so == t)
            {
                ans = min(ans, f.buoc);
            }
            if (f.so * 2 <= 50000)
                q.push({f.so * 2, f.buoc + 1});
            if (f.so - 1 > 0)
                q.push({f.so - 1, f.buoc + 1});
        }
        cout << ans << endl;
    }
}