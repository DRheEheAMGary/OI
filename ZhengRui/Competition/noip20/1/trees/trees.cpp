/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e5+10;
#ifdef CLANGD_
#define N 10
#endif
int n;
struct edge {
    int to,id;
};
vector <edge> g1[N],g2[N];
struct edges {
    int u,v,id;
};
vector <edges> e;
int tin[N],tout[N],nowt=0,dep1[N];
inline bool inson (int u,int v) {
    return tin[u]<=tin[v]&&tin[v]<=tout[u];
}
void dfs1 (int u,int fa) {
    tin[u]=++nowt;
    dep1[u]=dep1[fa]+1;
    for (auto [v,id]:g1[u]) {
        if (v==fa) continue;
        dfs1(v,u);
    }
    tout[u]=++nowt;
}
int fa[N][20],dep[N],pid[N];
void dfs2 (int u,int _fa) {
    fa[u][0]=_fa;
    dep[u]=dep[_fa]+1;
    for (int i=1;i<=19;i++) fa[u][i]=fa[fa[u][i-1]][i-1];
    for (auto [v,id]:g2[u]) {
        if (v==_fa) continue;
        pid[v]=id;
        dfs2(v,u);
    }
}
inline int lca2 (int u,int v) {
    if (dep[u]>dep[v]) swap(u,v);
    for (int i=19;i>=0;i--) {
        if (dep[fa[v][i]]>=dep[u]) v=fa[v][i];
    }
    if (u==v) return u;
    for (int i=19;i>=0;i--) {
        if (dep[fa[v][i]]!=dep[fa[u][i]]) u=fa[u][i],v=fa[v][i];
    }
    return fa[u][0];
}
signed main() {
    Cios;
    // freopen("trees.in","r",stdin);
    // freopen("trees.out","w",stdout);
    cin>>n;
    for (int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        g1[u].push_back({v,i});
        g1[v].push_back({u,i});
        e.push_back({u,v,i});
    }
    for (int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        g2[u].push_back({v,i});
        g2[v].push_back({u,i});
    }
    dfs1(1,0);
    dfs2(1,0);
    for (auto [u,v,id]:e) {
        if (dep1[u]>dep1[v]) swap(u,v);
        int l=lca2(u,v);
        if (inson(v,l)) {
            for (int i=19;i>=0;i--) {
                if (dep[fa[u][i]]>dep[l]&&!inson(v,fa[u][i])) u=fa[u][i];
            }
            cout<<pid[u]<<"\n";
        }
        else {
            int _v=v;
            for (int i=19;i>=0;i--) {
                if (dep[fa[v][i]]>dep[l]&&inson(_v,fa[v][i])) v=fa[v][i];
            }
            cout<<pid[v]<<"\n";
        }
    }
    return 0;
}

/*
g++ -g trees.cpp -o trees -std=c++14 -O2; echo "finish"; ./trees
*/