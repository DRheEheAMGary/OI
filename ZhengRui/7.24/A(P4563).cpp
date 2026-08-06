/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=5005;
int n,a[N],dp[N][N];
signed main() {
    Cios;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    int res=0;
    for (int r=1;r<=n;r++) {
        res^=(dp[r][r]=1);
        int sum=1,p=0;
        for (int l=r-1;l>=1;l--) {
            if (!p||(a[r]-a[p])/(r-p)>(a[r]-a[l])/(r-l)) sum+=min(dp[l+1][p],(p==0)?0x3f3f3f3f:dp[l+1][p-1]),p=l;
            res^=(dp[l][r]=min(dp[l][p],dp[l][p-1])+sum);
        }
    }
    cout<<res<<"\n";
    return 0;
}