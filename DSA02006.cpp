#include <bits/stdc++.h>
using namespace std;

int t, n, k, a[10001];
vector<string> ans;
bool kt;

void xuli(string kq, int tong, int so_trc)
{
    if (tong > k)
        return;
    if (tong == k)
    {
        kq.erase(kq.size() - 1, 1);
        kq += ']';
        ans.push_back(kq);
        kt=true;
        return;
    }
    for (int i = so_trc + 1; i <= n; i++)
    {
        stringstream ss;
        string x;
        ss << a[i];
        ss >> x;
        xuli(kq + x + " ", tong + a[i], i);
    }
}
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        ans.clear();
        kt = false;
        xuli("[", 0, 0);
        if (kt == false)
            cout << -1;
        else
            for (int i = 0; i < ans.size(); i++)
                cout << ans[i] << " ";
        cout << endl;
    }
}
