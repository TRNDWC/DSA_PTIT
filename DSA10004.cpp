#include <bits/stdc++.h>
using namespace std;
#define reset                      \
    for (int i = 0; i < 1001; i++) \
        A[i].clear(), check[i] = false;

bool check[1001];
vector<int> A[1001];

int Euler(int n)
{
    int count = 0;
    for (int i = 1; i < n + 1; i++)
        if (A[i].size() % 2 == 1)
            count++;
    if (count == 2)
        return 1;
    if (count == 0)
        return 2;
    return 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        reset int n, m;
        cin >> n >> m;
        while (m--)
        {
            int a, b;
            cin >> a >> b;
            A[a].push_back(b), A[b].push_back(a);
        }
        cout << Euler(n) << endl;
    }
    return 0;
}