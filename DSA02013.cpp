#include <bits/stdc++.h>
using namespace std;

int t, k, n, p, s;
bool f[501];
vector<string> ans;

void in(string kq, int sl, int tong, int trc)
{
    if (tong > s)
        return;
    if (sl == n)
    {
        if (tong == s)
            ans.push_back(kq);
        return;
    }
    for (int i = trc + 1; i <= s; i++)
        if (f[i] == 0)
        {
            stringstream ss;
            string x;
            ss << i;
            ss >> x;
            in(kq + x + " ", sl + 1, tong + i, i);
        }
}

int main()
{
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i <= 200; i++)
    {
        if (f[i] == 0)
            for (int j = i * 2; j <= 200; j += i)
                f[j] = 1;
    }
    cin >> t;
    while (t--)
    {
        cin >> n >> p >> s;
        ans.clear();
        in("", 0, 0, p);
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << endl;
    }
}