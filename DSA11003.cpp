#include <bits/stdc++.h>
using namespace std;

int n, pre[50100], vt_in[50100];

void in(int node, int can_duoi, int l, int r)
{
    int vt = vt_in[pre[node]];
    if (vt > l)
    {
        int con_trai = node + 1;
        in(con_trai, node + (vt - l), l, vt - 1);
    }
    if (vt < r)
    {
        int con_phai = can_duoi - (r - (vt + 1) + 1) + 1;
        in(con_phai, can_duoi, vt + 1, r);
    }
    cout << pre[node] << " ";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(pre, 0, sizeof(pre));
        memset(vt_in, 0, sizeof(vt_in));
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int so;
            cin >> so;
            vt_in[so] = i;
        }
        for (int i = 1; i <= n; i++)
            cin >> pre[i];
        in(1, n, 1, n);
        cout<<endl;
    }
}