/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e5+10,K=1e6+10,inf=(1<<30);
int n,m,k;
struct edge {
    int to,w;
};
vector <edge> g[N];
int res;
bool vis[N];
int rt,tsiz;
int siz[N],mxs[N];
inline void getroot (int u,int f) {
    siz[u]=1;
    mxs[u]=0;
    for (auto [v,w]:g[u]) {
        if (v==f||vis[v]) continue;
        getroot(v,u);
        siz[u]+=siz[v];
        mxs[u]=max(mxs[u],siz[v]);
    }
    mxs[u]=max(mxs[u],tsiz-siz[u]);
    if (rt==0||mxs[u]<mxs[rt]) rt=u;
}
vector <pair <int,int>> dis;
inline void getdist (int u,int f,int d,int dep) {
    if (d>k) return;
    dis.push_back({d,dep});
    for (auto [v,w]:g[u]) {
        if (v==f||vis[v]) continue;
        getdist (v,u,d+w,dep+1);
    }
}
inline void getsz (int u,int f,int &sz) {
    sz++;
    for (auto [v,w]:g[u]) {
        if (vis[v]||v==f) continue;
        getsz(v,u,sz);
    }
}
int tag[K];
inline void solve (int u) {
    vis[u]=1;
    tag[0]=0;
    vector <int> vised;
    for (auto [v,w]:g[u]) {
        if (vis[v]) continue;
        dis.clear();
        getdist(v,u,w,1); 
        for (auto [d,dep]:dis) {
            if (k>=d) res=min(res,dep+tag[k-d]);
        }
        for (auto [d,dep]:dis) {
            if (k>=d) {
                tag[d]=min(tag[d],dep);
                vised.push_back(d);
            }
        }
    }
    for (int p:vised) tag[p]=inf;
    for (auto [v,w]:g[u]) {
        if (vis[v]) continue;
        rt=0;
        tsiz=0;
        getsz(v,u,tsiz);
        getroot(v,0);
        solve(rt);
    }
}
signed main() {
    Cios;
    cin>>n>>k;
    for (int i=1;i<n;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        u++;
        v++;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for (int i=1;i<=k;i++) tag[i]=inf;
    rt=0;
    tsiz=n;
    res=inf;
    getroot(1,0);
    solve(rt);
    cout<<(res>=inf?(-1):res);
    return 0;
}