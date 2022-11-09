#include <bits/stdc++.h>
using namespace std;

int t, f[101][101];
string s;

int main()
{
    cin >> t;
    while (t--)
    {
        memset(f, 0, sizeof(f));
        cin >> s;
        // goi f[i][j] la so ki tu it nhat can xoa de bien doan i j thanh xau doi xung
        for (int len = 2; len <= s.size(); ++len)
        {
            for (int i = 0; i < s.size() - len + 1; ++i)
            {
                int j = i + len - 1;
                if (s[i] == s[j])
                    f[i][j] = f[i + 1][j - 1];
                else
                    f[i][j] = min(f[i + 1][j], f[i][j - 1]) + 1;
            }
        }
        // for (int i = 0; i < s.size(); i++)
        // {
        //     for (int j = 0; j < s.size(); j++)
        //         cout << f[i][j] << " ";
        //     cout << endl;
        // }
        cout << f[0][s.size() - 1] << endl;
    }
}