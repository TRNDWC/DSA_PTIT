#include <bits/stdc++.h>
using namespace std;

int t;
string s;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> s;
        long long ans = 0;
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                st.push('(');
            else
            {
                if (st.size() != 0 && st.top() == '(')
                {
                    st.pop();
                    ans += 2;
                }
                else st.push(')');
            }
        }
        cout << ans << endl;
    }
}