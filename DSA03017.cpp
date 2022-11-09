#include <bits/stdc++.h>
using namespace std;

int t, n, k;
string s;
int f[10001];

bool cmp(char a, char b)
{
    return f[a - 'A'] < f[b - 'A'];
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> k;
        cin >> s;
        memset(f, 0, sizeof(f));
        for (int i = 0; i < s.size(); i++)
            f[s[i] - 'A']++;
        priority_queue<char, vector<char>, function<bool(char, char)>> pq(cmp);
        for (char k = 'A'; k <= 'Z'; ++k)
            if (f[k - 'A'] != 0)
                pq.push(k);
        while (k > 0 && !pq.empty())
        {
            char gt = pq.top();
            //cout<<gt<<" "<<f[gt-'A']<<endl;
            pq.pop();
            k--;
            pq.push(gt);
            f[gt - 'A']--;
        }
        long long ans = 0;
        for (char k = 'A'; k <= 'Z'; k++)
            if (f[k - 'A'] != 0)
                ans += f[k-'A'] * f[k - 'A'];
        cout << ans << endl;
    }
}