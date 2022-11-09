#include <bits/stdc++.h>
using namespace std;

struct kdl
{
    int so;
    int len = 0;
};

bool ktnt(int x)
{
    if (x < 1)
        return 0;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return 0;
    return 1;
}

bool test(int a, int b)
{
    int d=0;
    while (a != 0)
    {
        int s1 = a % 10;
        int s2 = b % 10;
        if (s1 != s2)
            d++;
        if (d > 1)
            return false;
        a /= 10;
        b /= 10;
    }
    return true;
}

bool f[10001];
int t, s, e;
vector<int> snt;

int main()
{
    for (int i = 1000; i <= 9999; i++)
        if (ktnt(i) == true)
            snt.push_back(i);

    cin >> t;
    while (t--)
    {
        cin >> s >> e;
        memset(f, 0, sizeof(f));
        queue<kdl> q;
        q.push({s, 0});
        while (q.size())
        {
            kdl k = q.front();
            q.pop();
            if (f[k.so] == 1)
                continue;
            f[k.so] = 1;
            //cout << k.so << endl;
            if (k.so == e)
            {
                cout << k.len << endl;
                break;
            }
            for (int i = 0; i < snt.size(); i++)
                if (f[snt[i]] == 0 && test(snt[i], k.so) == true)
                {
                    q.push({snt[i], k.len + 1});
                }
        }
    }
}