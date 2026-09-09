/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=40;
vector <int> g[N];
int n,a[N],fa[N];
int dep[N];
void dfs (int u,int dep,int fa) {
    ::dep[u]=dep;
    ::fa[u]=fa;
    for (int v:g[u]) {
        if (v==fa) continue;
        dfs(v,dep+1,u);
    }
}
signed main() {
    Cios;
    int T;
    cin>>T;
    while (T--) {
        cin>>n;
        for (int i=1;i<=n;i++) cin>>a[i];
        for (int i=1;i<n;i++) {
            int u,v;
            cin>>u>>v;
            // g[u].push_back(v);
            // g[v].push_back(u);
        }
        cout<<(a[1]?"Si\n":"Yuan\n");
        // dfs(1,0,0);
        // bool nw=1;
        // int dst=-1;
        // do {
        //     for (int i=1;i<=n;i++) {
        //         if (!a[i]) continue;
        //         if (dst==-1||dep[dst]<dep[i]) dst=i;
        //     }
        //     if (dst==-1) break;
        //     int u=dst,v=a[u];
        //     while (u) {
        //         a[u]^=v;
        //         u=fa[u];
        //     }
        //     dst=-1;
        //     nw=!nw;
        // } while (1);
        // cout<<(nw?"Yuan\n":"Si\n");
        // for (int i=1;i<=n;i++) g[i].clear();
        
    }
    return 0;
}