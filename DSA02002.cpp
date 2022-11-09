#include <bits/stdc++.h>
using namespace std;

int t, n, a[20];
vector<string> ans;

void xuli(int n)
{
    string s = "[";
    for (int i = 1; i <= n; i++)
    {
        stringstream ss;
        string x;
        ss << a[i];
        ss >> x;
        if (i == n)
            s += x;
        else
            s += x + ' ';
    }
    s += ']';
    ans.push_back(s);
    if (n == 1)
        return;
    for (int i = 1; i < n; i++)
        a[i] += a[i + 1];
    xuli(n - 1);
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        xuli(n);
        for (int i = ans.size() - 1; i >= 0; i--)
            cout << ans[i] << " ";
        cout << endl;
        ans.clear();
    }
}