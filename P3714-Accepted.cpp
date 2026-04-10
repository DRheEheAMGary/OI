/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e5+10,inf=(1ll<<60);
int n,m,l,r;
struct edge {
    int to,c;
};
vector <edge> g[N];
int cw[N];
bool vis[N];
int siz[N],mxs[N];
class SegmentTree {
    int tr[N<<2];
    inline int lc (int p) {return p<<1;}
    inline int rc (int p) {return p<<1|1;}
    void pushup (int p) {
        tr[p]=max(tr[lc(p)],tr[rc(p)]);
    }
    public:
    void build (int p=1,int l=0,int r=N) {
        tr[p]=-inf;
        if (l==r) return;
        int mid=(l+r)>>1;
        build(lc(p),l,mid);
        build(rc(p),mid+1,r);
    }
    void update (int q,int w,int p=1,int l=0,int r=N) {
        if (l==r) return tr[p]=max(tr[p],w),void();
        int mid=(l+r)>>1;
        if (q<=mid) update(q,w,lc(p),l,mid);
        else update (q,w,rc(p),mid+1,r);
        pushup(p);
    }
    int query (int ql,int qr,int p=1,int l=0,int r=N) {
        if (ql<=l&&r<=qr) return tr[p];
        int mid=(l+r)>>1;
        int res=-inf;
        if (ql<=mid) res=max(res,query(ql,qr,lc(p),l,mid));
        if (qr> mid) res=max(res,query(ql,qr,rc(p),mid+1,r));
        return res;
    }
    void clear (int clr,int p=1,int l=0,int r=N) {
        if (l==r) return tr[p]=-inf,void();
        int mid=(l+r)>>1;
        if (clr<=mid) clear(clr,lc(p),l,mid);
        else clear(clr,rc(p),mid+1,r);
        pushup(p); 
    }
}stp,stq;
void getroot (int u,int f,int tsiz,int &rt) {
    siz[u]=1;
    mxs[u]=-1;
    for (auto [v,c]:g[u]) {
        if (v==f||vis[v]) continue;
        getroot(v,u,tsiz,rt);
        siz[u]+=siz[v];
        mxs[u]=max(mxs[u],siz[v]);
    }
    mxs[u]=max(mxs[u],tsiz-siz[u]);
    if (rt==0||mxs[rt]>mxs[u]) rt=u;
}
void getdis (int u,int f,int lstc,int dep,int wei,vector <pair<int,int>> &dis) {
    dis.push_back({dep,wei});
    for (auto [v,c]:g[u]) {
        if (v==f||vis[v]) continue;
        int w=cw[c];
        getdis(v,u,c,dep+1,wei+w*(lstc!=c),dis);
    }
}
void getsiz (int u,int f,int &sz) {
    sz++;
    for (auto [v,c]:g[u]) {
        if (v==f||vis[v]) continue;
        getsiz(v,u,sz);
    }
}
int res=-inf;
void solve (int u) {
    vis[u]=1;
    sort (g[u].begin(),g[u].end(),[&] (edge a,edge b) {return a.c<b.c;});
    int lstc=-1;
    vector <pair<int,int>> vised,tmp;
    stq.update(0,0);
    for (auto [v,c]:g[u]) {
        if (vis[v]) continue;
        vector <pair<int,int>> dis;
        getdis (v,u,c,1,cw[c],dis);
        if (lstc!=c) {
            lstc=c;
            for (auto [dep,wei]:tmp) stq.update(dep,wei),stp.clear(dep),vised.push_back({dep,wei});
            tmp.clear();
        }
        for (auto [dep,wei]:dis) res=max({res,stq.query(max(0ll,l-dep),max(0ll,r-dep))+wei,stp.query(max(0ll,l-dep),max(0ll,r-dep))+wei-cw[c]});
        for (auto [dep,wei]:dis) stp.update(dep,wei),tmp.push_back({dep,wei});
    }
    if (tmp.size()) {
        for (auto [dep,wei]:tmp) stp.clear(dep);
    }
    stq.clear(0);
    for (auto [dep,wei]:vised) stq.clear(dep);
    for (auto [v,c]:g[u]) {
        if (vis[v]) continue;
        int rt=0,tsiz=0;
        getsiz(v,u,tsiz);
        getroot(v,u,tsiz,rt);
        solve(rt);
    }
}
signed main() {
    Cios;
    cin>>n>>m>>l>>r;
    for (int i=1;i<=m;i++) cin>>cw[i];
    for (int i=1;i<n;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    int rt=0;
    stp.build();
    stq.build();
    getroot(1,0,n,rt);
    solve(rt);
    cout<<res<<"\n";
    return 0;
}