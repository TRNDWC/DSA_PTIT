#include <bits/stdc++.h>
using namespace std;

int ktra(int *M, int n)
{
    if (n < 2)
        return 1;
    for (int i = 1; i < n; i++)
        if (M[i - 1] >= M[i])
            return 0;
    return 1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, M[100000];
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> M[i];
        cout << ktra(M, n) << endl;
    }
    return 0;
}