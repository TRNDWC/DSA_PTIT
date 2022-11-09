#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

vector<int> k[1005];
bool chuaxet[1005];

void dfs(int d, int &kt)
{
    stack<int> st;
    st.push(d);
    chuaxet[d] = false;
    while (!st.empty())
    {
        int s = st.top();
        st.pop();
        for (auto t : k[s])
        {
            if (chuaxet[t] == true)
            {
                st.push(s);
                st.push(t);
                chuaxet[t] = false;
                break;
            }
            else if (t == d)
                kt = 1;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int v, e;
        cin >> v >> e;
        for (int i = 0; i < 1005; i++)
            k[i].clear();
        for (int i = 1; i <= e; i++)
        {
            int a, b;
            cin >> a >> b;
            k[a].push_back(b);
        }
        int kt = 0;
        for (int i = 1; i <= v; i++)
        {
            memset(chuaxet, true, sizeof(chuaxet));
            dfs(i, kt);
            if (kt == 1)
                break;
        }
        if (kt == true)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
}