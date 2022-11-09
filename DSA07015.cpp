#include <bits/stdc++.h>
using namespace std;

int t;
string s, so;

int dout(char k)
{
    if (k == '*' || k == '/')
        return 2;
    else if (k == '+' || k == '-')
        return 1;
    else
        return 0;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> s;
        stack<char> st;
        vector<string> kq;
        so = "";
        s += " ";
        for (int i = 0; i <= s.size(); i++)
        {
            if (s[i] == '(')
                st.push('(');
            else if (s[i] >= '0' && s[i] <= '9')
                so += s[i];
            else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            {
                if (so != "")
                {
                    kq.push_back(so);
                    so = "";
                }
                while (st.size() != 0 && dout(st.top()) >= dout(s[i]))
                {
                    kq.push_back(string(1, st.top()));
                    st.pop();
                }
                st.push(s[i]);
            }
            else if (s[i] == ')')
            {
                if (so != "")
                {
                    kq.push_back(so);
                    so = "";
                }
                while (st.size() != 0 && st.top() != '(')
                {
                    kq.push_back(string(1, st.top()));
                    st.pop();
                }
                st.pop();
            }
            else if (s[i] == ' ')
            {
                if (so != "")
                {
                    kq.push_back(so);
                    so = "";
                }
            }
        }
        while (st.size() != 0)
        {
            if (st.top() == '(')
                st.pop();
            else
            {
                kq.push_back(string(1, st.top()));
                st.pop();
            }
        }
        stack<string> ans;
        for (int i = 0; i < kq.size(); i++)
            if (kq[i] == "+" || kq[i] == "-" || kq[i] == "*" || kq[i] == "/")
            {
                string s2 = ans.top();
                ans.pop();
                string s1 = ans.top();
                ans.pop();

                stringstream ss;
                long long so1, so2, so3;
                ss << s1;
                ss >> so1;
                ss.clear();
                ss << s2;
                ss >> so2;
                ss.clear();
                if (kq[i] == "+")
                    so3 = so1 + so2;
                else if (kq[i] == "-")
                    so3 = so1 - so2;
                else if (kq[i] == "*")
                    so3 = so1 * so2;
                else if (kq[i] == "/")
                    so3 = so1 / so2;
                string s3;
                ss << so3;
                ss >> s3;
                ss.clear();
                ans.push(s3);
            }
            else if (kq[i] != " ")
            {
                ans.push(kq[i]);
            }
        cout << ans.top() << endl;
    }
}