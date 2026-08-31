/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=5e5+10;
int n,m;
vector <int> g[N],ng[N*2];
int dfncnt=0,pcnt=0,dfn[N],low[N];
stack <int> s;
void Tarjan (int u,int fa) {
    dfn[u]=low[u]=++dfncnt;
    s.push(u);
    for (int v:g[u]) {
        if (!dfn[v]) {
            Tarjan (v,u);
            low[u]=min(low[u],low[v]);
            if (low[v]>=dfn[u]) {
                pcnt++;
                while (1) {
                    int su=s.top();
                    s.pop();
                    ng[pcnt].push_back(su);
                    ng[su].push_back(pcnt);
                    if (su==v) break;
                }
                ng[pcnt].push_back(u);
                ng[u].push_back(pcnt);
            }
        }
        else low[u]=min(low[u],dfn[v]);
    }
}
int siz[N*2],hv[N*2],top[N*2],fa[N*2],dep[N*2];
void dfs1 (int u) {
    siz[u]=1;
    dep[u]=dep[fa[u]]+1;
    for (int v:ng[u]) {
        if (v==fa[u]) continue;
        fa[v]=u;
        dfs1(v);
        siz[u]+=siz[v];
        if (siz[v]>siz[hv[u]]) hv[u]=v;
    }
}
void dfs2 (int u,int rt) {
    top[u]=rt;
    if (hv[u]) dfs2(hv[u],rt);
    for (int v:ng[u]) {
        if (v==fa[u]||v==hv[u]) continue;
        dfs2(v,v);
    }
}
int lca (int u,int v) {
    while (top[u]!=top[v]) {
        if (dep[top[u]]<dep[top[v]]) swap(u,v);
        u=fa[top[u]];
    }
    return (dep[u]>dep[v]?v:u);
}
signed main() {
    Cios;
    cin>>n>>m;
    pcnt=n;
    for (int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    Tarjan(1,0);
    dfs1(1);
    dfs2(1,1);
    int q;
    cin>>q;
    while (q--) {
        int u,v;
        cin>>u>>v;
        cout<<(dep[u]+dep[v]-2*dep[lca(u,v)])/2+1<<"\n";
    }
    return 0;
}