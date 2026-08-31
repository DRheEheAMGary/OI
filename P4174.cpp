/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=6e4+10,M=4e5+10,inf=(1<<30);
struct edge {
    int to,c,nxt;
}e[M];
int hd[N],cnt=1;
int lv[N],cur[N];
void add_edge (int u,int v,int c) {
    e[++cnt]={v,c,hd[u]};
    hd[u]=cnt;
    e[++cnt]={u,0,hd[v]};
    hd[v]=cnt;
}
bool bfs (int s,int t) {
    memset(lv,-1,sizeof lv);
    lv[s]=0;
    queue <int> q;
    q.push(s);
    while (q.size()) {
        int u=q.front();
        q.pop();
        for (int i=hd[u];i;i=e[i].nxt) {
            int v=e[i].to;
            if (e[i].c>0&&lv[v]==-1) {
                lv[v]=lv[u]+1;
                q.push(v);
            }
        }
    }
    return lv[t]!=-1;
}
int dfs (int u,int t,int psed) {
    if (psed==0||u==t) return psed;
    int res=0;
    for (int &i=cur[u];i;i=e[i].nxt) {
        int v=e[i].to;
        if (lv[u]+1!=lv[v]||e[i].c==0) continue;
        int ps=dfs(v,t,min(psed-res,e[i].c));
        if (ps==0) continue;
        e[i].c-=ps;
        e[i^1].c+=ps;
        res+=ps;
        if (res==psed) break;
    }
    return res;
}
int Dinic (int s,int t) {
    int res=0;
    while (bfs(s,t)) {
        for (int i=0;i<=t;i++) cur[i]=hd[i];
        while (int psed=dfs(s,t,inf)) res+=psed;
    }
    return res;
} 
signed main() {
    Cios;
    int n,m;
    cin>>n>>m;
    int s=0,t=n+m+1;
    for (int i=1;i<=n;i++) {
        int p;
        cin>>p;
        add_edge(i,t,p);
    }
    int tot=0;
    for (int i=1;i<=m;i++) {
        int a,b,c;
        cin>>a>>b>>c;
        tot+=c;
        add_edge(s,n+i,c);
        add_edge(n+i,a,inf);
        add_edge(n+i,b,inf);
    }
    cout<<tot-Dinic(s,t);
    return 0;
}