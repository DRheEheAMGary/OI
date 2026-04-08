/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e7+10;
class Fenwick {
    int tr[N];
    inline int lb (int x) {return x&(-x);}
    public:
    inline void update (int p,int w) {
        if (p<0) return;
        p++;
        while (p<N) {
           tr[p]+=w;
           p+=lb(p); 
        }
    }
    inline int query (int p) {
        if (p<0) return 0;
        p++;
        int res=0;
        while (p) {
            res+=tr[p];
            p-=lb(p);
        }
        return res;
    }
    inline int queryInterval (int l,int r) {
        return query(r)-query(l-1);
    }
}bit,bbit;
int n,k,r;
vector <int> g[N];
int res,rt,tsiz;
bool vis[N];
int siz[N],mxs[N];
inline void getroot (int u,int f) {
    siz[u]=1;
    mxs[u]=0;
    for (auto v:g[u]) {
        if (v==f||vis[v]) continue;
        getroot(v,u);
        siz[u]+=siz[v];
        mxs[u]=max(mxs[u],siz[v]);
    }
    mxs[u]=max(mxs[u],tsiz-siz[u]);
    if (rt==0||mxs[rt]>mxs[u]) rt=u;
}
vector <int> dis;
inline void getdist (int u,int f,int d) {
    if (d>r) return;
    dis.push_back(d);
    for (auto v:g[u]) {
        if (v==f||vis[v]) continue;
        getdist(v,u,d+1);
    }
}
inline void gettsiz (int u,int f,int& sz) {
    sz++;
    for (auto v:g[u]) {
        if (v==f||vis[v]) continue;
        gettsiz(v,u,sz); 
    }
}
inline void solve (int u) {
    bbit.update(0,1);
    vis[u]=1;
    vector <int> vised;
    for (auto v:g[u]) {
        if (vis[v]) continue;
        dis.clear();
        getdist (v,u,1);
        for (int d:dis) res+=bit.queryInterval(k-d,r-d)+d*bbit.queryInterval(k-d,r-d);
        for (int d:dis) {
            if (d<=r) {
                bit.update(d,d);
                bbit.update(d,1);
                vised.push_back(d);
            }
        }
    }
    bbit.update(0,-1);
    for (int vd:vised)  bit.update(vd,-vd),bbit.update(vd,-1);
    for (auto v:g[u]) {
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
    cin>>n>>k>>r;
    for (int i=2;i<=n;i++) {
        int f;
        cin>>f;
        g[i].push_back(f);
        g[f].push_back(i);
    }
    rt=0;
    tsiz=n;
    getroot(1,0);
    solve(rt);
    cout<<res<<"\n";
    return 0;
}