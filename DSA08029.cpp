#include <bits/stdc++.h>
using namespace std;

int t;

struct kdl
{
    string f = "";
    int len = 0;
};

int main()
{
    cin >> t;
    while (t--)
    {
        kdl s, e;
        set<string> dd;
        for (int i = 1; i <= 6; i++)
        {
            char so;
            cin >> so;
            s.f += so;
        }
        for (int i = 1; i <= 6; i++)
        {
            char so;
            cin >> so;
            e.f += so;
        }
        queue<kdl> q;
        q.push(s);
        while (q.size())
        {
            kdl fr = q.front();
            q.pop();
            auto it = dd.find(fr.f);
            if (it != dd.end())
                continue;
            //cout<<fr.f<<endl;
            dd.insert(fr.f);
            if (fr.f == e.f)
            {
                cout << fr.len << endl;
                break;
            }
            string tam = "";
            tam += fr.f[3];
            tam += fr.f[0];
            tam += fr.f[2];
            tam += fr.f[4];
            tam += fr.f[1];
            tam += fr.f[5];
            q.push({tam, fr.len + 1});
            tam = "";
            tam += fr.f[0];
            tam += fr.f[4];
            tam += fr.f[1];
            tam += fr.f[3];
            tam += fr.f[5];
            tam += fr.f[2];
            q.push({tam, fr.len + 1});
        }
    }
}