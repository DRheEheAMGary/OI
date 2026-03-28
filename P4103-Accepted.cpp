/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e6+10,inf=1e15;
int n,k,imp[N];
vector <int> g[N],ng[N];
int fa[N],dep[N],sz[N],hv[N],dfn[N],top[N];
int dfncnt=0;
int sum[N],minr[N],maxr[N];
bool isimp[N];
int res,minres,maxres;
template <class _tp> class Stack {
    _tp s[N];
    int top_=0;
    public:
    void push (int p) {s[++top_]=p;}
    _tp top () {return s[top_];}
    _tp ptop () {return s[top_-1];}
    int size () {return top_;}
    void clear () {top_=0;}
    void pop () {top_--;}
};
Stack <int> st;
void dfs1 (int u) {
    dep[u]=dep[fa[u]]+1;
    sz[u]=1;
    for (int v:g[u]) {
        if (v==fa[u]) continue;
        fa[v]=u;
        dfs1(v);
        sz[u]+=sz[v];
        if (sz[v]>sz[hv[u]]) hv[u]=v;
    }
}
void dfs2 (int u,int tp) {
    dfn[u]=++dfncnt;
    top[u]=tp;
    if (hv[u]) dfs2(hv[u],tp);
    for (int v:g[u]) {
        if (v==fa[u]||v==hv[u]) continue;
        dfs2(v,v);
    }
}
int lca (int u,int v) {
    while (top[u]!=top[v]) {
        if (dep[top[v]]>dep[top[u]]) swap(u,v);
        u=fa[top[u]];
    }
    return (dep[u]<dep[v])?u:v;
}
void build () {
    st.clear();
    sort (imp+1,imp+1+k,[&] (int a,int b) {return dfn[a]<dfn[b];});
    st.push(1);
    if (imp[1]!=1) st.push(imp[1]);
    for (int i=2;i<=k;i++) {
        int lc=lca(st.top(),imp[i]);
        while (st.size()>1&&dfn[st.ptop()]>=dfn[lc]) ng[st.ptop()].push_back(st.top()),st.pop();
        if (lc!=st.top()) ng[lc].push_back(st.top()),st.pop(),st.push(lc);
        st.push(imp[i]);
    }
    while (st.size()>1) ng[st.ptop()].push_back(st.top()),st.pop();
}
void dodp (int u) {
    sum[u]=isimp[u];
    minr[u]=(!isimp[u])*inf;
    maxr[u]=(!isimp[u])*(-inf);
    for (int v:ng[u]) {
        dodp(v);
        int w=dep[v]-dep[u];
        if (sum[u]>0&&sum[v]>0) {
            minres=min(minres,minr[u]+minr[v]+w);
            maxres=max(maxres,maxr[u]+maxr[v]+w);
        }
        res+=w*sum[v]*(k-sum[v]);
        sum[u]+=sum[v];
        minr[u]=min(minr[u],minr[v]+w);
        maxr[u]=max(maxr[u],maxr[v]+w);
    }
    ng[u].clear();
    isimp[u]=0;
}
signed main() {
    Cios;
    cin>>n;
    for (int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1);
    dfs2(1,1);
    int q;
    cin>>q;
    while (q--) {
        cin>>k;
        for (int i=1;i<=k;i++) {
            cin>>imp[i];
            isimp[imp[i]]=1;
        }
        if (k<=1) {
            cout<<"0 0 0\n";
            if (k==1) isimp[imp[1]]=0;
            continue;
        }
        build();
        res=0;
        minres=inf;
        maxres=-inf;
        dodp(1);
        cout<<res<<" "<<minres<<" "<<maxres<<"\n";
    }
    return 0;
}