/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=5e5+10;
struct edge {
    int v,w;
};
vector <edge> g[N],ng[N];
int n,m,k;
int dep[N],sz[N],hv[N],dfn[N],top[N],fa[N],faw[N];
int dfncnt=0;
int imp[N];
template <class _tp> class Stack {
    _tp s[N];
    int top_=0;
    public:
    void push (int p) {s[++top_]=p;}
    _tp top () {return s[top_];}
    _tp ptop () {return s[top_-1];}
    int size () {return top_;}
    void clear () {top_=0;}
    void pop () {top_--;}
};
Stack <int> s;
void dfs1 (int u) {
    dep[u]=dep[fa[u]]+1;
    sz[u]=1;
    for (edge v:g[u]) {
        if (v.v==fa[u]) continue;
        fa[v.v]=u;
        faw[v.v]=v.w;
        dfs1(v.v);
        sz[u]+=sz[v.v];
        if (sz[v.v]>sz[hv[u]]) hv[u]=v.v;
    }
}
void dfs2 (int u,int tp) {
    dfn[u]=++dfncnt;
    top[u]=tp;
    if (hv[u]) dfs2(hv[u],tp);
    for (edge v:g[u]) {
        if (v.v==fa[u]||v.v==hv[u]) continue;
        dfs2(v.v,v.v);
    }
}
int lca (int u,int v) {
    while (top[u]!=top[v]) {
        if (dep[top[v]]>dep[top[u]]) swap(u,v);
        u=fa[top[u]];
    }
    return (dep[u]<dep[v])?u:v;
}
void build () {
    sort (imp+1,imp+1+k,[&] (int a,int b) {return dfn[a]<dfn[b];});
    s.clear();
    s.push(1);
    if (imp[1]!=1) s.push(imp[1]);
    for (int i=2;i<=k;i++) {
        int lc=lca(s.top(),imp[i]);
        while (s.size()>1&&dfn[s.ptop()]>dfn[lc]) ng[s.ptop()].push_back({s.top()});
    }
}
signed main() {
    Cios;
    return 0;
}