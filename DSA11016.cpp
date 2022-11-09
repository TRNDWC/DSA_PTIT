#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        set<int> S;
        for (int i = 0; i < n; i++)
        {
            int u, v;
            char c;
            cin >> u >> v >> c;
            S.insert(u);
            S.insert(v);
        }
        for (auto s : S)
            cout << s << ' ';
        cout << endl;
    }
    return 0;
}