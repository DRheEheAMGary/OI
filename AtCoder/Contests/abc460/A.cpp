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
    int n,m;
    cin>>n>>m;
    int res=0;
    while (m) {
        m=n%m;
        res++;
    }
    cout<<res<<"\n";
    return 0;
}