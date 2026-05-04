/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=510,D=250005,inf=0x3f3f3f3f3f3f3f3f;
int n,k,a[N],c[N];
int dp[D];
signed main() {
    Cios;
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i]>>c[i];
    memset(dp,0x3f,sizeof dp);
    dp[0]=0;
    for (int i=1;i<=n;i++) {
        for (int j=D-1;j>=a[i];j--) dp[j]=min(dp[j],dp[j-a[i]]+c[i]);
    }
    for (int i=D-1;i>=0;i--) {
        if (dp[i]<=k) {
            cout<<i<<"\n";
            return 0;
        }
    }
    return 0;
}