#include <bits/stdc++.h>
using namespace std;

int n, a[100001], f[100001];

int main()
{
    cin >> n;
    int k = 0;
    for (int i = 1; i <= n; i++)
    {
        int so;
        cin >> so;
        f[so] = f[so - 1] + 1;
        k = max(k, f[so]);
    }
    cout << n - k << endl;
}