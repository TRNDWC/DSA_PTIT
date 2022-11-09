#include <bits/stdc++.h>
using namespace std;

int t;
string s;

int main()
{
    cin >> t;
    while (t--)
    {
        stack<long long> toantu;
        cin >> s;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                int so = s[i] - '0';
                toantu.push(so);
            }
            else
            {
                long long so1 = toantu.top();
                toantu.pop();
                long long so2 = toantu.top();
                toantu.pop();
                long long gt = 0;
                if (s[i] == '+')
                    gt = so1 + so2;
                else if (s[i] == '-')
                    gt = so1 - so2;
                else if (s[i] == '*')
                    gt = so1 * so2;
                else
                    gt = so1 / so2;
                toantu.push(gt);
            }
        }
        if (!toantu.empty())
            cout << toantu.top() << endl;
    }
}