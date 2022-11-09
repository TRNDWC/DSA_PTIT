#include <bits/stdc++.h>
using namespace std;

int n, k, t, a[10001];
bool f[10001];
vector<string> ans;

void sinh(string s, int sl, int trc)
{
    if (sl == k)
    {
        ans.push_back(s);
        return;
    }
    for (int i = 1; i <= n; i++)
        if (a[i] > a[trc] && f[i] == 0)
        {
            stringstream ss;
            ss << a[i];
            string x;
            ss >> x;
            f[i] = 1;
            sinh(s + x + ' ', sl + 1, i);
            f[i] = 0;
        }
    return;
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
        a[0] = a[1] - 1;
        memset(f, 0, sizeof(f));
        ans.clear();
        sinh("", 0, 0);
        // sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << endl;
    }
}
