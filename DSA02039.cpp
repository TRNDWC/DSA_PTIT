#include <bits/stdc++.h>
using namespace std;

int t, n;
vector<string> ans;

void xuli(string s, int gt, int trc)
{
    if (gt == 0)
    {
        s.erase(s.size() - 1, 1);
        ans.push_back(s);
        return;
    }
    for (int i = gt; i >= 1; i--)
        if (i <= trc)
        {
            stringstream ss;
            string x;
            ss << i;
            ss >> x;
            xuli(s + x + ' ', gt - i, i);
        }
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        ans.clear();
        xuli("", n, n);
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
            cout << '(' << ans[i] << ") ";
        cout << endl;
    }
}