/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=200,M=1e4+10,inf=0x3f3f3f3f;
struct edge {
    int to,c,cst,nxt;
}e[M];
int n,s=0,t,maxflow=0,maxcost=0;
int hd[N],cnt=1;
int dis[N],cur[N];
bool vis[N];
int mp[N][N];
inline int getid (int x,int y) {return (x-1)*n+y;}
inline int getin (int x,int y) {return getid(x,y);}
inline int getout (int x,int y) {return getid(x,y)+n*n;}
void addedge (int u,int v,int c,int cst) {
    e[++cnt]={v,c,-cst,hd[u]},hd[u]=cnt;
    e[++cnt]={u,0,cst,hd[v]},hd[v]=cnt;
}
void build () {
    t=2*n*n+1;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            int in=getin(i,j),out=getout(i,j);
            addedge(in,out,1,mp[i][j]);
            addedge(in,out,inf,0);
            if (i+1<=n) addedge(out,getin(i+1,j),inf,0);
            if (j+1<=n) addedge(out,getin(i,j+1),inf,0);
        }
    }
    addedge(s,getin(1,1),2,0);
    addedge(getout(n,n),t,2,0);
}
bool spfa () {
    memset(dis,0x3f,sizeof dis);
    memset(vis,0,sizeof vis);
    queue<int> q;
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
    vis[u]=1;
    int res=0;
    for (int &i=cur[u];i;i=e[i].nxt) {
        if (flow==res) break;
        auto [v,c,cst,nxt]=e[i];
        if (!vis[v]&&c>0&&dis[v]==dis[u]+cst) {
            int nw=dfs(v,min(c,flow-res));
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
void mcmf () {
    while (spfa()) {
        int res=dfs(s,inf);
        maxflow+=res;
        maxcost-=res*dis[t];
    }
}
signed main() {
    Cios;
    cin>>n;
    while (1) {
        int x,y,v;
        cin>>x>>y>>v;
        if (x==0) break;
        mp[x][y]=v;
    }
    build();
    mcmf();
    cout<<maxcost<<"\n";
    return 0;
}