#include <bits/stdc++.h>
using namespace std;

int n, k, c, a[100001];

void xuli(string s)
{
    long long t = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '1')
            t += a[i];
    if (t == k)
        {for (int i = 0; i < s.size(); i++)
            if (s[i] == '1')
                cout << a[i] << " ";
            cout<<endl;
            c++;
        }
    
}

void sinh(string s, int sl)
{
    if (sl == n)
    {
        xuli(s);
        return;
    }
    sinh(s + '0', sl + 1);
    sinh(s + '1', sl + 1);
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sinh("",0);
    cout<<c;
}