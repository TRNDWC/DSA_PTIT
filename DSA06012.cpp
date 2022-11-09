#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int M[100000];
        for (int i = 0; i < n; i++)
            cin >> M[i];
        sort(M, M + n, greater<>());
        for (int i = 0; i < k; i++)
            cout << M[i] << " ";
        cout << endl;
    }
}