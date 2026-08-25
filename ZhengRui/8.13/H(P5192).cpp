/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e5+10,M=5e5+10,inf=(1ll<<60); 
struct edge {
    int to,c,nxt;
}e[M];
int n,m,ps,pt,ns,nt;
int dg[N];
int hd[N],cnt=1;
int lv[N],cur[N];
int g[N],c[N],d[N];
void addedge (int u,int v,int c) {
    e[++cnt]={v,c,hd[u]},hd[u]=cnt;
    e[++cnt]={u,0,hd[v]},hd[v]=cnt;
}
void addedge (int u,int v,int l,int r) {
    e[++cnt]={v,r-l,hd[u]},hd[u]=cnt;
    e[++cnt]={u,0,hd[v]},hd[v]=cnt;
    dg[u]-=l;
    dg[v]+=l;
}
bool bfs (int s,int t) {
    for(int i=0;i<=pt;i++) lv[i]=-1;
    lv[s]=1;
    cur[s]=hd[s];
    queue<int> q;
    q.push(s);
    while (q.size()) {
        int u=q.front();
        q.pop();
        for (int i=hd[u];~i;i=e[i].nxt) {
            auto [v,c,nxt]=e[i];
            if (c>0&&lv[v]==-1) {
                q.push(v);
                lv[v]=lv[u]+1;
                cur[v]=hd[v];
            }
        }
    }
    return lv[t]!=-1;
}
int dfs (int t,int u,int flow) {
    if (u==t||flow==0) return flow;
    int res=0;
    for (int &i=cur[u];~i;i=e[i].nxt) {
        auto [v,c,nxt]=e[i];
        if (c>0&&lv[v]==lv[u]+1) {
            int nw=dfs(t,v,min(c,flow-res));
            if (nw>0) {
                e[i].c-=nw;
                e[i^1].c+=nw;
                res+=nw;
                if (res==flow) break;
            }
        }
    }
    return res;
}
int Dinic (int s,int t) {
    int res=0;
    while (bfs(s,t)) {
        int flow;
        while ((flow=dfs(t,s,inf))) res+=flow;
    }
    return res;
}
void Solve () {
    ns=n+m+1;
    nt=n+m+2;
    ps=n+m+3;
    pt=n+m+4;
    for (int i=1;i<=m;i++) {
        cin>>g[i];
        addedge(n+i,nt,g[i],inf);
    }
    for (int i=1;i<=n;i++) {
        cin>>c[i]>>d[i];
        addedge(ns,i,0,d[i]);
        for (int j=1;j<=c[i];j++) {
            int t,l,r;
            cin>>t>>l>>r;
            t++;
            addedge(i,n+t,l,r);
        }
    }
    int expt_res=0;
    for (int i=0;i<=nt;i++) {
        if (dg[i]<0) addedge(i,pt,-dg[i]);
        else if (dg[i]>0) addedge(ps,i,dg[i]),expt_res+=dg[i];
    }
    addedge(nt,ns,inf);
    int pos_res=Dinic(ps,pt);
    if (pos_res!=expt_res) {
        cout<<"-1\n\n";
        return;
    }
    int nw_flow=e[cnt].c;
    e[cnt].c=0;
    e[cnt^1].c=0;
    cout<<nw_flow+Dinic(ns,nt)<<"\n\n";
}
void Clear () {
    cnt=1;
    memset(hd,-1,sizeof hd);
    memset(dg,0,sizeof dg);
    memset(cur,0,sizeof cur);
}
signed main() {
    Cios;
    while(cin>>n>>m) {
        Clear();
        Solve();
    }
    return 0;
}