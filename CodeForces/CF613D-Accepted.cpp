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
vector <int> g[N],ng[N];
int dfncnt=0,fa[N],dep[N],siz[N],dfn[N],hv[N],top[N];
int n;
int k,imp[N];
template <class _tp> class Stack {
    _tp st[N];
    int top_=0;
    public:
    void push (int p) {st[++top_]=p;}
    void pop () {top_--;}
    _tp top () {return st[top_];}
    _tp ptop () {return st[top_-1];}
    int size () {return top_;}
    void clear () {top_=0;}
};
Stack<int> st;
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
int res,mk[N];
void dodp (int u) {
    if (mk[u]) {
        for (int v:ng[u]) {
            dodp(v);
            if (mk[v]) res++,mk[v]=0;
        }
    }
    else {
        for (int v:ng[u]) {
            dodp(v);
            mk[u]+=mk[v],mk[v]=0;
        }
        if (mk[u]>1) res++,mk[u]=0;
    }
    ng[u].clear();
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
        for (int i=1;i<=k;i++) cin>>imp[i],mk[imp[i]]=1;
        bool sld=1;
        for (int i=1;i<=k;i++) {
            if (mk[fa[imp[i]]]) {
                sld=0;
                cout<<"-1\n";
                break;
            }
        }
        if (!sld) {
            st.clear();
            for (int i=1;i<=k;i++) mk[imp[i]]=0;
            continue;
        }
        build();
        dodp(1);
        cout<<res<<"\n";
        res=0;
        st.clear();
        mk[1]=0;
    }
    return 0;
}