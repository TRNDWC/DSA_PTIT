#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int M[10] = {0};
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            for (int i = 0; i < s.size(); i++)
                M[s[i] - '0']++;
        }
        for (int i = 0; i < 10; i++)
            if (M[i])
                cout << i << " ";
        cout << endl;
    }
}