/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e6+10;
int n,deg[N],outto[N],outw[N];
intl dp[N],mxd[N],ans=0;
struct edge {
    int to,w;
};
vector <edge> g[N];
queue <int> q;
signed main() {
    Cios;
    cin>>n;
    for (int i=1;i<=n;i++) {
        int u,l;
        cin>>u>>l;
        g[u].push_back({i,l});
        g[i].push_back({u,l});
        deg[u]++;
        deg[i]++;
        outto[i]=u;
        outw[i]=l;
    }
    for (int i=1;i<=n;i++) {
        if (deg[i]==1) q.push(i);
    }
    while (q.size()) {
        int u=q.front();
        q.pop();
        for (auto [v,w]:g[u]) {
            if (deg[v]>1) {
                mxd[v]=max(mxd[v],dp[v]+dp[u]+w);
                dp[v]=max(dp[v],dp[u]+w);
                if (--deg[v]==1) q.push(v);
            }
        }
    }
    
    return 0;
}