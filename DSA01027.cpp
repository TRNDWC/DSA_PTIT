#include <bits/stdc++.h>
using namespace std;

int n, a[50];

int main()
{
    cin >> n;
    int loops = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        loops *= i;
    }
    sort(a + 1, a + n + 1);
    while (loops--)
    {
        for (int i = 1; i <= n; i++)
            cout << a[i] << " ";
        cout << endl;
        bool conti = true;
        for (int i = n - 1; i >= 1; i--)
            if (a[i] < a[i + 1])
            {
                int vt = i + 1;
                for (int j = i + 1; j <= n; j++)
                    if (a[j] > a[i] && a[j] < a[vt])
                        vt = j;
                swap(a[i], a[vt]);
                sort(a + i + 1, a + n + 1);
                break;
            }
    }
}
