/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=5e4+10;
int n,m,q;
struct edge {
    int to,w;
};
vector <edge> g[N],ng[N];
int dfncnt=0,cnt,dfn[N],low[N],fa[N],tovw[N],dep[N],tot[N],sum[N];
int nfa[N][20],ndep[N],ndis[N];
void Tarjan (int u) {
    dfn[u]=low[u]=++dfncnt;
    for (auto [v,w]:g[u]) {
        if (v==fa[u]) continue;
        if (!dfn[v]) {
            fa[v]=u;
            tovw[v]=w;
            dep[v]=dep[u]+w;
            Tarjan (v);
            low[u]=min(low[u],low[v]);
            if (low[v]>dfn[u]) {
                ng[u].push_back({v,w});
                ng[v].push_back({u,w});
            }
        }
        else {
            low[u]=min(low[u],dfn[v]);
            if (dfn[v]<dfn[u]) {
                cnt++;
                tot[cnt]=dep[u]-dep[v]+w;
                int cur=u;
                while (cur!=v) {
                    sum[cur]=dep[cur]-dep[v];
                    int mind=min(sum[cur],tot[cnt]-sum[cur]);
                    ng[cnt].push_back({cur,mind});
                    ng[cur].push_back({cnt,mind});
                    cur=fa[cur];
                }
                ng[v].push_back({cnt,0});
                ng[cnt].push_back({v,0});
            }
        }
    }
}
void dfs (int u) {
    ndep[u]=ndep[nfa[u][0]]+1;
    for (int i=1;i<20;i++) nfa[u][i]=nfa[nfa[u][i-1]][i-1];
    for (auto [v,w]:ng[u]) {
        if (v==nfa[u][0]) continue;
        nfa[v][0]=u;
        ndis[v]=ndis[u]+w;
        dfs(v);
    }
}
int lca (int u,int v) {
    if (ndep[u]<ndep[v]) swap(u,v);
    for (int i=19;i>=0;i--) {
        if (ndep[nfa[u][i]]>=ndep[v]) u=nfa[u][i];
    }
    if (u==v) return u;
    for (int i=19;i>=0;i--) {
        if (nfa[u][i]!=nfa[v][i]) {
            u=nfa[u][i];
            v=nfa[v][i];
        }
    }
    return nfa[u][0];
}
int jump (int u,int _dep) {
    for (int i=19;i>=0;i--) {
        if (ndep[nfa[u][i]]>=_dep) u=nfa[u][i];
    }
    return u;
}
signed main() {
    Cios;
    cin>>n>>m>>q;
    for (int i=1;i<=m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    cnt=n;
    Tarjan(1);
    dfs(1);
    while (q--) {
        int u,v;
        cin>>u>>v;
        int lc=lca(u,v);
        if (lc<=n) cout<<ndis[u]+ndis[v]-2*ndis[lc]<<"\n";
        else {
            int _u=jump(u,ndep[lc]+1),_v=jump(v,ndep[lc]+1);
            int res=ndis[u]-ndis[_u]+ndis[v]-ndis[_v];
            int oncd=abs(sum[_u]-sum[_v]);
            res+=min(oncd,tot[lc]-oncd);
            cout<<res<<"\n";
        }
    }
    return 0;
}