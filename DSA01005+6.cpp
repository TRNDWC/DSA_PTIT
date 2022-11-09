#include <bits/stdc++.h>
using namespace std;

int n, k, a[10001], t;

int giaithua(int n)
{
    int tu = 1;
    for (int i = 1; i <= n; i++)
        tu *= i;
    return tu;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        int loops = giaithua(n) - 1;
        for (int i = 1; i <= n; i++)
        {
            a[i] = n-i+1;
            cout << n-i+1;
        }
        cout << " ";
        while (loops--)
        {
            int vt;
            bool k = false;
            for (int i = n - 1; i >= 1; i--)
                if (a[i] > a[i + 1])
                {
                    vt = i;
                    k = true;
                    break;
                }
            if (k == false)
            {
                for (int i = 1; i <= n; i++)
                    cout << a[i];
            }
            else
            {
                int v = vt + 1;
                for (int i = vt + 1; i <= n; i++)
                    if (a[i] < a[vt] && a[i] > a[v])
                        v = i;
                swap(a[vt], a[v]);
                for (int i = vt + 1; i <= n; i++)
                    for (int j = i + 1; j <= n; j++)
                        if (a[i] < a[j])
                            swap(a[i], a[j]);
                for (int i = 1; i <= n; i++)
                    cout << a[i];
            }
            cout << " ";
        }
        cout << endl;
    }
}
