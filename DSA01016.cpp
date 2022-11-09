#include <bits/stdc++.h>
using namespace std;

int n, t, a[20], sl;
bool tiep;

void in(int n)
{
    cout << "(";
    for (int i = 1; i <= n; i++)
        if (i == n)
            cout << a[i];
        else
            cout << a[i] << " ";
    cout << ")";
}

void sinh()
{
    int i = sl;
    while (i > 0 && a[i] == 1)
        i--;
    if (i == 0)
        tiep = false;
    else
    {
        a[i]--;
        int value = (sl - i) + 1; // sl-i số 1 và 1 số tách từ x[i]
        int num = value / a[i];   // đếm xem tách được bao nhiêu số giống x[i]
        for (int j = i + 1; j <= i + num; j++)
            a[j] = a[i];
        sl = i + num;          // tăng số lượng số lên
        if (value % a[i] != 0) // nếu dư thì thêm số dư vào cuối dãy tăng sl lên 1
        {
            sl++;
            a[sl] = value % a[i];
        }
    }
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        memset(a, 0, sizeof(a));
        a[1] = n;
        sl = 1;
        tiep = true;
        while (tiep)
        {
            in(sl);
            cout << " ";
            sinh();
        }
        cout << endl;
    }
}
