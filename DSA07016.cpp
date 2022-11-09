#include <bits/stdc++.h>
using namespace std;

int t, gt;
string s;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> s;
        stack<int> kq;
        stack<int> tam;
        kq.push(1);
        gt = 2;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'D')
            {
                tam.push(kq.top());
                kq.pop();
                kq.push(gt);
            }
            else
            {
                while (tam.size() != 0)
                {
                    kq.push(tam.top());
                    tam.pop();
                }
                kq.push(gt);
            }
            gt++;
        }
        while (tam.size() != 0)
        {
            kq.push(tam.top());
            tam.pop();
        }
        s = "";
        while (kq.size() != 0)
        {
            char k = '0' + kq.top();
            s = k + s;
            kq.pop();
        }
        cout << s << endl;
    }
}
