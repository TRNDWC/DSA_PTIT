#include <bits/stdc++.h>
using namespace std;

int t, l, r, d;

bool test1(string s)
{
    int M[100] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] - 48 > 5)
            return 0;
        M[s[i]]++;
    }
    for (int i = 0; i < 100; i++)
        if (M[i] > 1)
            return 0;
    return 1;
}

int main()
{
    cin >> t;
    while (t--)
    {
        d = 0;
        cin >> l >> r;
        queue<int> q;
        for (int i = 1; i <= 5; i++)
            q.push(i);
        while (q.size())
        {
            int a = q.front();
            q.pop();
            if (a>r) continue;
            if (test1(to_string(a)) == false)
                continue;
            if (a >= l && a <= r)
                d++;
            for (int i = 0; i <= 5; i++)
                q.push(a * 10 + i);
        }
        cout << d << endl;
    }
}
