/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e4+10,inf=(1<<30);
int n,m,s=0,t;
struct edge {
    int v,c,nxt;
}e[N*20];
int eidx=1,hd[N],cur[N],lv[N];
inline int get(int x,int y) {return (x-1)*m+y;}
inline bool id(int x,int y) {return (x+y)%2;}
void addedge (int u,int v,int w) {
    e[++eidx]={v,w,hd[u]},hd[u]=eidx;
    e[++eidx]={u,0,hd[v]},hd[v]=eidx;
}
int dfs (int u,int fl) {
    if (u==t||fl==0) return fl;
    int res=0;
    for (int &i=cur[u];~i;i=e[i].nxt) {
        auto [v,c,nxt]=e[i];
        if (c>0&&lv[u]+1==lv[v]) {
            int nw=dfs(v,min(c,fl-res));
            if (nw!=0) {
                e[i].c-=nw;
                e[i^1].c+=nw;
                res+=nw;
                if (res==fl) break;
            }
        }
    }
    return res;
}
bool bfs () {
    memset(lv,-1,sizeof lv);
    queue<int> q;
    q.push(s);
    lv[s]=1;
    while (q.size()) {
        int u=q.front();
        q.pop();
        cur[u]=hd[u];
        for (int i=hd[u];~i;i=e[i].nxt) {
            auto [v,c,nxt]=e[i];
            if (c>0&&lv[v]==-1) {
                q.push(v);
                lv[v]=lv[u]+1;
            }
        }
    }
    return lv[t]!=-1;
}
int Dinic () {
    int res=0;
    while (bfs()) res+=dfs(s,inf);
    return res;
}
signed main() {
    Cios;
    cin>>n>>m;
    t=n*m+1;
    int sum=0;
    memset(hd,-1,sizeof hd);
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            int w;
            cin>>w;
            sum+=w;
            int _id=get(i,j);
            if (id(i,j)) {
                addedge(s,_id,w);
                if (i-1>=1) addedge(_id,get(i-1,j),inf);
                if (i+1<=n) addedge(_id,get(i+1,j),inf);
                if (j-1>=1) addedge(_id,get(i,j-1),inf);
                if (j+1<=m) addedge(_id,get(i,j+1),inf);
            }
            else addedge(_id,t,w);
        }
    }
    cout<<sum-Dinic()<<"\n";
    return 0;
}