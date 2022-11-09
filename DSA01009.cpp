#include <bits/stdc++.h>
using namespace std;

int n, k;
string key;
vector<string> string_list;

void xuli(string s)
{
    string x = s;
    int d = 0;
    for (int i = 0; i <= s.size() - k; i++)
    {
        string tam = s.substr(i, k);
        if (tam == key)
            d++;
    }
    if (d == 1)
        string_list.push_back(s);
}

void sinh(string s, int sl)
{
    if (sl == n)
    {
        xuli(s);
        return;
    }
    sinh(s + 'A', sl + 1);
    sinh(s + 'B', sl + 1);
}

int main()
{
    cin >> n >> k;
    key = "";
    for (int i = 1; i <= k; i++)
        key += 'A';
    sinh("", 0);
    cout << string_list.size() << endl;
    for (int i = 0; i < string_list.size(); i++)
        cout << string_list[i] << endl;
}