#include <bits/stdc++.h>
using namespace std;

bool cmp(long long  a, long long  b)
{
    return a > b;
}

long long t, n, ans;
priority_queue<long long , std::vector<long long >, std::function<bool(long long , long long )>> a(cmp);

int main()
{
    cin >> t;
    while (t--)
    {
        while (!a.empty())
            a.pop();
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            long long  so;
            cin >> so;
            a.push(so);
        }
        ans = 0;
        while (true)
        {
            if (a.size() == 1)
            {
                a.pop();
                break;
            }
            long long  d1 = a.top();
            a.pop();
            long long  d2 = a.top();
            a.pop();
            ans += d1 + d2;
            a.push(d1 + d2);
        }
        cout << ans << endl;
    }
}