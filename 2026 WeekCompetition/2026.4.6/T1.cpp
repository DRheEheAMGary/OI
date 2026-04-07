/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=110,inf=0x3f3f3f3f;
int n,a,b,k[N],dp[N][N],w[N][N];
signed main() {
    Cios;
    cin>>n>>a>>b;
    memset(w,0x3f,sizeof w);
    for (int i=1;i<=n;i++) {
        cin>>k[i];
        for (int j=1;j<=k[i];j++) {
            int v;
            cin>>v;
            w[i][v]=(j!=1);
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (i==j) dp[i][j]=0;
            else dp[i][j]=w[i][j];
        }
    }
    for (int k=1;k<=n;k++) {
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
        }
    }
    cout<<(dp[a][b]>=inf?(-1):dp[a][b])<<"\n";
    return 0;
}