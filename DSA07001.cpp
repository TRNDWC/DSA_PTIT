#include <bits/stdc++.h>
using namespace std;

stack<int> st;
string s;
int k;

int main()
{
    while (cin >> s)
    {
        if (s == "push")
        {
            cin >> k;
            st.push(k);
        }
        else if (s == "show")
        {
            if (st.empty())
            {
                cout << "empty\n";
                continue;
            }
            vector<int> a;
            while (!st.empty())
            {
                a.push_back(st.top());
                st.pop();
            }
            for (int i = a.size() - 1; i >= 0; i--)
            {
                cout << a[i] << " ";
                st.push(a[i]);
            }
            cout << endl;
        }
        else
        {
            st.pop();
        }
    }
}