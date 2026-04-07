/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=5e3+10,W=1e4+10;
int n,nw,k,w[N],v[N],dp[W][N];
int h,ans,er;
signed main() {
    Cios;
    cin>>n>>nw>>k;
    for (int i=1;i<=n;i++) cin>>w[i]>>v[i];
    dp[0][0]=0;
    for (int i=1;i<=n;i++) {
        for (int j=nw;j>=0;j--) {
            for (int l=k;l>=0;l--) {
                if (j>=w[i]) dp[j][l]=max(dp[j][l],dp[j-w[i]][l]+v[i]);
                if (l>=1) dp[j][l]=max(dp[j][l],dp[j][l-1]+v[i]);
            }
        }
    }
    cout<<dp[nw][k]<<"\n";
    return 0;
}