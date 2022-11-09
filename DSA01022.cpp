#include <bits/stdc++.h>
using namespace std;

int gt[20], n, t, a[20], sl[20];

int main()
{
    cin >> t;

    // hàm tính giai thừa với gt[i]=i!

    gt[0] = 1;
    gt[1] = 1;
    for (int i = 2; i <= 12; i++)
        gt[i] = gt[i - 1] * i;

    // xuli

    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            sl[i] = i; // sl[i] là số cách chọn chữ số khi chữ số đang xét là i
        }

        long long ans = 1; // vị trí ban đầu 1 2 3 ... n là vị trí ban đầu

        for (int i = 1; i <= n; i++)
        {
            ans += (sl[a[i]] - 1) * gt[n - i];  // khi chữ số cần xét là a[i] thì có
                                                // sl[a[i]]-1 chữ số nhỏ hơn nhân với gt(các vị trí còn lại)
            for (int j = a[i] + 1; j <= n; j++) // khi đã chốt vị trí i là a[i] thì khi về sau nếu chọn vị trí j có chữ số
                sl[j]--;                        // a[j] và chữ số a[j]>a[i] thì không thể chọn a[i] nữa nên giảm đi 1
        }
        cout << ans << endl;
    }
}