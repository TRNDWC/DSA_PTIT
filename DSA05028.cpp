#include <bits/stdc++.h>
using namespace std;

int t;
string str1, str2;
int f[101][101];

int main()
{
    cin >> t;
    while (t--)
    {
        memset(f, 0, sizeof(f));
        cin >> str1 >> str2;
        // goi f[i][j] la so phep bien doi it nhat de bien str1[1->i] thanh str2[1->j];
        for (int i = 1; i <= str1.size(); i++)
            f[i][0] = i;
        for (int i = 1; i <= str2.size(); i++)
            f[0][i] = i;
        str1 = ' ' + str1;
        str2 = ' ' + str2;
        for (int i = 1; i < str1.size(); i++)
            for (int j = 1; j <= str2.size(); j++)
                if (str1[i] == str2[j])
                    f[i][j] = f[i - 1][j - 1];
                else
                    f[i][j] = min(f[i - 1][j], min(f[i][j - 1], f[i - 1][j - 1])) + 1;
        cout << f[str1.size() - 1][str2.size() - 1] << endl;
    }
}