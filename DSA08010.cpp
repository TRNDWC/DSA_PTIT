#include <bits/stdc++.h>
using namespace std;

int t, n;
set<int> a;

struct kdl
{
    int so;
    int len = 0;
};

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        queue<kdl> q;
        q.push({n, 0});
        a.clear();
        while (q.size())
        {
            kdl s = q.front();
            q.pop();

            if (s.so < 0)
                continue;
            if (a.count(s.so) != 0)
                continue;

            a.insert(s.so);
            if (s.so == 1 || s.so == 2)
            {
                cout << s.len - 1 + s.so << endl;
                break;
            }
            bool kt = false;
            for (int i = 2; i * i <= s.so; i++)
            {
                if (s.so % i == 0)
                {
                    q.push({max(i, s.so / i), s.len + 1});
                }
            }
            q.push({s.so - 1, s.len + 1});
        }
    }
}