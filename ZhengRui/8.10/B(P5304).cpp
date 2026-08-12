/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define szof sizeof
intc N=1e5+10,inf=0x3f3f3f3f3f3f3f3f;
struct edge {
    int to,v;
};
struct node {
    int u,w;
    bool operator < (const node &p) const {return w>p.w;}
};
vector <edge> g[N];
int n,m,k;
int dis[N],ks[N];
bool vis[N];
int dijs (int ith) {
    priority_queue<node> pq;
    memset(dis,0x3f,szof dis);
    memset(vis,0,szof vis);
    vector <int> ress;
    int res=inf;
    for (int i=1;i<=k;i++) {
        int _k=ks[i];
        if ((_k>>ith)&1) dis[_k]=0,pq.push({_k,0});
        else ress.push_back(_k);
    }
    while (pq.size()) {
        auto [u,w]=pq.top();
        pq.pop();
        if (vis[u]) continue;
        vis[u]=1;
        for (auto [v,l]:g[u]) {
            if (vis[v]) continue;
            if (dis[v]>dis[u]+l) {
                dis[v]=dis[u]+l;
                pq.push({v,dis[v]});
            }
        }
    }
    for (int _r:ress) res=min(res,dis[_r]);
    memset(dis,0x3f,szof dis);
    memset(vis,0,szof vis);
    ress.clear();
    for (int i=1;i<=k;i++) {
        int _k=ks[i];
        if (!((_k>>ith)&1)) dis[_k]=0,pq.push({_k,0});
        else ress.push_back(_k);
    }
    while (pq.size()) {
        auto [u,w]=pq.top();
        pq.pop();
        if (vis[u]) continue;
        vis[u]=1;
        for (auto [v,l]:g[u]) {
            if (vis[v]) continue;
            if (dis[v]>dis[u]+l) {
                dis[v]=dis[u]+l;
                pq.push({v,dis[v]});
            }
        }
    }
    for (int _r:ress) res=min(res,dis[_r]);
    return res;
}
signed main() {
    Cios;
    int T;
    cin>>T;
    while (T--) {
        cin>>n>>m>>k;
        for (int i=1;i<=m;i++) {
            int u,v,w;
            cin>>u>>v>>w;
            g[u].push_back({v,w});
        }
        for (int i=1;i<=k;i++) cin>>ks[i];
        int res=inf;
        for (int i=0;(1<<i)<=n;i++) res=min(res,dijs(i));
        cout<<res<<"\n";
        for (int i=1;i<=n;i++) g[i].clear();
    }
    return 0;
}