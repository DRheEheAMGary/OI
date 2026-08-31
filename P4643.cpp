/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e4+10;
int n,m,a[N];
signed main() {
    Cios;
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        a[i]*=2;
    }
    for (int i=1;i<=m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        a[u]+=w;
        a[v]+=w;
    }
    sort (a+1,a+1+n);
    int res=0;
    for (int i=n;i>=1;i-=2) res+=a[i]-a[i-1];
    cout<<res<<"\n";
    return 0;
}