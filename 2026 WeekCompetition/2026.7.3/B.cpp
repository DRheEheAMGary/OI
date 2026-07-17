/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e5+10,inf=0x3f3f3f3f;
struct edge {
    int to,c,nxt;
}e[N];
int s,t;
int hd[N],cnt=1;
int lv[N],cur[N];
int n,m,bl[N],rd[N];
void addedge (int u,int v,int c) {
    cnt++,e[cnt]={v,c,hd[u]},hd[u]=cnt;
    cnt++,e[cnt]={u,0,hd[v]},hd[v]=cnt;
}
bool bfs () {
    for (int i=1;i<=n+m+2;i++) lv[i]=-1;
    queue<int> q;
    q.push(s);
    lv[s]=1;
    cur[s]=hd[s];
    while (q.size()) {
        int u=q.front();
        q.pop();
        cur[u]=hd[u];
        for (int i=hd[u];i;i=e[i].nxt) {
            auto [v,c,nxt]=e[i];
            if (c>0&&lv[v]==-1) {
                q.push(v);
                lv[v]=lv[u]+1;
            }
        }
    }
    return lv[t]!=-1;
}
int dfs (int u,int flow) {
    if (u==t||flow==0) return flow;
    int res=0;
    for (int &i=cur[u];i;i=e[i].nxt) {
        if (flow==res) break;
        auto [v,c,nxt]=e[i];
        if (c>0&&lv[u]+1==lv[v]) {
            int nw=dfs(v,min(c,flow-res));
            if (nw!=0) {
                e[i].c-=nw;
                e[i^1].c+=nw;
                res+=nw;
            }
        }
    }
    return res;
}
int Dinic () {
    int res=0;
    while (bfs()) res+=dfs(s,inf);
    return res;
}
signed main() {
    Cios;
    int T;
    cin>>T;
    while (T--) {
        cnt=1;
        cin>>n>>m;
        for (int i=1;i<=n;i++) cin>>bl[i];
        for (int i=1;i<=m;i++) cin>>rd[i];
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) {
                int g=__gcd(bl[i],rd[j]);
                if (g!=1) addedge(i,n+j,1);
            }
        }
        s=n+m+1;
        t=n+m+2;
        for (int i=1;i<=n;i++) addedge(s,i,1);
        for (int i=1;i<=m;i++) addedge(n+i,t,1);
        cout<<Dinic()<<"\n";
        for (int i=1;i<=cnt;i++) e[i]={0,0,0};
        for (int i=1;i<=n+m+2;i++) hd[i]=0;
    }
    return 0;
}