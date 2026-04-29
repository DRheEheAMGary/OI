/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e5+10,inf=(1ll<<60);
struct node {
    int to,w;
    bool operator < (const node &x) const  {
        return w>x.w;
    }
};
vector <node> g[N];
int h,x,y,z,dis[N];
bool vis[N];
priority_queue<node> pq;
void dij () {
    pq.push({0,0});
    dis[0]=0;
    for (int i=1;i<x;i++) dis[i]=inf;
    while (pq.size()) {
        auto [u,d]=pq.top();
        pq.pop();
        if (vis[u]) continue;
        vis[u]=1;
        for (auto [v,w]:g[u]) {
            if (vis[v]) continue;
            dis[v]=min(dis[v],d+w);
            pq.push({v,dis[v]});
        }
    }
}
signed main() {
    Cios;
    cin>>h>>x>>y>>z;
    for (int i=0;i<x;i++) {
        g[i].push_back({(y+i)%x,y});
        g[i].push_back({(z+i)%x,z});
    }
    dij();
    h--;
    int res=0;
    for (int i=0;i<x;i++) {
        if (h>=dis[i]) res+=(h-dis[i])/x+1;
    }
    cout<<res<<"\n";
    return 0;
}