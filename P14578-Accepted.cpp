/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e3+10,M=3e4+10,inf=0x3f3f3f3f;
struct edge {
    int to,c,fl,nxt;
}e[M];
int n,m,s,t;
int hd[N],cnt=1;
int lv[N],cur[N];
int ifl[N],ofl[N];
int dwn[M];
void add (int u,int v,int c,int fl,int _dwn) {
    e[++cnt]={v,c,fl,hd[u]};
    hd[u]=cnt;
    dwn[cnt]=_dwn;
}
bool bfs () {
    memset(lv,-1,sizeof lv);
    queue<int> q;
    q.push(s);
    lv[s]=1;
    cur[s]=hd[s];
    while (q.size()) {
        int u=q.front();
        q.pop();
        for (int i=hd[u];~i;i=e[i].nxt) {
            auto [v,c,fl,nxt]=e[i];
            if (c-fl>0&&lv[v]==-1) {
                cur[v]=hd[v];
                lv[v]=lv[u]+1;
                q.push(v);
            }
        }
    }
    return lv[t]!=-1;
}
int dfs (int u,int flow) {
    if (u==t||flow==0) return flow;
    int res=0;
    for (int &i=cur[u];~i;i=e[i].nxt) {
        if (flow==res) break;
        auto [v,c,fl,nxt]=e[i];
        if (c-fl>0&&lv[v]==lv[u]+1) {
            int nw=dfs(v,min(c-fl,flow-res));
            if (nw>0) {
                e[i].fl+=nw;
                e[i^1].fl-=nw;
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
    cin>>n>>m;
    memset(hd,-1,sizeof hd);
    for (int i=1;i<=m;i++) {
        int u,v,l,r;
        cin>>u>>v>>l>>r;
        add(u,v,r-l,0,l);
        add(v,u,0,0,l);
        ifl[v]+=l;
        ofl[u]+=l;
    }
    s=0;
    t=n+1;
    int tot=0;
    for (int i=1;i<=n;i++) {
        if (ifl[i]<ofl[i]) {
            add(i,t,ofl[i]-ifl[i],0,-1);
            add(t,i,0,0,-1);    
            tot+=ofl[i]-ifl[i];
        }
        if (ifl[i]>ofl[i]) {
            add(s,i,ifl[i]-ofl[i],0,-1);
            add(i,s,0,0,-1);
        }
    }
    int res=Dinic();
    if (res!=tot) {
        cout<<"No\n";
        return 0;
    }
    cout<<"Yes\n";
    for (int i=2;i<=2*m;i+=2) cout<<e[i].fl+dwn[i]<<"\n";
    return 0;
}