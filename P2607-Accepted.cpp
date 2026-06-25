/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e6+10;
vector <int> g[N];
int n,s1,s2,res,w[N],vis[N],dp[N][2];
void dfs (int u,int rt) {
    vis[u]=1;
    for (int v:g[u]) {
        if (v==rt) {
            s1=u;
            s2=v;
            return;
        }
        if (!vis[v]) dfs(v,rt);
    }
}
int dodp (int u,int rt) {
    dp[u][0]=0;
    dp[u][1]=w[u];
    for (int v:g[u]) {
        if (v==rt) continue;
        dodp(v,rt);
        dp[u][0]+=max(dp[v][0],dp[v][1]);
        dp[u][1]+=dp[v][0];
    }
    return max(dp[u][0],dp[u][1]);
}
signed main() {
    Cios;
    cin>>n;
    for (int i=1;i<=n;i++) {
        int v;
        cin>>w[i]>>v;
        g[v].push_back(i);
    }
    for (int i=1;i<=n;i++) {
        if (!vis[i]) {
            s1=s2=0;
            dfs(i,i);
            if (s1) res+=max(dodp(s1,s1),dodp(s2,s2));
        }
    }
    cout<<res<<"\n";
    return 0;
}