#include <bits/stdc++.h>
using namespace std;

int n, m, k, a[100001], b[100001], c[100001], t;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= m; i++)
            cin >> b[i];
        for (int i = 1; i <= k; i++)
            cin >> c[i];
        int x, y, z;
        x = 1;
        y = 1;
        z = 1;
        bool kt = false;
        while (true)
        {
            //cout<<x<<" "<<y<<" "<<z<<endl;
            //cout<<a[x]<<" "<<b[y]<<" "<<c[z]<<endl<<endl;
            long long gt = max(a[x], max(b[y], c[z]));
            if (a[x] == gt && b[y] == gt && c[z] == gt)
            {
                kt = true;
                cout << a[x] << " ";
                x++;
                y++;
                z++;
                continue;
            }
            if (a[x] < gt)
                x++;
            if (b[y] < gt)
                y++;
            if (c[z] < gt)
                z++;
            if (x > n || y > m || z > k)
                break;
        }
        if (kt == false)
            cout << "NO";
        cout<<endl;
    }
}