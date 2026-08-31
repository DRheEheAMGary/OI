/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e6+10;
int n,k,a[N];
inline int g(int v,int m) {
    int x=(v&m);
    if (x==m) return 0;
    int h=63-__builtin_clzll(m&(~v));
    return (v/(1ll<<(h+1))*(1ll<<(h+1))+(1ll<<h)+m%(1ll<<h));
}
signed main() {
    Cios;
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    int res=0,cnxt=0,ccur=0;
    for (int bi=60;bi>=0;bi--) {
        int m=res|(1ll<<bi);
        cnxt=0;
        for (int i=n;i>=1;i--) {
            int v=a[i]+cnxt;
            if ((v&m)==m) ccur=cnxt;
            else ccur=g(v,m)-a[i];
            if (ccur>k)  break;
            cnxt=ccur;
        }
        if (ccur<=k) res=m;
    }
    cout<<res<<"\n";
    return 0;
}
