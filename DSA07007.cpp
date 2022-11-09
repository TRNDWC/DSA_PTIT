#include <bits/stdc++.h>
using namespace std;

string xuli(string s)
{
    stack<char> st;
    stack<char> tam;
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
    return ans;
    // cout << endl;
}

int t;
string x1, x2;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> x1 >> x2;
        string s1, s2;
        s1 = xuli(x1);
        s2 = xuli(x2);
        if (s1 == s2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}