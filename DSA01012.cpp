#include <bits/stdc++.h>
using namespace std;

int t, n;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        int loops = 1;
        string ans = "";
        for (int i = 1; i <= n; i++)
        {
            loops *= 2;
            ans += '0';
        }
        while (loops--)
        {
            cout << ans[0];
            for (int i = 1; i < ans.size(); i++)
            {
                if (ans[i - 1] == '0')
                    cout << ans[i];
                else if (ans[i] == '1')
                    cout << '0';
                else
                    cout << '1';
            }
            cout<<" ";
            int nho = 1;
            for (int i = ans.size() - 1; i >= 0; i--)
            {
                if (nho == 0)
                    break;
                if (ans[i] == '1')
                    ans[i] = '0';
                else
                {
                    ans[i] = '1';
                    nho = 0;
                }
            }
        }
        cout << endl;
    }
}