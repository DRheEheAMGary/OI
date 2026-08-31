/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e5+10,inf=0xc0c0c0c0c0c0c0c0;
int n,q,x,y;
int v[N],c[N],dp[N];
signed main() {
    Cios;
    cin>>n>>q;
    double m=0,t;
    for (int i=1;i<=n;i++) {
        cin>>v[i]>>c[i];
        t=1.0*c[i]/v[i];
        if (t>m) {
            m=t;
            x=v[i];
            y=c[i];
        }
    }
    memset(dp,0xc0,sizeof dp);
    dp[0]=0;
    for (int i=1;i<=n;i++) {
        if (v[i]==x) continue;
        int g=__gcd(v[i],x);
        for (int j=0;j<g;j++) {
            int r=j;
            for (int k=0;k<2;k+=(r==j?1:0)) {
                int nr=(r+v[i])%x;
                if (dp[r]!=inf) dp[nr]=max(dp[nr],dp[r]+c[i]-(r+v[i])/x*y);
                r=nr;
            }
        }
    }
    while (q--) {
        int ti;
        cin>>ti;
        int ri=ti%x;
        if (dp[ri]==inf) cout<<"-1\n";
        else cout<<ti/x*y+dp[ri]<<"\n";
    }
    return 0;
}