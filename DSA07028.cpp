#include <bits/stdc++.h>
using namespace std;

long t, n, a[500001];

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        stack<int> san;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
        {
            while (san.size() != 0 && a[san.top()] <= a[i])
                san.pop();
            if (san.size() == 0)
            {
                cout << i << " ";
                san.push(i);
            }
            else
            {
                cout << i - san.top() << " ";
                san.push(i);
            }
        }
        cout << endl;
    }
}
