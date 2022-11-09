#include <bits/stdc++.h>
using namespace std;

long long n, k, a[200], w[200], ans;
string ans_list;

void xuli(string s)
{
    long long kl = 0;
    long long gt = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '1')
        {
            gt += a[i + 1];
            kl += w[i + 1];
        }
    // cout << gt << " " << kl << endl;
    if (kl > k)
        return;
    if (gt > ans)
    {
        ans = gt;
        ans_list = s;
    }
}
void sinh(string s, int sl)
{
    if (sl == n)
    {
        // cout << s << endl;
        xuli(s);
        return;
    }
    sinh(s + '0', sl + 1);
    sinh(s + '1', sl + 1);
}

int main()
{
    //freopen("data.in","r",stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    ans = -1;
    sinh("", 0);
    cout << ans << endl;
    for (int i = 0; i < ans_list.size(); i++)
        cout << ans_list[i] << " ";
}