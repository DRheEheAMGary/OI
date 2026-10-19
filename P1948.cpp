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
intc N=1e3+10;
struct Edge {
    int u,v,w;
};
vector <Edge> eds;
struct edge {
    int to,v;
};
vector <edge> g[N];
int n,p,k;
struct node {
    int u,l;
    bool operator <(const node &p) const {return l>p.l;}
};
int dis[N];
bool vis[N];
int dijs () {
    priority_queue<node> pq;
    memset(dis,0x3f,szof dis);
    memset(vis,0,szof vis);
    pq.push({1,0});
    dis[1]=0;
    while (pq.size()) {
        auto [u,l]=pq.top();
        pq.pop();
        if (vis[u]) continue;
        vis[u]=1;
        for (auto [v,w]:g[u]) {
            if (vis[v]) continue;
            if (dis[v]>dis[u]+w) {
                dis[v]=dis[u]+w;
                pq.push({v,dis[v]});
            }
        }
    }
    if (dis[n]==0x3f3f3f3f3f3f3f3f) return -1;
    return dis[n];
}
bool Check (int x) {
    for (auto [u,v,w]:eds) {
        if (w>x) g[u].push_back({v,1}),g[v].push_back({u,1});
        else g[u].push_back({v,0}),g[v].push_back({u,0});
    }
    int _k=dijs();
    if (_k==-1) {
        cout<<"-1\n";
        exit(0);
    }
    for (int i=1;i<=n;i++) g[i].clear();
    return _k<=k;
}
signed main() {
    Cios;
    cin>>n>>p>>k;
    for (int i=1;i<=p;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        eds.push_back({u,v,w});
    }
    int l=0,r=1e6+10,res=0;
    while (l<=r) {
        int mid=(l+r)>>1;
        if (Check(mid)) res=mid,r=mid-1;
        else l=mid+1;
    }
    cout<<res<<"\n";
    return 0;
}