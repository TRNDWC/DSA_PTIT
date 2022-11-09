#include <bits/stdc++.h>
using namespace std;

int t, n, m, e, r[1001];
vector<int> a[1001];
int M[1001];
bool f[1001];

string xuli()
{
    for (int i = 1; i <= n; i++)
        M[i] = 1;
    int cl = 1;
    for (int i = 1; i <= n; i++)
        if (f[i] == 0)
        {
            f[i] = 1;
            queue<int> q;
            q.push(i);
            while (q.size())
            {
                int x = q.front();
                q.pop();
                for (int y : a[x])
                {
                    if (M[y] == M[x])
                        M[y]++;
                    cl = max(cl, max(M[x], M[y]));
                    if (cl > 2)
                    {
                        return "NO\n";
                    }
                    if (f[y] == 0)
                    {
                        q.push(y);
                        f[y] = 1;
                    }
                }
            }
        }
    //cout<<cl<<endl;
    return "YES\n";
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m;

        for (int i = 1; i <= 1000; i++)
            a[i].clear();
        memset(f, 0, sizeof(f));

        for (int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        cout << xuli();
    }
}