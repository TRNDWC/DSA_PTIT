#include <bits/stdc++.h>
using namespace std;

int t, f[1001][1001];
string x, y;

int main()
{
    cin >> t;
    while (t--)
    {
        memset(f, 0, sizeof(f));
        cin >> x >> y;

        // f[i][j] la do dai xau lon nhat khi xet den vi tri i cua xau x va vitri j cua xau i
        // f[i][j]=f[i-1][j-1]+1;
        // f[i][j]=max(f[i-1][j],f[i][j-1]);

        x = " " + x;
        y = " " + y;

        for (int i = 1; i < x.size(); i++)
            for (int j = 1; j < y.size(); j++)
            {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                if (x[i] == y[j])
                    f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
            }

        cout << f[x.size() - 1][y.size() - 1] << endl;
    }
}