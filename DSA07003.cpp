#include <bits/stdc++.h>
using namespace std;

int t;
string s;
stack<char> st;

int main()
{
    cin >> t;
    while (t--)
    {
        while (!st.empty())
            st.pop();
        scanf("\n");
        getline(cin, s);
        bool kt = true;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
                continue;
            if (s[i] == '(')
                st.push('(');
            else if (s[i] <= 'z' && s[i] >= 'a')
                continue;
            else if (s[i] == ')')
            {
                if (st.top() == '(')
                {
                    kt = false;
                    break;
                }
                while (!st.empty())
                {
                    char k = st.top();
                    st.pop();
                    if (k == '(')
                        break;
                }
            }
            else
                st.push('&');
        }
        if (kt == true)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
}