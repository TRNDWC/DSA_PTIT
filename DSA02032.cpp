#include <bits/stdc++.h>
using namespace std;

int t, n, k, a[1001];
vector<string> ans;

void sinh(string s, int tong, int trc)
{
    if (tong > k)
        return;
    if (tong == k)
    {
        s.erase(s.size() - 1, 1);
        ans.push_back(s);
        return;
    }
    for (int i = trc; i <= n; i++)
    {
        stringstream ss;
        string x;
        ss << a[i];
        ss >> x;
        sinh(s + x + " ", tong + a[i], i);
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
        ans.clear();
        sinh("", 0, 1);
        if (ans.empty())
        {
            cout << -1 << endl;
        }
        else
        {
            cout << ans.size() << " ";
            for (int i = 0; i < ans.size(); i++)
                cout << "{" << ans[i] << "} ";
            cout << endl;
        }
    }
}