#include <bits/stdc++.h>
using namespace std;

void Load(vector<int> M, int left, int right)
{
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    Load(M, mid + 1, right);
    Load(M, left, mid);
    cout << M[mid] << " ";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> M;
        for (int i = 0; i < n; i++)
        {
            int so;
            cin >> so;
            M.push_back(so);
        }
        sort(M.begin(), M.end(), greater<>());
        Load(M, 0, n);
        cout << endl;
    }
    return 0;
}