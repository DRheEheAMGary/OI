/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define szof sizeof
intc N=3005,mod=1e9+7;
int n,dp[N][N],f[N],C[N][N],inv[N],sz[N];
struct edge {
    int v;
    bool arr;
};
vector <edge> g[N];
void dfs (int u) {
    dp[u][1]=sz[u]=1;
    for (auto [v,arr]:g[u]) {
        dfs(v);
        for (int i=1;i<=sz[u];i++) {
            for (int j=1;j<=sz[v];j++) {
                if (arr) {
                    (f[i]+=((dp[u][i]*dp[v][j])%mod*C[sz[u]+sz[v]][sz[u]])%mod)%=mod;
                    (((f[i+j]-=((dp[u][i]*dp[v][j])%mod*C[sz[u]+sz[v]][sz[u]])%mod)%=mod)+=mod)%=mod;
                }
                else (f[i+j]+=((dp[u][i]*dp[v][j])%mod*C[sz[u]+sz[v]][sz[u]])%mod)%=mod;
            }
        }
        sz[u]+=sz[v];
        for (int i=1;i<=sz[u];i++) dp[u][i]=f[i],f[i]=0;
    }
    for (int i=1;i<=sz[u];i++) (dp[u][i]*=inv[i])%=mod;
}
signed main() {
    Cios;
    cin>>n;
    inv[1]=1;
    for (int i=2;i<=n;i++) inv[i]=((mod-mod/i)*inv[mod%i])%mod;
    C[0][0]=1;
    for (int i=1;i<=n;i++) {
        C[i][0]=1;
        for (int j=1;j<=i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    }
    for (int i=2;i<=n;i++) {
        int v;
        char w;
        cin>>v>>w;
        g[v].push_back({i,w=='>'});
    }
    dfs(1);
    int res=0;
    for (int i=1;i<=n;i++) (res+=dp[1][i])%=mod;
    cout<<res<<"\n";
    return 0;
}