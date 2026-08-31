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
int n,m,q,sz,hanser=0,yousa=0;
int v[N],w[N],c[N];
int pos (int p) {
    return (p-1)/sz+1;
}
struct ques {
    int idx,l,r,t,lca,res;
}hr[N];
struct chag {
    int p,c;
}ly[N];
struct answ {
    int res,idx=0;
    int a[N<<1],st[N],ed[N],vis[N],cnt[N];
    void addst (int p) {
        idx++;
        a[idx]=p;
        st[p]=idx;
    }
    void added (int p) {
        idx++;
        a[idx]=p;
        ed[p]=idx;
    }
    void add (int p) {
        vis[p]^=1;
        if (vis[p]) res+=w[++cnt[c[p]]]*v[c[p]];
        else res-=w[cnt[c[p]]--]*v[c[p]];
    }
    int reslca (int l) {
        return w[cnt[c[l]]+1]*v[c[l]];
    }
}res;
class TreeLink {
    vector <int> g[N];
    int sz[N],dep[N],fa[N],hv[N],top[N];
    void dfs1 (int u) {
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
        res.addst(u);
        if (hv[u]) dfs2 (hv[u],rt);
        for (int v:g[u]) {
            if (v==hv[u]||v==fa[u]) continue;
            dfs2(v,v);
        }
        res.added(u);
    }
    public:
    void addEdge (int u,int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    void Init () {
        dfs1(1);
        dfs2(1,1);
    }
    int lca (int u,int v) {
        while (top[u]!=top[v]) {
            if (dep[top[u]]<dep[top[v]]) swap(u,v);
            u=fa[top[u]];
        } 
        return (dep[u]>dep[v]?v:u);
    }
}tl;
signed main(){
    Cios;
    cin>>n>>m>>q;
    sz=pow(n<<1,2.0/3);
    for (int i=1;i<=m;i++) cin>>v[i];
    for (int i=1;i<=n;i++) cin>>w[i];
    for (int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        tl.addEdge(u,v);
    }
    for (int i=1;i<=n;i++) cin>>c[i];
    tl.Init();
    for (int i=1;i<=q;i++) {
        int ty,x,y;
        cin>>ty>>x>>y;
        if (!ty) {
            ly[++yousa]={x,y};
        }
        else {
            int lc=tl.lca(x,y);
            if (res.st[x]>res.st[y]) swap(x,y);
            if (lc==x) hr[++hanser]={i,res.st[x],res.st[y],yousa,0,0};
            else hr[++hanser]={i,res.ed[x],res.st[y],yousa,lc,0};
        }
    }
    sort (hr+1,hr+1+hanser,
        [&] (ques a,ques b) {
            if (pos(a.l)!=pos(b.l)) return pos(a.l)<pos(b.l);
            if (pos(a.r)!=pos(b.r)) return pos(a.r)<pos(b.r);
            return a.t<b.t;
        }
    );
    for (int i=1,l=1,r=0,t=0;i<=hanser;i++) {
        while (l<hr[i].l) res.add(res.a[l++]);
        while (l>hr[i].l) res.add(res.a[--l]);
        while (r>hr[i].r) res.add(res.a[r--]);
        while (r<hr[i].r) res.add(res.a[++r]);
        while (t<hr[i].t) {
            t++;
            if (res.vis[ly[t].p]) {
                res.add(ly[t].p);
                swap(c[ly[t].p],ly[t].c);
                res.add(ly[t].p);
            }
            else swap(c[ly[t].p],ly[t].c);
        }
        while (t>hr[i].t) {
            if (res.vis[ly[t].p]) {
                res.add(ly[t].p);
                swap(c[ly[t].p],ly[t].c);
                res.add(ly[t].p);
            }
            else swap(c[ly[t].p],ly[t].c);
            t--;
        }
        hr[i].res=res.res;
        if (hr[i].lca) hr[i].res+=res.reslca(hr[i].lca);
    }
    sort (hr+1,hr+1+hanser,
        [&] (ques a,ques b) {return a.idx<b.idx;}
    );
    for (int i=1;i<=hanser;i++) cout<<hr[i].res<<"\n";
    return 0;
}