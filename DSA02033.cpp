#include <bits/stdc++.h>
using namespace std;

int t, n;
bool ck[20];

void xuli(int so, int scs)
{
    if (scs >= 2)
    {
        int cs1 = so % 10;
        int cs2 = (so / 10) % 10;
        if (abs(cs1 - cs2) == 1)
            return;
    }
    if (scs == n)
    {
        cout << so << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
        if (ck[i] == 0)
        {
            ck[i] = 1;
            xuli(so * 10 + i, scs + 1);
            ck[i] = 0;
        }
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        memset(ck, 0, sizeof(ck));
        xuli(0, 0);
    }
}