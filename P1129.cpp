/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=205;
int n;
int grid[N][N];
int match[N];
bool vis[N];
bool dfs (int u) {
    for (int v=1;v<=n;v++) {
        if (grid[u][v]&&!vis[v]) {
            vis[v]=1;
            if (!match[v]||dfs(match[v])) {
                match[v]=u;
                return 1;
            }
        }
    }
    return 0;
}
void solve() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) cin>>grid[i][j];
    }
    memset(match,0,sizeof match);
    int ans=0;
    for(int i=1;i<=n;i++) {
        memset(vis,0,sizeof vis);
        if(dfs(i)) ans++;
    }
    if(ans==n) cout<<"Yes\n";
    else cout<<"No\n";
}

signed main(){
    Cios;
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}