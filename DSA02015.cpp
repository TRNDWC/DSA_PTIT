#include <bits/stdc++.h>
using namespace std;

int t;
string s;
vector<string> ans;

bool check(string s)
{
    if (s.size()==0) return false;
    int x = 0, y = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            x++;
            y++;
        }
        if (s[i] == ')')
            x--;
        if (x < 0)
            return false;
    }
    if (y == 0 && s.size() == 1)
        return false;
    return x == 0;
}

void dequy(string s)
{
    if (s.size() == 0)
        return;
    unordered_set<string> mapu;
    queue<string> kho;
    mapu.insert(s);
    kho.push(s);
    bool kt = false;
    while (!kho.empty())
    {
        string x = kho.front();
        kho.pop();
        if (check(x) == true)
        {
            ans.push_back(x);
            kt = true;
        }
        if (kt == true)
            continue;
        for (int i = 0; i < x.size(); i++)
            if (x[i] == '(' || x[i] == ')')
            {
                string tam = x;
                tam.erase(i, 1);
                if (mapu.find(tam) == mapu.end())
                {
                    kho.push(tam);
                    mapu.insert(tam);
                }
            }
    }
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> s;
        ans.clear();
        dequy(s);
        if (ans.empty())
            cout << -1 << endl;
        else
        {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++)
                cout << ans[i] << " ";
            cout << endl;
        }
    }
}


