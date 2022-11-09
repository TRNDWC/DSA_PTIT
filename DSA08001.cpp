#include <bits/stdc++.h>
using namespace std;

int t, so, k, n;

int main()
{
    cin >> k;
    while (k--)
    {
        cin >> n;
        queue<int> q;
        while (n--)
        {
            cin>>t;
            if (t == 3)
                cin >> so;
            if (t == 1)
            {
                cout << q.size() << endl;
            }
            else if (t == 2)
            {
                if (q.size() == 0)
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
            else if (t == 3)
            {
                q.push(so);
            }
            else if (t == 4)
            {
                if (q.size() != 0)
                    q.pop();
            }
            else if (t == 5)
            {
                if (q.size() != 0)
                    cout << q.front() << endl;
                else
                    cout << -1 << endl;
            }
            else
            {
                if (q.size() != 0)
                    cout << q.back() << endl;
                else
                    cout << -1 << endl;
            }
        }
    }
}
