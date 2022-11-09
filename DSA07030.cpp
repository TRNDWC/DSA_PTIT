#include <bits/stdc++.h>
using namespace std;

int t, n, l[100001], r[100001], m;
long long a[100001], key;

int main()
{
    cin >> t;
    while (t--)
    {
        stack<int> st;
        cin >> m >> n;
        key = 0;
        while (m--)
        {
            for (int i = 1; i <= n; i++)
            {
                int so;
                cin >> so;
                if (so == 0)
                    a[i] = 0;
                else
                    a[i]++;
            }
            for (int i = 1; i <= n; i++)
            {
                if (st.size() == 0)
                {
                    st.push(i);
                    l[i] = 0;
                }
                else
                {
                    while (st.size() != 0 && a[st.top()] >= a[i])
                    {
                        st.pop();
                    }
                    if (st.size() == 0)
                    {
                        l[i] = 0;
                        st.push(i);
                    }
                    else
                    {
                        l[i] = st.top();
                        st.push(i);
                    }
                }
            }
            cout << endl;
            while (st.size() != 0)
                st.pop();
            for (int i = n; i >= 1; i--)
            {
                if (st.size() == 0)
                {
                    st.push(i);
                    r[i] = n + 1;
                }
                else
                {
                    while (st.size() != 0 && a[st.top()] >= a[i])
                    {
                        st.pop();
                    }
                    if (st.size() == 0)
                    {
                        r[i] = n + 1;
                        st.push(i);
                    }
                    else
                    {
                        r[i] = st.top();
                        st.push(i);
                    }
                }
            }
            long long ans = 0;
            for (int i = 1; i <= n; i++)
            {
                // cout << l[i] << " " << r[i] << endl;
                long long gt = a[i] * 1ll * (r[i] - 1 - (l[i] + 1) + 1);
                ans = max(ans, gt);
            }
            key = max(key, ans);
        }
        cout << key << endl;
    }
}