#include <bits/stdc++.h>
using namespace std;

long lo so,n,ans;

int main() 
{
    cin>>n;
    while (n--) 
    {
        int so;
        cin>>so;
        ans+=so+abs(so);
    }
    cout<<ans*2;
}