#include <bits/stdc++.h>
using namespace std;
int M[1001][1001];
vector<int> A[1001];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> M[i][j];
            if (M[i][j])
            {
                A[i].push_back(j);
            }
        }
    for (int i = 1; i <= n; i++)
    {
        for (auto x : A[i])
            cout << x << " ";
        cout << endl;
    }
}