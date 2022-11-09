#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    string ma_a = a, mi_a = a;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '5')
            ma_a[i] = '6';
        else if (a[i] == '6')
            mi_a[i] = '5';
    }
    string ma_b = b, mi_b = b;
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] == '5')
            ma_b[i] = '6';
        else if (b[i] == '6')
            mi_b[i] = '5';
    }
    stringstream ss;
    ss << mi_a;
    int min_a;
    ss >> min_a;
    ss.clear();
    ss << mi_b;
    int min_b;
    ss >> min_b;
    ss.clear();
    cout << min_a + min_b << " ";
    ss << ma_a;
    int max_a;
    ss >> max_a;
    ss.clear();
    ss << ma_b;
    int max_b;
    ss >> max_b;
    ss.clear();
    cout << max_a + max_b;
}