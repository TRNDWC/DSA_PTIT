#include <bits/stdc++.h>
using namespace std;

int a[10], t, ans;
vector<int> b = {1, 2, 3, 4, 5};
bool kt;

bool xuli(string s)
{
    int t = a[b[0]];
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '+')
            t += a[b[i + 1]];
        else if (s[i] == '-')
            t -= a[b[i + 1]];
        else
            t *= a[b[i + 1]];
    }
    // cout << t << " " << s << endl;
    if (t == 23)
        return true;
    else
        return false;
}

void sinh(string s, int sl)
{
    if (kt == true)
        return;
    if (sl == 4)
    {
        if (xuli(s) == true)
            kt = true;
    }
    else
    {
        sinh(s + '*', sl + 1);
        sinh(s + '+', sl + 1);
        sinh(s + '-', sl + 1);
    }
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> a[1] >> a[2] >> a[3] >> a[4] >> a[5];
        b.clear();
        b={1,2,3,4,5};
        kt = false;
        do
        {
            sinh("", 0);
        } while (next_permutation(b.begin(), b.end()));

        if (kt == true)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}