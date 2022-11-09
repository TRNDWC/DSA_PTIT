#include <bits/stdc++.h>
using namespace std;

int n, a[10001];
vector<string> ans;

void xuli(string s, int sl, int so_trc)
{
    if (sl >= 2)
        ans.push_back(s);
    for (int i = so_trc + 1; i <= n; i++)
        if (a[i] > a[so_trc])
        {
            stringstream ss;
            string x;
            ss << a[i];
            ss >> x;
            xuli(s + x + " ", sl + 1, i);
        }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[0] = -1;
    ans.clear();
    xuli("", 0, 0);
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
}