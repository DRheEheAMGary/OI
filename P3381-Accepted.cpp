/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=5e3+10,M=2e5+10,inf=0x3f3f3f3f3f3f3f3f;
struct edge {
    int to,c,cst,nxt;
}e[M];
int hd[N],cnt=1;
int n,m,s,t;
int maxflow=0,mincost=0;
int dis[N],cur[N];
bool vis[N];
void addedge (int u,int v,int c,int cst) {
    e[++cnt]={v,c,cst,hd[u]};
    hd[u]=cnt;
    e[++cnt]={u,0,-cst,hd[v]};
    hd[v]=cnt;
}
bool spfa () {
    memset(dis,0x3f,sizeof dis);
    memset(vis,0,sizeof vis);
    queue <int> q;
    q.push(s);
    dis[s]=0;
    vis[s]=1;
    cur[s]=hd[s];
    while (q.size()) {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for (int i=hd[u];i;i=e[i].nxt) {
            auto [v,c,cst,nxt]=e[i];
            if (c>0&&dis[v]>dis[u]+cst) {
                dis[v]=dis[u]+cst;
                cur[v]=hd[v];
                if (!vis[v]) {
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
    }
    return dis[t]!=inf;
}
int dfs (int u,int flow) {
    if (u==t||flow==0) return flow;
    int res=0;
    vis[u]=1;
    for (int& i=cur[u];i;i=e[i].nxt) {
        if (flow==res) break;
        auto [v,c,cst,nxt]=e[i];
        if (!vis[v]&&c>0&&dis[v]==dis[u]+cst) {
            int k=dfs(v,min(c,flow-res));
            if (k>0) {
                e[i].c-=k;
                e[i^1].c+=k;
                res+=k;
            }
        }
    }
    vis[u]=0;
    return res;
}
void mcmf () {
    while (spfa()) {
        int res=dfs(s,inf);
        maxflow+=res;
        mincost+=res*dis[t];
    }
}
signed main() {
    Cios;
    cin>>n>>m>>s>>t;
    for (int i=1;i<=m;i++) {
        int u,v,c,cst;
        cin>>u>>v>>c>>cst;
        addedge(u,v,c,cst);
    }
    mcmf();
    cout<<maxflow<<" "<<mincost<<"\n";
    return 0;
}