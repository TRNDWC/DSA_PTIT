#include <bits/stdc++.h>
using namespace std;

int t, n;
long long a[100001], k;

bool test(int n, long long k)
{
    int l = 1;
    long long to = 0;
    for (int r = 1; r <= n; r++)
    {
        to += a[r]; 
        while (l < r && to > k)
        {
            to -= a[l];
            l++;
        }
        if (to == k)
            return true;
    }
    return false;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        if (test(n, k) == true)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}