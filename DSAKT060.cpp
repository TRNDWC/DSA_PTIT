#include <bits/stdc++.h>
using namespace std;

string ST[400001], s;

void build(int id, int l, int r)
{
    if (l == r)
    {
        ST[id] = s[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    ST[id] = ST[id * 2] + ST[id * 2 + 1];
    return;
}

void update(int id, int l, int r, int x, string u)
{
    if (x < l || x > r)
        return;
    if (l == r)
    {
        ST[id] = u;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, x, u);
    update(id * 2 + 1, mid + 1, r, x, u);
    ST[id] = ST[id * 2] + ST[id * 2 + 1];
}

string get(int id, int l, int r, int u, int v)
{
    if (r < u || l > v)
    {
        return "";
    }
    if (u <= l && r <= v)
    {
        return ST[id];
    }
    int mid = (l + r) / 2;
    string ans = get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
    return ans;
}

int main()
{
    cin >> s;
    build(1, 0, s.size() - 1);
    int q;
    cin >> q;
    while (q--)
    {
        char k;
        cin >> k;
        if (k == 'q')
        {
            int u, v;
            cin >> u >> v;
            string x = get(1, 0, s.size() - 1, u - 1, v - 1);
            // cout<<x<<endl;
            string tmp = x;
            reverse(tmp.begin(), tmp.end());
            if (x == tmp)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else if (k == 'c')
        {
            int u;
            string v;
            cin >> u >> v;
            update(1, 0, s.size() - 1, u - 1, v);
        }
    }
}