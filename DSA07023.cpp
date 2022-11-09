#include <bits/stdc++.h>
using namespace std;

int t;
string s;

int main()
{
    cin >> t;
    while (t--)
    {
        scanf("\n");
        getline(cin, s);
        s += " ";
        stack<string> st;
        string x = "";
        for (int i = 0; i < s.size(); i++)
            if (s[i] == ' ')
            {
                // cout<<x<<endl;
                if (x != "")
                    st.push(x);
                x = "";
            }
            else
            {
                x += s[i];
            }
        while (st.size() != 0)
        {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
}