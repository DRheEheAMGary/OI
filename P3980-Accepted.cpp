/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e3+10,M=5e4+10,inf=0x3f3f3f3f3f3f3f3f;
int n,m,s,t;
struct edge {
    int to,c,cst,nxt;
}e[M];
int hd[N],cnt=1;
int dis[N],cur[N],a[N];
bool vis[N];
void addedge (int u,int v,int c,int cst) {
    e[++cnt]={v,c,cst,hd[u]},hd[u]=cnt;
    e[++cnt]={u,0,-cst,hd[v]},hd[v]=cnt;
}
bool spfa () {
    memset(dis,0x3f,sizeof dis);
    queue<int> q;
    q.push(s);
    dis[s]=0;
    cur[s]=hd[s];
    vis[s]=1;
    while (q.size()) {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for (int i=hd[u];~i;i=e[i].nxt) {
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
int dfs (int u,int fl) {
    if (u==t||fl==0) return fl;
    int res=0;
    vis[u]=1;
    for (int &i=cur[u];~i;i=e[i].nxt) {
        if (fl==res) break;
        auto [v,c,cst,nxt]=e[i];
        if (!vis[v]&&c>0&&dis[v]==dis[u]+cst) {
            int nw=dfs(v,min(fl-res,c));
            if (nw>0) {
                e[i].c-=nw;
                e[i^1].c+=nw;
                res+=nw;
            }
        }
    }
    vis[u]=0;
    return res;
}
int Dinic () {
    int res=0;
    while (spfa()) res+=dfs(s,inf)*dis[t];
    return res;
}
signed main() {
    Cios;
    cin>>n>>m;
    s=0;
    t=n+2;
    memset(hd,-1,sizeof hd);
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n+1;i++) {
        int w=a[i]-a[i-1];
        if (w>0) addedge(s,i,w,0);
        else if (w<0) addedge(i,t,-w,0);
    }
    for (int i=1;i<=n;i++) addedge(i+1,i,inf,0);
    for (int i=1;i<=m;i++) {
        int s,t,c;
        cin>>s>>t>>c;
        addedge(s,t+1,inf,c);
    }
    cout<<Dinic()<<"\n";
    return 0;
} 