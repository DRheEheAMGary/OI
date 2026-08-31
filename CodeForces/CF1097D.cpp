/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc mod=1e9+7;
int n,k,inv[60],dp[60],ndp[60];
int qpow (int a,int b) {
    int res=1;
    while (b) {
        if (b&1) (res*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return res;
}
signed main() {
    Cios;
    cin>>n>>k;
    for (int i=1;i<60;i++) inv[i]=qpow(i,mod-2);
    int res=1;
    for (int p=2;p*p<=n;p++) {
        if (n%p==0) {
            int m=0;
            while (n%p==0) m++,n/=p;
            int pp=1;
            for (int j=0;j<=m;j++) dp[j]=pp,(pp*=p%mod)%=mod;
            for (int j=1;j<=k;j++) {
                int sum=0;
                for (int l=0;l<=m;l++) (sum+=dp[l])%=mod,ndp[l]=sum*inv[l+1]%mod;
                memcpy(dp,ndp,sizeof dp);
            }
            (res*=dp[m])%=mod;
        }
    }
    if (n>1) {
        int m=1,p=n%mod;
        int pp=1;
        for (int j=0;j<=m;j++) dp[j]=pp,(pp*=p%mod)%=mod;
        for (int j=1;j<=k;j++) {
            int sum=0;
            for (int l=0;l<=m;l++) (sum+=dp[l])%=mod,ndp[l]=sum*inv[l+1]%mod;
            memcpy(dp,ndp,sizeof dp);
        }
        (res*=dp[m])%=mod;
    }
    cout<<res<<"\n";
    return 0;
}