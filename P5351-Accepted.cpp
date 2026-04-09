/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e5+10,inf=(1<<30);
struct edge {
    int to,w;
};
int n,l,r;
vector <edge> g[N];
bool vis[N];
int siz[N],mxs[N];
class Fenwick {
    int tr[N];
    inline int lb (int x) {return x&(-x);}
    public:
    void update (int p,int w) {
        if (p<0) return;
        p++;
        while (p<N) {
            tr[p]+=w;
            p+=lb(p);
        }
    }
    int query (int p) {
        if (p<0) return 0;
        p++;
        int res=0; 
        while (p) {
            res+=tr[p];
            p-=lb(p);
        }
        return res;
    }
    int query (int l,int r) {
        return query(r)-query(l-1);
    }
}bit;
void getroot (int u,int f,int tsiz,int &rt) {
    siz[u]=1;
    mxs[u]=-1;
    for (auto [v,w]:g[u]) {
        if (vis[v]||v==f) continue;
        getroot (v,u,tsiz,rt);
        siz[u]+=siz[v];
        mxs[u]=max(mxs[u],siz[v]);
    }
    mxs[u]=max(mxs[u],tsiz-siz[u]);
    if (rt==0||mxs[rt]>mxs[u]) rt=u;
}
void getdis (int u,int f,int wei,int dep,vector<pair<int,int>>& dis) {
    dis.push_back({wei,dep});
    for (auto [v,w]:g[u]) {
        if (vis[v]||v==f) continue;
        getdis(v,u,max(wei,w),dep+1,dis);
    }
}
void getsz (int u,int f,int& sz) {
    sz++;
    for (auto [v,w]:g[u]) {
        if (vis[v]||v==f) continue;
        getsz(v,u,sz);
    }
}
void solve (int u,int& res) {
    vis[u]=1;
    auto cmp=[&] (pair<int,int> a,pair<int,int> b) {return a.first<b.first;};
    vector <pair<int,int>> vised;
    vised.push_back({0,0});
    for (auto [v,w]:g[u]) {
        if (vis[v]) continue;
        vector <pair<int,int>> dis;
        getdis(v,u,w,1,dis);
        sort (dis.begin(),dis.end(),cmp);
        for (auto [wei,dep]:dis) res-=wei*bit.query(l-dep,r-dep),bit.update(dep,1);
        for (auto [wei,dep]:dis) bit.update(dep,-1);
        for (auto val:dis) vised.push_back(val);
    }
    sort(vised.begin(),vised.end(),cmp);
    for (auto [wei,dep]:vised) res+=wei*bit.query(l-dep,r-dep),bit.update(dep,1);
    for (auto [wei,dep]:vised) bit.update(dep,-1);
    for (auto [v,w]:g[u]) {
        if (vis[v]) continue;
        int rt=0,tsiz=0;
        getsz(v,u,tsiz);
        getroot(v,u,tsiz,rt);
        solve(rt,res);
    }
}
signed main() {
    Cios;
    cin>>n>>l>>r;
    for (int i=1;i<n;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    int rt=0,res=0;
    getroot(1,0,n,rt);
    solve(rt,res);
    cout<<res*2<<"\n";
    return 0;
}