#include <bits/stdc++.h>
using namespace std;

int n, k, f[50][50], t;
vector<int> a;
vector<vector<int>> ans;

int giaithua(int n)
{
    int tu = 1;
    for (int i = 1; i <= n; i++)
        tu *= i;
    return tu;
}

void in()
{
    int t = 0;
    for (int i = 0; i < a.size(); i++)
    {
        t += f[i + 1][a[i]];
    }
    if (t == k)
        ans.push_back(a);
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> f[i][j];
    int loops = giaithua(n);
    for (int i = 1; i <= n; i++)
        a.push_back(i);
    while (loops--)
    {
        in();
        int vt;
        bool ck = false;
        for (int i = a.size() - 2; i >= 0; i--)
            if (a[i] < a[i + 1])
            {
                vt = i;
                ck = true;
                break;
            }
        if (ck == true)
        {
            int v = vt + 1;
            for (int i = vt + 1; i < a.size(); i++)
                if (a[i] > a[vt] && a[i] < a[v])
                    v = i;
            swap(a[vt], a[v]);
            for (int i = vt + 1; i < a.size(); i++)
                for (int j = i + 1; j < a.size(); j++)
                    if (a[i] > a[j])
                        swap(a[i], a[j]);
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}
