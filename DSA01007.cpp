#include<bits/stdc++.h>
using namespace std;
int t,n;
void sinh (string s, int sl)
{
    if (sl==n) 
    {
        cout<<s<<" ";
        return;
    }
    sinh(s+'A',sl+1);
    sinh(s+'B',sl+1);
}
int main()
{
    cin>>t;
    while (t--) 
    {
        cin>>n;
        sinh("",0);
        cout<<endl;
    }
}