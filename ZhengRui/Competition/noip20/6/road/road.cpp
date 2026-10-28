/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e5+10;
constexpr intl inf=1ll<<60;
#ifdef CLANGD_
#define N 10
#endif
struct edge {
    int to;
    intl w;
    int nxt;
}e[N*20];
int hd[N],ecnt=0;
inline void addedge (int u,int v,int w) {
    e[++ecnt]={v,w,hd[u]},hd[u]=ecnt;
    e[++ecnt]={u,w,hd[v]},hd[v]=ecnt;
}
struct point {
    int u;
    intl f;
    inline bool operator <(const point &p) const {return f>p.f;}
};
int n,m,X;
int a[N];
intl f[N];
bool vis[N];
signed main() {
    Cios;
    // freopen("road.in","r",stdin);
    // freopen("road.out","w",stdout);
    cin>>n>>m>>X;
    for (int i=1;i<=n;i++) cin>>a[i],f[i]=inf;
    for (int i=1;i<=m;i++) {
        int u,v,t;
        cin>>u>>v>>t;
        addedge(u,v,t);
    }
    f[1]=0;
    priority_queue<point> pq;
    pq.push({1,0});
    while (pq.size()) {
        auto [u,t]=pq.top();
        pq.pop();
        if (vis[u]) continue;
        vis[u]=1;
        for (int i=hd[u];i;i=e[i].nxt) {
            auto [v,w,_nxt]=e[i];
            if (a[u]<w) continue;
            intl d=max(f[u]+w,(intl)X-a[v]);
            if (d<f[v]) f[v]=d,pq.push({v,f[v]});
        }
    }
    if (f[n]==inf) cout<<"-1\n";
    else cout<<2*f[n]-X+a[n]<<"\n";
    return 0;
}

/*
g++ -g road.cpp -o road.exe -std=c++14 -O2 -static; echo "finish"; .\road.exe; rm road.exe
cd $work/ZhengRui/Competition/noip20/6/road && g++ road.cpp -o road -std=c++14 -O2 && echo "finish" && ./road && rm road
*/