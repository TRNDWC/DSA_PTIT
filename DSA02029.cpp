#include <bits/stdc++.h>
using namespace std;

void dichuyen(int n, char start, char end, char middle)
{
    if (n == 1)
    {
        cout << start << " -> " << end << endl;
        return;
    }
    dichuyen(n - 1, start, middle, end);
    dichuyen(1, start, end, middle);
    dichuyen(n - 1, middle, end, start);
}

int n;

int main()
{
    cin >> n;
    dichuyen(n, 'A', 'C', 'B');
}