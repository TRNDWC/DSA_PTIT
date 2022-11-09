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
        int M[100000];
        for (int i = 0; i < n; i++)
            cin >> M[i];
        vector<int> dpl(n, 1), dpr(n, 1);
        for (int i = 1; i < n; i++)
            if (M[i] > M[i - 1])
                dpl[i] += dpl[i - 1];
        for (int i = n - 2; i >= 0; i--)
            if (M[i] > M[i + 1])
                dpr[i] += dpr[i + 1];
        int res = 0;
        for (int i = 0; i < n; i++)
            res = max(res, dpl[i] + dpr[i] - 1);
        cout << res << endl;
    }
}