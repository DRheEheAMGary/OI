/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e6+10;
const intl inf=1ll<<60;
#ifdef CLANGD_
#define N 10
#endif
struct edge {
    int to,nxt;
}e[N*2];
int hd[N],ecnt=0;
int n,m,a[N],b[N],c[N];
intl cie[N],bel[N],sz[N],dfn[N];
int ccnt=0,tim=0;
intl dep[N];
inline void addedge (int u,int v) {
    e[++ecnt]={v,hd[u]},hd[u]=ecnt;
}
class DisjointSetUnion {
    int fa[N];
    public:
    void Init () {
        for (int i=1;i<=m;i++) fa[i]=i;
    }
    int find (int u) {
        if (fa[u]==u) return u;
        return fa[u]=find(fa[u]);
    }
    void merge (int u,int v) {
        u=find(u);
        v=find(v);
        fa[v]=u;
    }
}dsu;
inline void dfs (int u) {
    dfn[u]=++tim;
    sz[u]=1;
    for (int i=hd[u];i;i=e[i].nxt) {
        int v=e[i].to;
        dep[v]=dep[u]+c[v];
        bel[v]=bel[u];
        dfs(v);
        sz[u]+=sz[v];
    }
}
inline bool sub (int u,int v) {return dfn[u]<=dfn[v]&&dfn[v]<=dfn[u]+sz[u]-1;}
inline intl query (int u,int v) {
    if (u==v) return 0;
    if (bel[u]!=bel[v]) return inf;
    intl res=inf;
    if (sub(v,u)) res=dep[u]-dep[v];
    if (sub(v,cie[bel[u]])) res=min(res,dep[u]-dep[v]+dep[cie[bel[u]]]+c[bel[u]]);
    return res;
}
bool check (intl val) {
    for (int i=1,j=1;i<=n;i++) {
        while (j<=m&&query(a[i],j)>val) j++;
        if (j>m) return 0; 
    }
    return 1;
}
signed main() {
    Cios;
    int T;
    cin>>T;
    while (T--) {
        cin>>n>>m;
        for (int i=1;i<=n;i++) cin>>a[i];
        for (int i=1;i<=m;i++) cin>>b[i];
        for (int i=1;i<=m;i++) cin>>c[i];
        for (int i=1;i<=m;i++) hd[i]=cie[i]=bel[i]=sz[i]=dfn[i]=dep[i]=0;
        dsu.Init();
        ecnt=ccnt=tim=0;
        for (int i=1;i<=m;i++) {
            if (dsu.find(i)!=dsu.find(b[i])) {
                dsu.merge(i,b[i]);
                addedge(b[i],i);
            }
            else cie[i]=b[i];
        }
        for (int i=1;i<=m;i++) {
            if (cie[i]) bel[i]=i,dfs(i);
        }
        if (!check(1e18)) {
            cout<<"-1\n";
            continue;
        }
        intl L=0,R=1e18,res=-1;
        while (L<=R) {
            intl mid=(L+R)>>1;
            if (check(mid)) R=mid-1,res=mid;
            else L=mid+1;
        }
        cout<<res<<"\n";
    }
    return 0;
}

/*
g++ transform.cpp -o transform -std=c++14 -O2; echo "finish"; ./transform
*/