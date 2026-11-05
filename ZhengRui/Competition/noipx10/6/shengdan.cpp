/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e5+10;
intl n,m,a[N];
map<intl,intl> t;
signed main() {
    Cios;
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    if (n*(n-1)/2>=3*m+(1<<18)) return cout<<m,0;
    for (int i=1;i<=n;i++) {
        for (int j=i+1;j<=n;j++) t[a[i]^a[j]]++;
    }
    intl res=0;
    for (auto &[_idx,tx]:t) res+=tx*(tx-1)/2;
    cout<<res/3;
    return 0;
}