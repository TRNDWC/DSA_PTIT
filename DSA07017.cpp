#include <bits/stdc++.h>
using namespace std;

int t, n, a[1000001];

int main()
{
    cin >> t;
    while (t--)
    {
        vector<int> lonhon, behon;
        stack<int> st;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = n; i >= 2; i--)
            st.push(i);
        stack<int> tam;
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
                if (j > i && a[j] > a[i])
                {
                    lonhon.push_back(j);
                    break;
                }
                tam.push(j);
                st.pop();
            }
            if (st.size() == 0)
            {
                lonhon.push_back(-1);
                continue;
            }
        }
        lonhon.push_back(-1);

        while (st.size() != 0)
            st.pop();
        while (tam.size() != 0)
            tam.pop();

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
                if (j > i && a[j] < a[i])
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
        // for (int i = 0; i < lonhon.size(); i++)
        //     cout << lonhon[i] << " ";
        // cout << endl;
        // for (auto i : behon)
        //     cout << i << " ";
        // cout << endl;
        for (int i = 0; i < lonhon.size(); i++)
        {
            if (lonhon[i] == -1)
            {
                cout << -1 << " ";
                continue;
            }
            if (behon[lonhon[i] - 1] == -1)
            {
                cout << -1 << " ";
                continue;
            }
            cout << a[behon[lonhon[i] - 1]] << " ";
        }
        cout << endl;
    }
}