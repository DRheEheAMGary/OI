/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=4e4+10,K=2e4+10;
class Fenwick {
    int tr[K];
    inline int lb (int x) {return x&(-x);}
    public:
    void update (int p,int w) {
        p++;
        while (p<K) {
           tr[p]+=w;
           p+=lb(p); 
        }
    }
    int query (int p) {
        p++;
        int res=0;
        while (p) {
            res+=tr[p];
            p-=lb(p);
        }
        return res;
    }
}bit;
int n,k;
struct edge {
    int to,w;
};
vector <edge> g[N];
int res,rt,tsiz;
bool vis[N];
int siz[N],mxs[N];
void getroot (int u,int f) {
    siz[u]=1;
    mxs[u]=0;
    for (auto [v,w]:g[u]) {
        if (v==f||vis[v]) continue;
        getroot(v,u);
        siz[u]+=siz[v];
        mxs[u]=max(mxs[u],siz[v]);
    }
    mxs[u]=max(mxs[u],tsiz-siz[u]);
    if (rt==0||mxs[rt]>mxs[u]) rt=u;
}
vector <int> dis;
void getdist (int u,int f,int d) {
    if (d>k) return;
    dis.push_back(d);
    for (auto [v,w]:g[u]) {
        if (v==f||vis[v]) continue;
        getdist(v,u,d+w);
    }
}
void gettsiz (int u,int f,int& sz) {
    sz++;
    for (auto [v,w]:g[u]) {
        if (v==f||vis[v]) continue;
        gettsiz(v,u,sz); 
    }
}
void solve (int u) {
    bit.update(0,1);
    vis[u]=1;
    vector <int> vised;
    for (auto [v,w]:g[u]) {
        if (vis[v]) continue;
        dis.clear();
        getdist (v,u,w);
        for (int d:dis) res+=bit.query(k-d);
        for (int d:dis) {
            if (d<=k) {
                bit.update(d,1);
                vised.push_back(d);
            }
        }
    }
    bit.update(0,-1);
    for (int vd:vised)  bit.update(vd,-1);
    for (auto [v,w]:g[u]) {
        if (vis[v]) continue;
        rt=0;
        tsiz=0;
        gettsiz(v,u,tsiz);
        getroot(v,u);
        solve(rt);
    }
}
signed main() {
    Cios;
    cin>>n;
    for (int i=1;i<n;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    cin>>k;
    rt=0;
    tsiz=n;
    getroot(1,0);
    solve(rt);
    cout<<res<<"\n";
    return 0;
}