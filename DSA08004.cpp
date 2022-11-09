#include <bits/stdc++.h>
using namespace std;

int t, k;
string s;
int f[10001];

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> k;
        cin >> s;
        priority_queue<int> pq;
        memset(f, 0, sizeof(f));
        for (char i : s)
            f[i - 'A']++;
        for (char i = 'A'; i <= 'Z'; i++)
            if (f[i - 'A'] != 0)
                pq.push(f[i - 'A']);
        while (k--)
        {
            if (pq.size() == 0)
                break;
            int x = pq.top();
            pq.pop();
            pq.push(x - 1);
        }
        long long ans = 0;
        while (pq.size() != 0)
        {
            int x = pq.top();
            pq.pop();
            ans += 1LL * x * x;
        }
        cout << ans << endl;
    }
}
