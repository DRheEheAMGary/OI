/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e5+10,inf=(1<<30);
struct edge {
    int to,w;
};
struct question {
    int u1,u2;
};
struct distances {
    int dep,u,bel;
};
vector <question> q;
vector <edge> g[N];
int n,m;
bool vis[N];
int siz[N],mxs[N];
int res=inf;
int dist[N],belg[N];
inline void getroot (int u,int f,int tsiz,int &rt) {
    siz[u]=1;
    mxs[u]=-1;
    for (auto [v,w]:g[u]) {
        if (v==f||vis[v]) continue;
        getroot(v,u,tsiz,rt);
        siz[u]+=siz[v];
        mxs[u]=max(mxs[u],siz[v]);
    }
    mxs[u]=max(mxs[u],tsiz-siz[u]);
    if (rt==0||mxs[rt]>mxs[u]) rt=u;
}
inline void getsiz (int u,int f,int &sz) {
    sz++;
    for (auto [v,w]:g[u]) {
        if (v==f||vis[v]) continue;
        getsiz(v,u,sz);
    }
}
inline void getdis (int u,int f,int dep,int bel) {
    belg[u]=bel;
    dist[u]=dep;
    for (auto [v,w]:g[u]) {
        if (v==f) continue;
        getdis(v,u,dep+w,(bel==0)?v:bel);
    }
}
inline void solve (int u) {
    vis[u]=1;
    dist[u]=0;
    belg[u]=0;
    getdis(u,0,0,0);
    int maxdep=-1;
    for (auto [u1,u2]:q) maxdep=max(maxdep,dist[u1]+dist[u2]);
    res=min(res,maxdep);
    int tmpv=-1;
    for (auto [u1,u2]:q) {
        if (dist[u1]+dist[u2]==maxdep) {
            if (u1==u||u2==u||belg[u1]!=belg[u2]) return;
            if (tmpv==-1) tmpv=belg[u1];
            if (tmpv!=belg[u1]) return;
        }
    }
    if (vis[tmpv]) return;
    int rt=0,tsiz=0;
    getsiz(tmpv,u,tsiz);
    getroot(tmpv,u,tsiz,rt);
    solve(rt);
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
    for (int i=0;i<m;i++) {
        int u,v;
        cin>>u>>v;
        q.push_back({u,v});
    }
    int rt=0;
    getroot(1,0,n,rt);
    solve(rt);
    cout<<res<<"\n";
    return 0;
}