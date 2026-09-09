/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e5+10,inf=1e18;
int t,k,n,x[N],y[N],dp[N][2];
int solvemin (int l,int r) {
    int len=r-l+1;
    if (len%2==0) return 0;
    int res=inf;
    for (int i=l;i<=r;i++) {
        if ((i-l)%2==0||x[i+1]-x[i-1]<=k) res=min(res,y[i]);
    }
    return res;
}
int solvemax (int l,int r) {
    int len=r-l+1;
    dp[r+1][0]=0;
    dp[r+1][1]=-inf;
    int ub=r+1;
    for (int i=r;i>=l;i--) {
        dp[i][0]=dp[i+1][0];
        dp[i][1]=dp[i+1][1];
        while (ub-1>i&&x[ub-1]>x[i]+k) ub--;
        bool cro=(i==l||i==r||x[i+1]-x[i-1]<=k);
        int tot=r-i+1;
        if (cro||tot%2==0) {
            if (dp[ub][1]!=-inf) dp[i][0]=max(dp[i][0],dp[ub][1]+y[i]);
        }
        if (cro||tot%2==1) {
            if (dp[ub][0]!=-inf) dp[i][1]=max(dp[i][1],dp[ub][0]+y[i]);
        }
    }
    return (len%2!=0)?dp[l][1]:dp[l][0];
}
signed main() {
    Cios;
    cin>>t>>n>>k;
    for (int i=1;i<=n;i++) cin>>x[i]>>y[i];
    int res=0;
    for (int l=1,r=1;l<=n;l=r+1) {
        r=l;
        while (r<n&&x[r+1]-x[r]<=k) r++;
        if (t==1) res+=solvemin(l,r);
        else res+=solvemax(l,r);
    }
    cout<<res<<"\n";
    return 0;
}
