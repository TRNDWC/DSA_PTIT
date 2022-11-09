#include <bits/stdc++.h>
using namespace std;

int t, n, a[1000001];

int main()
{
    cin >> t;
    while (t--)
    {
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
                    cout << a[j] << " ";
                    break;
                }
                tam.push(j);
                st.pop();
            }
            if (st.size() == 0)
            {
                cout << -1 << " ";
                continue;
            }
        }
        cout << -1 << endl;
    }
}