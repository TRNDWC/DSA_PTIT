#include <bits/stdc++.h>
using namespace std;

long long ans;
string s, x, a;
int t;

bool ktra(string x)
{
    int vt = 0;
    for (int i = 0; i < x.size(); i++)
    {
        bool k = false;
        for (int j = vt; j < s.size(); j++)
            if (s[j] == x[i])
            {
                vt = j + 1;
                k = true;
                break;
            }
        if (k == false)
            return false;
    }
    return true;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> s;
        bool kt = false;
        for (long long i = 1; i <= 100; i++)
        {
            x = "";
            ans = 0;
            ans = i * i * i;
            x = to_string(ans);
            if (ktra(x) == true)
            {
                kt = true;
                a = x;
            }
        }
        if (kt == false)
            cout << -1 << endl;
        else
            cout << a << endl;
    }
}