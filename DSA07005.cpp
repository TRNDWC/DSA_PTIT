#include <bits/stdc++.h>
using namespace std;

int t;
string s;

int main()
{
    cin >> t;
    while (t--)
    {
        stack<char> st;
        stack<char> tam;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == ')')
            {
                while (st.size() != 0 && st.top() != '(')
                {
                    tam.push(st.top());
                    st.pop();
                }
                st.pop();
                // cout<<i<<" "<<tam.size()<<" "<<st.size();
                if (st.size() != 0)
                {
                    if (st.top() == '+' || st.top() == '(')
                    {
                        while (tam.size() != 0)
                        {
                            st.push(tam.top());
                            tam.pop();
                        }
                    }
                    else
                    {
                        while (tam.size() != 0)
                        {
                            if (tam.top() == '+')
                            {
                                st.push('-');
                            }
                            else if (tam.top() == '-')
                            {
                                st.push('+');
                            }
                            else
                                st.push(tam.top());
                            tam.pop();
                        }
                    }
                }
                else
                {
                    while (tam.size() != 0)
                    {
                        st.push(tam.top());
                        tam.pop();
                    }
                }
            }
            else
            {
                st.push(s[i]);
            }
        string ans = "";
        while (st.size() != 0)
        {
            ans = st.top() + ans;
            st.pop();
        }
        cout << ans << endl;
        // cout << endl;
    }
}   