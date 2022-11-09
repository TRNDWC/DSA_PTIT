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
        vector<int> M;
        for (int i = 0; i < n; i++)
        {
            int so;
            cin >> so;
            M.push_back(so);
        }
        sort(M.begin(), M.end());
        cout << M[(n - 1) / 2] << endl;
    }
    return 0;
}
