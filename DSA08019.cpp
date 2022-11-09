#include <bits/stdc++.h>
using namespace std;

int t, n;
vector<string> ans;

int main()
{
    cin >> t;
    while (t--)
    {
        ans.clear();
        cin >> n;
        queue<string> q;
        q.push("6");
        q.push("8");
        while (q.size())
        {
            string tam = q.front();
            q.pop();
            if (tam.size() > n)
                break;
            ans.push_back(tam);
            q.push(tam + '6');
            q.push(tam + '8');
        }
        cout << ans.size() << endl;
        for (int i = ans.size() - 1; i >= 0; i--)
            cout << ans[i] << " ";
        cout << endl;
    }
}