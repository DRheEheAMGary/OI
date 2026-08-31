/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e5+10;
int n,m,val[N];
vector <int> g[N];
class DynamicSegmentTree {
    struct node {
        int lc,rc,sum;
    }tr[N*40];
    int nodecnt=0;
    public:
    void update (int &p,int l,int r,int pos,int val) {
        if (!p) p=++nodecnt;
        tr[p].sum+=val;
        if (l==r) return;
        int mid=(l+r)>>1;
        if (pos<=mid) update (tr[p].lc,l,mid,pos,val);
        else update (tr[p].rc,mid+1,r,pos,val);
    }
    int query (int p,int l,int r,int ql,int qr) {
        if (!p||l>r) return 0;
        if (ql<=l&&r<=qr) return tr[p].sum;
        int mid=(l+r)>>1,res=0;
        if (ql<=mid) res+=query(tr[p].lc,l,mid,ql,qr);
        if (qr> mid) res+=query(tr[p].rc,mid+1,r,ql,qr);
        return res;
    }
}dst1,dst2;
class Treelink {
    public:
    int fa[N],dep[N],dfn[N],siz[N],top[N],hv[N];
    int dfncnt=0;
    void dfs1 (int u) {
        dep[u]=dep[fa[u]]+1;
        siz[u]=1;
        for (int v:g[u]) {
            if (v==fa[u]) continue;
            fa[v]=u;
            dfs1(v);
            siz[u]+=siz[v];
            if (siz[v]>siz[hv[u]]) hv[u]=v;
        }
    }
    void dfs2 (int u,int tp) {
        top[u]=tp;
        dfn[u]=++dfncnt;
        if (hv[u]) dfs2(hv[u],tp);
        for (int v:g[u]) {
            if (v==fa[u]||v==hv[u]) continue;
            dfs2(v,v);
        }
    }
    int lca (int u,int v) {
        while (top[u]!=top[v]) {
            if (dep[top[u]]>dep[top[v]]) swap(u,v);
            v=fa[top[v]];
        }
        return (dep[u]>dep[v]?v:u);
    }
}tl;
int rt1[N],rt2[N];
int dis (int u,int v) {
    return tl.dep[u]+tl.dep[v]-2*tl.dep[tl.lca(u,v)];
}
int siz[N],mxs[N],fa[N];
bool vis[N];
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
    if (rt==0||mxs[u]<mxs[rt]) rt=u;
}
void getsiz (int u,int f,int &sz) {
    sz++;
    for (int v:g[u]) {
        if (v==f||vis[v]) continue;
        getsiz(v,u,sz);
    }
}
void build (int u,int f) {
    vis[u]=1;
    fa[u]=f;
    for (int v:g[u]) {
        if (vis[v]) continue;
        int tsiz=0;
        getsiz(v,u,tsiz);
        int rt=0;
        getroot(v,u,tsiz,rt);
        build(rt,u);
    }
}
void update (int u,int v) {
    int p=u;
    while (p) {
        dst1.update(rt1[p],0,n,dis(p,u),v);
        if (fa[u]) dst2.update(rt2[p],0,n,dis(fa[p],u),v);
        p=fa[p];
    }
}
int query (int u,int k) {
    int res=dst1.query(rt1[u],0,n,0,k);
    int p=u;
    while (fa[p]) {
        int d=dis(fa[p],u);
        if (k>=d) {
            res+=dst1.query(rt1[fa[p]],0,n,0,k-d);
            res-=dst2.query(rt2[p],0,n,0,k-d);
        }
        p=fa[p];
    }
    return res;
}
signed main() {
    Cios;
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>val[i];
    for (int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    tl.dfs1(1);
    tl.dfs2(1,1);
    int tsiz=n,rt=0;
    getroot(1,0,tsiz,rt);
    build(rt,0);
    for (int i=1;i<=n;i++) update(i,val[i]);
    int last=0;
    while (m--) {
        int op,x,y;
        cin>>op>>x>>y;
        x^=last;
        y^=last;
        if (op==0) {
            last=query(x,y);
            cout<<last<<"\n";
        }
        else {
            update(x,y-val[x]);
            val[x]=y;
        }
    }
    return 0;
}