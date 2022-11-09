#include <bits/stdc++.h>
using namespace std;

long long tu, mau, t;

long long ucln(long long a, long long b)
{
    long long cmp = 0;
    while (b != 0)
    {
        cmp = a % b;
        a = b;
        b = cmp;
    }
    return a;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> tu >> mau;
        long long gt = ucln(tu, mau);
        tu /= gt;
        mau /= gt;
        long long i = 2;
        while (true)
        {
            if (tu == 1)
            {
                cout << tu << "/" << mau << endl;
                break;
            }
            else if (tu * i - mau > 0)
            {
                long long tu_so, mau_so;
                tu_so = tu * i - mau;
                mau_so = i * mau;
                long long uc = ucln(tu_so, mau_so);
                tu = tu_so / uc;
                mau = mau_so / uc;
                cout << 1 << "/" << i << " + ";
            }
            else
                i++;
        }
        // xuli(tu,mau);
        // cout<<tu<<" "<<mau<<endl;
    }
}