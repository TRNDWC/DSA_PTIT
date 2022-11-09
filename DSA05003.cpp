#include <bits/stdc++.h>
using namespace std;

int t, x, y, z;
string s1, s2, s3;
long long f[101][101][101];

int main()
{
    cin >> t;
    while (t--)
    {
        memset(f, 0, sizeof(f));
        cin >> x >> y >> z;
        cin >> s1 >> s2 >> s3;
        s1 = ' ' + s1;
        s2 = ' ' + s2;
        s3 = ' ' + s3;
        for (int i = 1; i <= x; i++)
            for (int j = 1; j <= y; j++)
                for (int k = 1; k <= z; k++)
                {
                    f[i][j][k] = max(f[i][j][k], f[i - 1][j][k]);
                    f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][k]);
                    f[i][j][k] = max(f[i][j][k], f[i - 1][j][k - 1]);
                    f[i][j][k] = max(f[i][j][k], f[i][j - 1][k]);
                    f[i][j][k] = max(f[i][j][k], f[i][j - 1][k - 1]);
                    f[i][j][k] = max(f[i][j][k], f[i][j][k - 1]);
                    if (s1[i] == s2[j] && s2[j] == s3[k])
                        f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][k - 1] + 1);
                }
        cout << f[x][y][z] << endl;
    }
}