/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e5+10;
int h[N],idx=1;
struct node {
    int v,c,nxt;
}e[N*20];
int n,m,s,t;
int mf[N],pre[N];
void add (int u,int v,int c) {
    e[++idx]={v,c,h[u]};
    h[u]=idx;
}
bool bfs () {
    memset (mf,0,sizeof mf);
    queue <int> q;
    q.push(s);
    mf[s]=1e9;
    while (q.size()) {
        int u=q.front();
        q.pop();
        for (int i=h[u];i;i=e[i].nxt) {
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
    cin>>n>>m>>s>>t;
    while(m--){
        int u,v,c;
        cin>>u>>v>>c;
        add(u,v,c);
        add(v,u,0);
    }
    cout<<ek();
    return 0;
}