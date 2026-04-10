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
int n,m;
vector <int> g[N];
// int k[N];
vector <pair <int,int>> k[N];
bool vis[N];
int siz[N],mxs[N];
int tag[N],res[N];
void getroot (int u,int f,int tsiz,int &rt) {
    siz[u]=1;
    mxs[u]=-1;
    for (int v:g[u]) {
        if (v==f||vis[v]) continue;
        getroot(v,u,tsiz,rt);
        siz[u]+=siz[v];
        mxs[u]=max(mxs[u],siz[v]); 
    }
    mxs[u]=max(mxs[u],tsiz-siz[u]);
    if (rt==0||mxs[rt]>mxs[u]) rt=u;
}
void getdis (int u,int f,int dep,vector <pair<int,int>> &dis) {
    dis.push_back({dep,u});
    for (int v:g[u]) {
        if (v==f||vis[v]) continue;
        getdis(v,u,dep+1,dis);
    }
}
void getsiz (int u,int f,int &sz) {
    sz++;
    for (int v:g[u]) {
        if (v==f||vis[v]) continue;
        getsiz(v,u,sz);
    }
}
void solve (int u) {
    vis[u]=1;
    vector <int> vised;
    tag[0]=1;
    for (int v:g[u]) {
        if (vis[v]) continue;
        vector <pair<int,int>> dis;
        getdis(v,u,1,dis);
        for (auto [dep,t]:dis) {
            if (k[t].size()) {
                for (auto [hsr,idx]:k[t]) {
                    if (hsr>=dep) res[idx]+=tag[hsr-dep];
                }
            }
        }
        for (auto [dep,t]:dis) tag[dep]++,vised.push_back(dep);
    }
    if (k[u].size()) {
        for (auto [hsr,idx]:k[u]) res[idx]+=tag[hsr];
    }
    for (int dep:vised) tag[dep]--;
    vised.clear();
    tag[0]=0;
    for (int i=g[u].size()-1;i>=0;i--) {
        int v=g[u][i];
        if (vis[v]) continue;
        vector <pair<int,int>> dis;
        getdis(v,u,1,dis);
        for (auto [dep,t]:dis) {
            if (k[t].size()) {
                for (auto [hsr,idx]:k[t]) {
                    if (hsr>=dep) res[idx]+=tag[hsr-dep];
                }
            }
        }
        for (auto [dep,t]:dis) tag[dep]++,vised.push_back(dep);
    }
    for (int dep:vised) tag[dep]--;
    for (int v:g[u]) {
        if (vis[v]) continue;
        int rt=0,tsiz=0;
        getsiz(v,u,tsiz);
        getroot(v,u,tsiz,rt);
        solve(rt);
    }
}
signed main() {
    Cios;
    int T;
    cin>>T;
    while (T--) {
        cin>>n>>m;
        for (int i=1;i<n;i++) {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for (int i=1;i<=m;i++) {
            int x,k;
            cin>>x>>k;
            ::k[x].push_back({k,i});
        }
        int rt=0;
        getroot (1,0,n,rt);
        solve(rt);
        for (int i=1;i<=m;i++) cout<<res[i]<<"\n",res[i]=0;
        for (int i=1;i<=n;i++) {
            g[i].clear();
            k[i].clear();
            vis[i]=0;
        }
    }
    return 0;
}