#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        vector<int> A[1001];
        while (n--)
        {
            int a, b;
            cin >> a >> b;
            A[a].push_back(b);
        }
        for (int i = 1; i <= m; i++)
        {
            cout << i << ": ";
            for (auto x : A[i])
                cout << x << " ";
            cout << endl;
        }
    }
}