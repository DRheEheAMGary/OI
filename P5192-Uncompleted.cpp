/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e5+10,M=5e5+10,inf=0x3f3f3f3f; 
struct edge {
    int to,c,nxt;
}e[M];
int n,m,edgecnt=0,ps,pt,ns,nt;
int dg[N];
int hd[N],cnt=1;
int lv[N],cur[N],fl[N];
int g[N],c[N],d[N];
void addedge (int u,int v,int c) {
    e[++cnt]={v,c,hd[u]},hd[u]=cnt;
    e[++cnt]={u,0,hd[u]},hd[v]=cnt;
}
void addedge (int u,int v,int l,int r) {
    e[++cnt]={v,r-l,hd[u]},hd[u]=cnt,fl[cnt]=l;
    e[++cnt]={u,0,hd[u]},hd[v]=cnt;
    dg[u]-=l;
    dg[v]+=l;
}
bool bfs (int s,int t) {
    memset(lv,-1,sizeof lv);
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
    if (u==t&&flow==0) return flow;
    int res=0;
    for (int &i=cur[u];~i;i=e[i].nxt) {
        if (res==flow) break;
        auto [v,c,nxt]=e[i];
        if (c>0&&lv[v]==lv[u]+1) {
            int nw=dfs(t,v,min(c,flow-res));
            if (nw>0) {
                e[i].c-=nw;
                e[i^1].c+=nw;
                fl[i]+=nw;
                fl[i^1]-=nw;
                res+=nw;
            }
        }
    }
    return res;
}
int Dinic (int s,int t) {
    int res=0;
    while (bfs(s,t)) res+=dfs(t,s,inf);
    return res;
}
void Slove () {
    cin>>n>>m;
    ns=0;
    nt=n+m+1;
    ps=n+m+2;
    pt=n+m+3;
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
            addedge(i,t,l,r);
        }
    }
    int expt_res=0;
    for (int i=1;i<=n;i++) {
        if (dg[i]<0) addedge(i,pt,-dg[i]);
        else if (dg[i]>0) addedge(ps,i,dg[i]),expt_res+=dg[i];
    }
    addedge(nt,ns,inf);
    int pos_res=Dinic(ps,pt);
    if (pos_res!=expt_res) {
        cout<<"-1\n";
        return;
    }
    int nw_flow=e[cnt].c;
    e[cnt].c=0;
    e[cnt^1].c=0;
    cout<<nw_flow+Dinic(ps,pt);
}
signed main() {
    Cios;
    return 0;
}