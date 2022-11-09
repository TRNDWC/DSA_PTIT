#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        set<int> X;
        for (int i = 0; i < n; i++)
        {
            int so;
            cin>>so;
            X.insert(so);
        }
        if (X.count(x) == 0)
            cout << -1 << endl;
        else
            cout << 1 << endl;
    }
}