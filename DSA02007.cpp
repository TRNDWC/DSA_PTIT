#include <bits/stdc++.h>
using namespace std;

int t, k;
string s, ans;

void xuli(string s, int count)
{
    ans = max(ans, s);
    if (count == k)
    {
        return;
    }
    bool kt=false;
    for (int i = 0; i < s.size(); i++)
        for (int j = i + 1; j < s.size(); j++)
            if (s[j] > s[i])
            {
                kt=true;
                swap(s[i], s[j]);
                xuli(s, count + 1);
                swap(s[i], s[j]);
            }
    if (kt==false) return;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> k;
        cin >> s;
        ans = "";
        xuli(s, 0);
        cout << ans << endl;
    }
}