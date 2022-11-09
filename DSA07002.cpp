#include <bits/stdc++.h>
using namespace std;

stack<int> st;
int k, t;
string s;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> s;
        if (s == "PUSH")
        {
            cin >> k;
            st.push(k);
        }
        else if (s == "POP")
        {
            if (st.empty())
                continue;
            st.pop();
        }
        else
        {
            if (!st.empty())
                cout << st.top() << endl;
            else
                cout << "NONE\n";
        }
    }
}