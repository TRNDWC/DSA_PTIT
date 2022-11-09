#include <bits/stdc++.h>
using namespace std;

int t, n, sl7, left_4;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        sl7 = n / 7;
        left_4 = n % 7;
        bool kt = false;
        while (sl7 > 0)
        {
            if (left_4 % 4 == 0)
            {
                kt = true;
                break;
            }
            sl7--;
            left_4 += 7;
        }
        if (kt == true)
        {
            for (int i = 1; i <= left_4 / 4; i++)
                cout << 4;
            for (int i = 1; i <= sl7; i++)
                cout << 7;
            cout << endl;
        }
        else
            cout << -1 << endl;
    }
}