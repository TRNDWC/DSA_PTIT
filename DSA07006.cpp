#include <bits/stdc++.h>
using namespace std;

string s;
vector<pair<int, int>> ar;
vector<string> ans;
int gt;

void xuli(string x)
{
    bool kt = false;
    string tam = s;
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] == '1')
        {
            kt = true;
            int vt1, vt2;
            vt1 = ar[i].first;
            vt2 = ar[i].second;
            tam[vt1] = '%';
            tam[vt2] = '%';
        }
    }
    string kq = "";
    for (int i = 0; i < tam.size(); i++)
        if (tam[i] != '%')
            kq += tam[i];
    if (kt == false)
        return;
    // cout << kq << " " << x << endl;
    ans.push_back(kq);
    return;
}

void sinh(string x, int sl)
{
    if (sl == gt)
    {
        xuli(x);
        return;
    }
    sinh(x + '0', sl + 1);
    sinh(x + '1', sl + 1);
}

int main()
{
    cin >> s;
    int stt = 0;
    stack<int> a;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            a.push(i);
        }
        else if (s[i] == ')')
        {
            ar.push_back(make_pair(a.top(), i));
            a.pop();
        }
    }
    gt = ar.size();
    ans.clear();
    sinh("", 0);
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i] == ans[i - 1])
            continue;
        cout << ans[i] << endl;
    }
}