#include <bits/stdc++.h>
using namespace std;

struct kdl
{
    int id, dl, pro;
};

bool cmp(kdl a, kdl b)
{
    if (a.pro != b.pro)
        return a.pro > b.pro;
    else
        return a.dl < b.dl;
}

int t, n, f[10001], max_dl, sl, ans_pro;
kdl a[10001];

int main()
{
    cin >> t;
    while (t--)
    {
        memset(f, 0, sizeof(f));
        max_dl = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].id;
            cin >> a[i].dl;
            cin >> a[i].pro;
            max_dl = max(max_dl, a[i].dl);
        }
        sort(a + 1, a + n + 1, cmp);
        // for (int i = 1; i <= n; i++)
        //     cout << a[i].pro << endl;
        sl = 0;
        ans_pro = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = a[i].dl; j >= 1; j--)
                if (f[j] == 0)
                {
                    ans_pro += a[i].pro;
                    sl++;
                    f[j] = 1;
                    break;
                }
        }
        cout << sl << " " << ans_pro << endl;
    }
}
