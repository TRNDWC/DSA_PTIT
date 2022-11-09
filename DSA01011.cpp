#include <bits/stdc++.h>
using namespace std;

int t;
string stt, s;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> stt >> s;
        bool kt = false;
        int vt = s.size();
        for (int i = s.size() - 2; i >= 0; i--)
            if (s[i] < s[i + 1])
            {
                kt = true;
                vt = i;
                break;
            }
        if (kt == false)
        {
            cout << stt << " "
                 << "BIGGEST" << endl;
        }
        else
        {
            int v = vt + 1;
            for (int i = v; i < s.size(); i++)
                if (s[vt] < s[i] && s[i] < s[v])
                    v = i;
            swap(s[v], s[vt]);
            for (int i = vt + 1; i < s.size(); i++)
                for (int j = i + 1; j < s.size(); j++)
                    if (s[i] > s[j])
                        swap(s[i], s[j]);
            cout << stt << " " << s << endl;
        }
    }
}