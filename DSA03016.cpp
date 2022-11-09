#include <bits/stdc++.h>
using namespace std;

int s, d, t;
int ans[1001];

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> s >> d;
        if (s > d * 9)
            cout << -1 << endl;
        else
        {
            memset(ans, 0, sizeof(ans));
            ans[1] = 1;
            s--;
            int vt = d;
            while (s > 0)
            {
                if (s > 9 - ans[vt])
                {
                    s -= (9 - ans[vt]);
                    ans[vt] = 9;
                    vt--;
                }
                else
                {
                    ans[vt] += s;
                    s = 0;
                }
            }
            for (int i = 1; i <= d; i++)
                cout << ans[i];
            cout << endl;
        }
    }
}
