/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#ifdef CLANGD_
intc N=3e2+10;
#else
intc N=3e5+10;
#endif
intc mod1=1e9+7,mod2=1e9+9;
mt19937 rnd(time(0));
int n,c[N],ch[N];
int fa[N];
vector <int> g[N];
struct pSegmentTree {
    struct HAnSerH {
        int h1,h2;
        bool operator== (const HAnSerH &h) const {return h1==h.h1&&h2==h.h2;}
        bool operator!= (const HAnSerH &h) const {return h1!=h.h1||h2!=h.h2;}
        HAnSerH operator+ (const HAnSerH &h) const {return {(h1+h.h1)%mod1,(h2+h.h2)%mod2};}
        HAnSerH operator- (const HAnSerH &h) const {return {((h1-h.h1)%mod1+mod1)%mod1,((h2-h.h2)%mod2+mod2)%mod2};}
    };
    struct node {
        int lc,rc;
        HAnSerH h;
    }tr[N*20];
    int pcnt=0;
    int root[N];
    public:
    inline int newnode () {
        tr[++pcnt]={0,0,{0,0}};
        return pcnt;
    }
    inline int copynode (int cur) {
        tr[++pcnt]=tr[cur];
        return pcnt;
    }
    inline int& lc (int p) {return tr[p].lc;}
    inline int& rc (int p) {return tr[p].rc;}
    inline node& lct (int p) {return tr[lc(p)];}
    inline node& rct (int p) {return tr[rc(p)];}
    inline int& rt (int p) {return root[p];}
    inline void pushup (int p) {tr[p].h=lct(p).h+rct(p).h;}
    inline HAnSerH lhsum (int u,int v,int lca,int fl) {return lct(u).h+lct(v).h-lct(lca).h-lct(fl).h;}
    inline HAnSerH rhsum (int u,int v,int lca,int fl) {return rct(u).h+rct(v).h-rct(lca).h-rct(fl).h;}
    inline void update (int &p,int cur,int q,int l=0,int r=n) {
        p=copynode(cur);
        if (l==r) {
            tr[p].h=tr[p].h+(HAnSerH){ch[q],ch[q]};
            return;
        }
        int mid=(l+r)>>1;
        if (q<=mid) update(lc(p),lc(p),q,l,mid);
        else update(rc(p),rc(p),q,mid+1,r);
        pushup(p);
    }
    // inline HAnSerH query (int p,int ql,int qr,int l=1,int r=n) {
    //     if (!p) return {0,0};
    //     if (ql<=l&&r<=qr) return tr[p].h;
    //     int mid=(l+r)>>1;
    //     HAnSerH res={0,0};
    //     if (ql<=mid) res=res+query(lc(p),ql,qr,l,mid);
    //     if (qr>mid) res=res+query(rc(p),ql,qr,mid+1,r);
    //     return res;
    // }
    inline int BirQuery (int u1,int v1,int lca1,int fl1,int u2,int v2,int lca2,int fl2,int l=0,int r=n) {
        HAnSerH lh1=lhsum(u1,v1,lca1,fl1),rh1=rhsum(u1,v1,lca1,fl1),
                lh2=lhsum(u2,v2,lca2,fl2),rh2=rhsum(u2,v2,lca2,fl2);
        int mid=(l+r)>>1;
        if (l==r) return l-1;
        else if (lh1!=lh2) return BirQuery (lc(u1),lc(v1),lc(lca1),lc(fl1),lc(u2),lc(v2),lc(lca2),lc(fl2),l,mid);
        else if (rh1!=rh2) return BirQuery (rc(u1),rc(v1),rc(lca1),rc(fl1),rc(u2),rc(v2),rc(lca2),rc(fl2),mid+1,r);
        else return r;
    }
}pst;
int sz[N],hv[N],top[N],dep[N];
void dfs1 (int u) {
    pst.update(pst.rt(u),pst.rt(fa[u]),c[u]);
    sz[u]=1;
    dep[u]=dep[fa[u]]+1;
    for (int v:g[u]) {
        if (v==fa[u]) continue;
        fa[v]=u;
        dfs1(v);
        sz[u]+=sz[v];
        if (sz[hv[u]]<sz[v]) hv[u]=v;
    }
}
void dfs2 (int u,int rt) {
    top[u]=rt;
    if (hv[u]) dfs2(hv[u],rt);
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
signed main() {
    Cios;
    // freopen ("sample1.in","r",stdin);
    // freopen ("sample.out","w",stdout);
    cin>>n;
    for (int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i=1;i<=n;i++) cin>>c[i],ch[c[i]]=rnd();
    dfs1(1);
    dfs2(1,1);
    int q;
    cin>>q;
    while (q--) {
        int u1,v1,u2,v2;
        cin>>u1>>v1>>u2>>v2;
        int l1=lca(u1,v1),l2=lca(u2,v2);
        cout<<pst.BirQuery(pst.rt(u1),pst.rt(v1),pst.rt(l1),pst.rt(fa[l1]),pst.rt(u2),pst.rt(v2),pst.rt(l2),pst.rt(fa[l2]))<<"\n";
    }
    return 0;
}

/*
g++ -g tree.cpp -o tree.exe -O2 -std=c++14 -static ; echo "finish" ; ./tree

*/