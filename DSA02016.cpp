#include <bits/stdc++.h>
using namespace std;

int t, n, m, d;
bool a[1001][1001];

bool check(int x, int y)
{
    for (int i = 1; i <= n; i++)
        if (a[x][i] == 1)
            return false;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= y; j++)
            if (a[i][j] == 1 && abs(i - x) == abs(j - y))
                return false;
    return true;
}

void dat(int stt)
{
    if (stt == n + 1)
    {
        d++;
        /*for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                cout << a[i][j];
            cout << endl;
        }*/
        return;
    }
    for (int i = 1; i <= n; i++)
        if (check(i, stt) == true)
        {
            a[i][stt] = 1;
            dat(stt + 1);
            a[i][stt] = 0;
        }
}
int main()
{
    cin >> t;
    while (t--)
    {
        memset(a, 0, sizeof(a));
        cin >> n;
        d = 0;
        dat(1);
        cout << d << endl;
    }
}