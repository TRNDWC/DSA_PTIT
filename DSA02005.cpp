#include <bits/stdc++.h>
using namespace std;

int n, k, t;
string a;

int giaithua(int n)
{
    int tu = 1;
    for (int i = 1; i <= n; i++)
        tu *= i;
    return tu;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> a;
        n = a.size();
        int loops = giaithua(n) - 1;
        cout << a << " ";
        while (loops--)
        {
            int vt;
            bool k = false;
            for (int i = a.size() - 2; i >= 0; i--)
                if (a[i] < a[i + 1])
                {
                    vt = i;
                    k = true;
                    break;
                }
            if (k == false)
            {
                for (int i = a.size() - 1; i >= 0; i--)
                    cout << a[i];
            }
            else
            {
                int v = vt + 1;
                for (int i = vt + 1; i < a.size(); i++)
                    if (a[i] > a[vt] && a[i] < a[v])
                        v = i;
                swap(a[vt], a[v]);
                for (int i = vt + 1; i < a.size(); i++)
                    for (int j = i + 1; j < a.size(); j++)
                        if (a[i] > a[j])
                            swap(a[i], a[j]);
                cout<<a;
            }
            cout << " ";
        }
        cout << endl;
    }
}
