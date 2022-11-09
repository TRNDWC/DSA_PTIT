#include <bits/stdc++.h>
using namespace std;

bool check[10000];

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
        int N[10] = {0};
        int sum = 0;
        for (int i = 0; i < n; i++)
            N[M[i]]++, sum += M[i];
        bool check = false;
        if (sum % 3 == 1)
        {
            if (N[1] > 0)
                N[1]--, check = true;
            else if (N[4] > 0)
                N[4]--, check = true;
            else if (N[7] > 0)
                N[7]--, check = true;
        }
        else if (sum % 3 == 2)
        {
            if (N[2] > 0)
                N[2]--, check = true;
            else if (N[5] > 0)
                N[5]--, check = true;
            else if (N[8] > 0)
                N[8]--, check = true;
        }
        else
            check = true;
        if (!check)
        {
            cout << -1 << endl;
            continue;
        }
        int k = 10, ok = 1;
        while (k--)
            while (N[k]--)
                cout << k, ok = 0;
        if (ok)
            cout << -1;
        cout << endl;
    }
    return 0;
}