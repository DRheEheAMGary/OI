/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
signed main() {
    Cios;
    int a,b,p,q,m;
    cin>>a>>b>>p>>q>>m;
    cout<<(a*p+b*q)<<"\n"<<(m-a*p-b*q);
    return 0;
}