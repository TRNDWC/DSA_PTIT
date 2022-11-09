#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;
    string s;
    int n;
    cin >> n;
    while (n--)
    {
        cin >> s;
        if (s == "PUSH")
        {
            int so;
            cin >> so;
            q.push(so);
        }
        else if (s == "POP")
        {
            if (q.size() != 0)
                q.pop();
        }
        else if (s == "PRINTFRONT")
        {
            if (q.size() != 0)
                cout << q.front() << endl;
            else
                cout << "NONE\n";
        }
    }
}