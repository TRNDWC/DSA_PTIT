#include <bits/stdc++.h>
using namespace std;

int t, n;
int f[1000001], a[1000001];

int main()
{
    cin >> t;
    while (t--)
    {
        memset(f, 0, sizeof(f));
        stack<int> st;
        stack<int> tam;
        vector<int> behon;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            f[a[i]]++;
        }
        for (int i = n; i >= 2; i--)
            st.push(i);

        for (int i = 1; i < n; i++)
        {
            while (tam.size() != 0)
            {
                if (tam.top() > i)
                    st.push(tam.top());
                tam.pop();
            }
            while (st.size() != 0)
            {
                int j = st.top();
                if (j > i && f[a[j]] > f[a[i]])
                {
                    behon.push_back(j);
                    break;
                }
                tam.push(j);
                st.pop();
            }
            if (st.size() == 0)
            {
                behon.push_back(-1);
                continue;
            }
        }
        behon.push_back(-1);
        for (int i = 0; i < behon.size(); i++)
            if (behon[i] != -1)
                cout << a[behon[i]] << " ";
            else
                cout << -1 << " ";
        cout<<endl;
    }
}