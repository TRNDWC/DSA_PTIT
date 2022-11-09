#include <bits/stdc++.h>
using namespace std;

int t, n, a[100001], k;
deque<int> q;

int main()
{
    cin >> t;
    while (t--)
    {
        q.clear();
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
        {
            while (q.size() && a[i] >= a[q.back()])
                q.pop_back();
            q.push_back(i);
            while (q.size() && q.front() + k <= i)
                q.pop_front();
            if (i >= k)
                cout << a[q.front()] << " ";
        }
        cout << endl;
    }
}