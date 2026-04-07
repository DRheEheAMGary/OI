/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e5+10,K=1e6+10;
int n,m,k;
struct edge {
    int to,w;
};
vector <edge> g[N];
int res;
bool vis[N];
int rt,tsiz;
int siz[N],mxs[N];
inline void getroot (int u,int f) {
    siz[u]=1;
    mxs[u]=0;
    for (auto [v,w]:g[u]) {
        if (v==f||vis[v]) continue;
        getroot(v,u);
        siz[u]+=siz[v];
        mxs[u]=max(mxs[u],siz[v]);
    }
    mxs[u]=max(mxs[u],tsiz-siz[u]);
    if (rt==0||mxs[u]<mxs[rt]) rt=u;
}
vector <int> dis;
inline void getdist (int u,int f,int d) {
    dis.push_back(d);
    for (auto [v,w]:g[u]) {
        if (v==f||vis[v]) continue;
        getdist (v,u,d+w);
    }
}
int tag[N];
signed main() {
    Cios;
    return 0;
}