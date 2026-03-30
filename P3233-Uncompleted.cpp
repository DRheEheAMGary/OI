/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=3e5+10,inf=(1ll<<40);
int n,m;
vector <int> g[N],ng[N];
int dfn[N],sz[N],dep[N],fa[N][40];
int imp[N],isimp[N];
int dfncnt=0;
int bel[N],nwsz[N],mind[N];
void dfs(int u,int f) {
    dfn[u]=++dfncnt;
    sz[u]=1;
    fa[u][0]=f;
    for (int i=1;i<=30;i++) fa[u][i]=fa[fa[u][i-1]][i-1];
    for (auto v:g[u]) {
        if (v==f) continue;
        dep[v]=dep[u]+1;
        dfs(v,u);
        sz[u]+=sz[v];
    }
}
int lca (int u,int v) {
    if (dep[u]<dep[v]) swap(u,v);
    for (int i=30;i>=0;i--) if (dep[fa[u][i]]>=dep[v]) u=fa[u][i];
    if (u==v) return u;
    for (int i=30;i>=0;i--) if (fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
    return fa[u][0];
}
template <class _tp> class Stack {
    _tp s[N];
    int top_=0;
public:
    void push (int x) {s[++top_]=x;}
    _tp top () {return s[top_];}
    _tp ptop () {return s[top_-1];}
    void pop () {top_--;}
    int size () {return top_;}
    void clear () {top_=0;}
};
Stack<int> st;
void build () {
    st.clear();
    st.push(1);
    if (imp[1]!=1) st.push(imp[1]);
    for (int i=2;i<=n;i++) {
        int lc=lca(st.top(),imp[i]);
        if (isimp[lc]) {
            mind[lc]=0;
            bel[lc]=lc;
        }
        else {
            mind[lc]=inf;
            bel[lc]=0;
        }
        while (st.size()>1&&dfn[st.ptop()]>=dfn[lc]) ng[st.ptop()].push_back(st.top()),st.pop();
        if (lc!=st.top()) ng[lc].push_back(st.top()),st.pop();
        st.push(imp[i]);
        mind[imp[i]]=0;
        bel[imp[i]]=imp[i];
    }
    while (st.size()>1) ng[st.ptop()].push_back(st.top()),st.pop();
}
void dfs1 (int u) {
    
}
signed main() {
    Cios;
    return 0;
}