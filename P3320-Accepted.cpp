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
int n,m;
struct edge {
    int to,w;
};
vector <edge> g[N];
int dfncnt=0,dep[N],siz[N],fa[N],dfn[N],top[N],hv[N],d[N];
auto cmp = [](int a,int b) {return dfn[a]<dfn[b];};
set<int,decltype(cmp)> s(cmp);
void dfs1 (int u,int w) {
    dep[u]=dep[fa[u]]+w;
    d[u]=d[fa[u]]+1;
    siz[u]=1;
    for (edge e:g[u]) {
        int v=e.to,w=e.w;
        if (v==fa[u]) continue;
        fa[v]=u;
        dfs1(v,w);
        siz[u]+=siz[v];
        if (siz[hv[u]]<siz[v]) hv[u]=v;
    }
}
void dfs2 (int u,int tp) {
    top[u]=tp;
    dfn[u]=++dfncnt;
    if (hv[u]) dfs2(hv[u],tp);
    for (edge e:g[u]) {
        int v=e.to;
        if (v==fa[u]||v==hv[u]) continue;
        dfs2(v,v);
    }
}
int lca (int u,int v) {
    while (top[u]!=top[v]) {
        if (d[top[u]]<d[top[v]]) swap(u,v);
        u=fa[top[u]];
    }
    return (d[u]>d[v])?v:u;
}
int dis (int u,int v) {
    return dep[u]+dep[v]-2*dep[lca(u,v)];
}
signed main() {
    Cios;
    cin>>n>>m;
    for (int i=1;i<n;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dfs1(1,0);
    dfs2(1,1);
    int res=0;
    for (int i=1;i<=m;i++) {
        int u;
        cin>>u;
        if (s.size()==0) {
            s.insert(u);
            cout<<"0\n";
            continue;
        } 
        auto fd=s.find(u);
        if (s.size()==1&&fd!=s.end()) {
            s.erase(u);
            cout<<"0\n";
            continue;
        }
        else if (s.size()==1) {
            int val=*s.begin();
            s.insert(u);
            res+=2*dis(val,u);
            cout<<res<<"\n";
            continue;
        }
        int pre,nxt;
        if (fd!=s.end()) {
            pre=*((fd==s.begin()?prev(s.end()):prev(fd)));
            nxt=*((next(fd)==s.end())?s.begin():next(fd));
            res=res-dis(u,pre)-dis(u,nxt)+dis(nxt,pre);
            s.erase(fd);
        }
        else {
            fd=s.insert(u).first;
            pre=*((fd==s.begin()?prev(s.end()):prev(fd)));
            nxt=*((next(fd)==s.end())?s.begin():next(fd));
            res=res+dis(u,pre)+dis(u,nxt)-dis(pre,nxt);
        }
        cout<<res<<"\n";
    }
    return 0;
}