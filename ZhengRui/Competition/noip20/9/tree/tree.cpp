/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e6+10;
#ifdef CLANGD_
#define N 10
#endif
int n,a[N];
struct edge {
    int to,nxt;
}e[N<<3];
int hd[N],ecnt=0;
int hd1[N],hd2[N];
void addedge (int u,int v) {
    e[++ecnt]={v,hd[u]},hd[u]=ecnt;
    e[++ecnt]={u,hd[v]},hd[v]=ecnt;
}
void addedge1 (int u,int v) {
    e[++ecnt]={v,hd1[u]},hd1[u]=ecnt;
} 
void addedge2 (int u,int v) {
    e[++ecnt]={v,hd2[u]},hd2[u]=ecnt;
}
int fa[N];
int find (int x) {
    if (x==fa[x]) return x;
    return fa[x]=find(fa[x]);
}
int tin[N],tout[N],tcnt=0;
void dfs2 (int u) {
    tin[u]=++tcnt;
    for (int i=hd2[u],v=e[i].to;i;i=e[i].nxt,v=e[i].to) dfs2(v);
    tout[u]=++tcnt;
}
intl res[N];
class Fenwick {
    intl tr[N<<1];
    inline int lb (int x) {return x&(-x);}
    public:
    void update (int x,int k) {
        while (x<(N<<1)) {
            tr[x]+=k;
            x+=lb(x);
        }
    }
    intl query (int x) {
        intl res=0;
        while (x) {
            res+=tr[x];
            x-=lb(x);
        }
        return res;
    }
    inline intl query (int l,int r) {return query(r)-query(l-1);}
}bit;
void dfs1 (int u) {
    res[u]=bit.query(tin[u],tout[u]);
    bit.update(tin[u],a[u]);
    for (int i=hd1[u],v=e[i].to;i;i=e[i].nxt,v=e[i].to) dfs1(v);
    bit.update(tin[u],-a[u]);
}
signed main() {
    Cios;
    // freopen("tree.in","r",stdin);
    // freopen("tree.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        addedge(u,v);
    }
    for (int i=1;i<=n;i++) fa[i]=i;
    for (int u=n;u>=1;u--) {
        for (int i=hd[u],v=e[i].to;i;i=e[i].nxt,v=e[i].to) {
            if (v>u) addedge1(u,v=find(v)),fa[v]=u;
        }
    }
    for (int i=1;i<=n;i++) fa[i]=i;
    for (int u=1;u<=n;u++) {
        for (int i=hd[u],v=e[i].to;i;i=e[i].nxt,v=e[i].to) {
            if (v<u) addedge2(u,v=find(v)),fa[v]=u;
        }
    }
    dfs2(n);
    dfs1(1);
    for (int i=1;i<=n;i++) cout<<res[i]<<" \n"[i==n];
    return 0;
}

/*
g++ -g tree.cpp -o tree.exe -std=c++14 -O2 -static; echo "finish"; .\tree.exe; rm tree.exe
cd $work/ZhengRui/Competition/noip20/9/tree && g++ tree.cpp -o tree -std=c++14 -O2 && echo "finish" && ./tree && rm tree
*/