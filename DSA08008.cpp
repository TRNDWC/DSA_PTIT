#include <bits/stdc++.h>
using namespace std;

long long t,n;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        queue<long long> q;
        q.push(1);
        while (q.size())
        {
            long long tam = q.front();
            q.pop();
            if (tam % n == 0)
            {
                cout << tam << endl;
                break;
            }
            q.push(tam * 10);
            q.push(tam * 10 + 1);
        }
    }
}