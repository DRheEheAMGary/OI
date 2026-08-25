/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e5+10,H=505,M=1.3e6+10;
intc dx[]={0,1,-1,0,0},dy[]={0,0,0,1,-1};
int n,h,w,a,b,c;
struct edge {
    int to,w,nxt;
}e[M*6];
int s[N],t[N];
int hd[M];
int ecnt=0;
inline int id (int x,int y,int t) {return (x*(w+1)+y)*5+t;}
inline void addedge (int u,int v,int w) {e[++ecnt]={v,w,hd[u]},hd[u]=ecnt;}
inline void addedge (int ux,int uy,int ut,int vx,int vy,int vt,int w) {addedge(id(ux,uy,ut),id(vx,vy,vt),w);}
inline bool check (int x,int y) {return !(x<0||x>h||y<0||y>w);}
queue <pair <int,int>> q;
priority_queue <pair <int,int>,vector <pair<int,int>>,greater<pair <int,int>>> pq;
int dis[H][H],vis[H][H];
int disp[M],visp[M];
signed main() {
    Cios;
    cin>>h>>w>>a>>b>>c>>n;
    memset(dis,0x3f,sizeof dis);
    memset(disp,0x3f,sizeof disp);
    memset(hd,-1,sizeof hd);
    pair <int,int> st,ed;
    for (int i=1;i<=n;i++) {
        cin>>s[i]>>t[i];
        q.push({s[i],t[i]});
        dis[s[i]][t[i]]=0;
    }
    while (q.size()) {
        auto [_s,_t]=q.front();q.pop();
        if (vis[_s][_t]) continue;
        vis[_s][_t]=1;
        for (int i=1;i<=4;i++) {
            int ds=_s+dx[i],dt=_t+dy[i];
            if (!check(ds,dt)) continue;
            if (dis[ds][dt]>dis[_s][_t]+1) dis[ds][dt]=dis[_s][_t]+1,q.push({ds,dt});
        }
    }
    for (int i=0;i<=h;i++) {
        for (int j=0;j<=w;j++) {
            for (int d=1;d<=4;d++) if (check(i+dx[d],j+dy[d])) addedge(i,j,0,i+dx[d],j+dy[d],0,c);
            for (int d=1;d<=4;d++) addedge(i,j,0,i,j,d,b);
            for (int d=1;d<=4;d++) if (check(i+dx[d],j+dy[d])) addedge(i,j,d,i+dx[d],j+dy[d],d,a);
            for (int d=1;d<=4;d++) addedge(i,j,d,i,j,0,c*dis[i][j]);
        }
    }
    pq.push({0,id(s[1],t[1],0)});
    disp[id(s[1],t[1],0)]=0;
    while (pq.size()) {
        auto [_w,u]=pq.top();pq.pop();
        if (visp[u]) continue;
        visp[u]=1;
        for (int i=hd[u],v=e[i].to;~i;i=e[i].nxt,v=e[i].to) {
            if (visp[v]) continue;
            if (disp[v]>disp[u]+e[i].w) disp[v]=disp[u]+e[i].w,pq.push({disp[v],v});
        }
    }
    cout<<disp[id(s[n],t[n],0)]<<"\n";
    return 0;
}