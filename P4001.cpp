/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e6+10;
int n,m;
inline int getid (int x,int y) {return (x-1)*m+y;}
int h[N],idx=1;
struct node {
    int v,c,nxt;
}e[N*10];
int s,t;
int mf[N],pre[N];
void add (int u,int v,int c) {
    e[++idx]={v,c,h[u]};
    h[u]=idx;
    e[++idx]={u,c,h[v]};
    h[v]=idx;
}
bool bfs () {
    fill(mf,mf+1+t,0);
    queue <int> q;
    q.push(s);
    mf[s]=1e9;
    while (q.size()) {
        int u=q.front();
        q.pop();
        for (int i=h[u];~i;i=e[i].nxt) {
            int v=e[i].v;
            if (!mf[v]&&e[i].c) {
                mf[v]=min(mf[u],e[i].c);
                pre[v]=i;
                q.push(v);
                if (v==t) return 1;
            }
        }
    }
    return 0;
}
int ek() {
    int res=0;
    while (bfs()) {
        int v=t;
        while (v!=s) {
            int ei=pre[v];
            e[ei].c-=mf[t];
            e[ei^1].c+=mf[t];
            v=e[ei^1].v;
        }
        res+=mf[t];
    }
    return res;
}
signed main() {
    Cios;
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for (int i=1;i<=n;i++) {
        for (int j=1;j<m;j++) {
            int w;
            cin>>w;
            add(getid(i,j),getid(i,j+1),w);
        }
    }
    for (int i=1;i<n;i++) {
        for (int j=1;j<=m;j++) {
            int w;
            cin>>w;
            add(getid(i,j),getid(i+1,j),w);
        }
    }
    for (int i=1;i<n;i++) {
        for (int j=1;j<m;j++) {
            int w;
            cin>>w;
            add(getid(i,j),getid(i+1,j+1),w);
        }
    }
    s=getid(1,1);
    t=getid(n,m);
    cout<<ek();
    return 0;
}