#include <bits/stdc++.h>
using namespace std;

int main()
{
    deque<int> q;
    string s;
    int n;
    cin >> n;
    while (n--)
    {
        cin >> s;
        if (s == "PUSHFRONT")
        {
            int so;
            cin >> so;
            q.push_front(so);
        }
        else if (s == "PUSHBACK")
        {
            int so;
            cin >> so;
            q.push_back(so);
        }
        else if (s == "POPFRONT")
        {
            if (q.size() != 0)
                q.pop_front();
        }
        else if (s == "POPBACK")
        {
            if (q.size() != 0)
                q.pop_back();
        }
        else if (s == "PRINTFRONT")
        {
            if (q.size() != 0)
                cout << q.front() << endl;
            else
                cout << "NONE\n";
        }
        else if (s == "PRINTBACK")
        {
            if (q.size() != 0)
                cout << q.back() << endl;
            else
                cout << "NONE\n";
        }
    }
}