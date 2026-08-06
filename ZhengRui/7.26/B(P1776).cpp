/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e6+10;
int n,wi,v[N],w[N],dp[N],cnt;
signed main() {
    Cios;
    cin>>n>>wi;
    for (int i=1;i<=n;i++) {
        int a,b,c;
        cin>>a>>b>>c;
        for (int k=1;k<=c;k*=2) {
            cnt++;
            v[cnt]=a*k;
            w[cnt]=b*k;
            c-=k;
        }
        if (c) {
            cnt++;
            v[cnt]=a*c;
            w[cnt]=b*c;
        }
    }
    for (int i=1;i<=cnt;i++) {
        for (int j=wi;j>=w[i];j--) dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
    }
    int res=0;
    for (int i=0;i<=wi;i++) res=max(res,dp[i]);
    cout<<res<<"\n";
    return 0;
}