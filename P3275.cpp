/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e5+10;
struct edge {
    int to,w;
};
vector <edge> g[N],ng[N];
int dfncnt,scccnt,dfn[N],low[N],bel[N],siz[N],in[N],dp[N];
stack <int> s;
int n,k;
void Tarjan (int u) {
    s.push(u);
    low[u]=dfn[u]=++dfncnt;
    for (auto [v,w]:g[u]) {
        if (!dfn[v]) {
            Tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if (!bel[v]) low[u]=min(low[u],dfn[v]);
    }
    if (low[u]==dfn[u]) {
        scccnt++;
        while (1) {
            int v=s.top();
            s.pop();
            bel[v]=scccnt;
            siz[scccnt]++;
            if (v==u) break;
        }
    }
}
signed main() {
    Cios;
    cin>>n>>k;
    for (int i=1;i<=k;i++) {
        int x,a,b;
        cin>>x>>a>>b;
        if (x==1) {
            g[a].push_back({b,0});
            g[b].push_back({a,0});
        }
        else if (x==2) g[a].push_back({b,1});
        else if (x==3) g[b].push_back({a,0});
        else if (x==4) g[b].push_back({a,1});
        else if (x==5) g[a].push_back({b,0});
    }
    for (int i=1;i<=n;i++) {
        if (!dfn[i]) Tarjan(i);
    }
    for (int u=1;u<=n;u++) {
        for (auto [v,w]:g[u]) {
            if (bel[u]==bel[v]&&w==1) {
                cout<<"-1\n";
                return 0;
            }
            if (bel[u]!=bel[v]) {
                ng[bel[u]].push_back({bel[v],w});
                in[bel[v]]++;
            }
        }
    }
    queue <int> q;
    for (int i=1;i<=scccnt;i++) {
        if (!in[i]) q.push(i),dp[i]=1;
    }
    while (q.size()) {
        int u=q.front();
        q.pop();
        for (auto [v,w]:ng[u]) {
            in[v]--;
            dp[v]=max(dp[v],dp[u]+w);
            if (!in[v]) q.push(v);
        }
    }
    int res=0;
    for (int i=1;i<=scccnt;i++) res+=siz[i]*dp[i];
    cout<<res<<"\n";
    return 0;
}