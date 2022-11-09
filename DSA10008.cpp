#include <bits/stdc++.h>
using namespace std;

int t, m, n, u;
vector<pair<int, int>> a[1001];
long long d[1001];
bool ck[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
    cin >> t;
    while (t--)
    {

        //
        for (int i = 1; i <= 1000; i++)
        {
            a[i].clear();
            d[i] = INT_MAX;
        }
        //

        cin >> n >> m >> u;
        for (int i = 1; i <= m; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            a[x].push_back({y, z});
            a[y].push_back({x, z});
        }

        d[u] = 0;
        pq.push({0, u});
        while (pq.size())
        {
            pair<int, int> v = pq.top();
            pq.pop();
            for (pair<int, int> x : a[v.second])
                if (d[x.first] > d[v.second] + x.second)
                {
                    d[x.first] = d[v.second] + x.second;
                    pq.push({d[x.first], x.first});
                }
        }

        for (int i = 1; i <= n; i++)
            cout << d[i] << " ";
        cout << endl;
    }
}