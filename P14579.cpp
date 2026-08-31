/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e3+10,M=5e5+10,inf=0x3f3f3f3f;
int n,m,s,t,ns,nt;
struct edge {
    int to,c,nxt;
}e[M];
int hd[N],cnt=1;
int lv[N],cur[N];
int pfl[N];
void addedge (int u,int v,int c) {
    e[++cnt]={v,c,hd[u]},hd[u]=cnt;
    e[++cnt]={u,0,hd[v]},hd[v]=cnt;
}
bool bfs (int s_,int t_) {
    queue<int> q;
    memset(lv,-1,sizeof lv);
    q.push(s_);
    cur[s_]=hd[s_];
    lv[s_]=1;
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
    return lv[t_]!=-1;
}
int dfs (int t_,int u,int flw) {
    if (u==t_||flw==0) return flw;
    int res=0;
    for (int &i=cur[u];~i;i=e[i].nxt) {
        if (flw==res) break;
        auto [v,c,nxt]=e[i];
        if (c>0&&lv[v]==lv[u]+1) {
            int nw=dfs(t_,v,min(flw-res,c));
            if (nw>0) {
                e[i].c-=nw;
                e[i^1].c+=nw;
                res+=nw;
            }
        }
    }
    return res;
}
int Dinic (int s_,int t_) {
    int res=0;
    while (bfs(s_,t_)) res+=dfs(t_,s_,inf);
    return res;
}
signed main() {
    Cios;
    cin>>n>>m>>s>>t;
    memset(hd,-1,sizeof hd);
    for (int i=1;i<=m;i++) {
        int u,v,l,r;
        cin>>u>>v>>l>>r;
        addedge(u,v,r-l);
        pfl[v]+=l;
        pfl[u]-=l;
    }
    ns=0;
    nt=n+1;
    int expt_flow=0;
    for (int i=1;i<=n;i++) {
        if (pfl[i]>0) addedge(ns,i,pfl[i]),expt_flow+=pfl[i];
        else if (pfl[i]<0) addedge(i,nt,-pfl[i]);
    }
    addedge(t,s,inf);
    int posb_flow=Dinic(ns,nt);
    if (posb_flow!=expt_flow) {
        cout<<"N\n";
        return 0;
    }
    int nw_flow=e[cnt].c;
    e[cnt].c=0;
    e[cnt^1].c=0;
    cout<<nw_flow+Dinic(s,t)<<"\n";
    return 0;
}