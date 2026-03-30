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
int dfncnt=0;
int dep[N],siz[N],dfn[N],fa[N][30];
vector <int> g[N];
int k,imp[N];
vector <int> si;
vector <int> ng[N];
int mind[N],bel[N];
int res[N],rmsiz[N];
template <class _tp> class Stack {
    _tp s[N];
    int top_;
    public:
    void push (int x) {s[++top_]=x;}
    void pop () {top_--;}
    _tp top () {return s[top_];}
    _tp ptop () {return s[top_-1];}
    int size () {return top_;}
    void clear () {top_=0;}
};
Stack <int> st;
void dfs (int u,int f) {
    fa[u][0]=f;
    siz[u]=1;
    dep[u]=dep[f]+1;
    dfn[u]=++dfncnt;
    for (int i=1;i<=20;i++) fa[u][i]=fa[fa[u][i-1]][i-1];
    for (int v:g[u]) {
        if (v==f) continue;
        dfs(v,u);
        siz[u]+=siz[v];
    }
}
int lca (int u,int v) {
    if (dep[u]<dep[v]) swap(u,v);
    for (int i=20;i>=0;i--) {
        if (dep[fa[u][i]]>=dep[v]) u=fa[u][i];
    }
    if (u==v) return u;
    for (int i=20;i>=0;i--) {
        if (fa[u][i]!=fa[v][i]) {
            u=fa[u][i];
            v=fa[v][i];
        }
    }
    return fa[u][0];
}
void build () {
    sort (si.begin(),si.end(),[&] (int a,int b) {return dfn[a]<dfn[b];});
    st.clear();
    st.push(1);
    ng[1].clear();
    for (int u:si) {
        if (u==1) continue;
        int lc=lca(st.top(),u);
        if (lc!=st.top()) {
            while (st.size()>1&&dep[st.ptop()]>=dep[lc]) ng[st.ptop()].push_back(st.top()),st.pop();
            if (st.ptop()!=lc) ng[lc].push_back(st.top()),st.pop(),st.push(lc),mind[lc]=inf,bel[lc]=0;
        }
        st.push(u);
    }
    while (st.size()>1) ng[st.ptop()].push_back(st.top()),st.pop();
    st.clear();
}
void dfs1 (int u) {
    for (int v:ng[u]) {
        dfs1(v);
        if ((mind[u]>(mind[v]+dep[v]-dep[u]))||(mind[u]==(mind[v]+dep[v]-dep[u])&&bel[u]>bel[v])) {
            bel[u]=bel[v];
            mind[u]=mind[v]+dep[v]-dep[u];
        }
    }
}
void dfs2 (int u) {
    for (int v:ng[u]) {
        if (mind[v]>(mind[u]+dep[v]-dep[u])||(mind[v]==(mind[u]+dep[v]-dep[u])&&bel[v]>bel[u])) {
            bel[v]=bel[u];
            mind[v]=mind[u]+dep[v]-dep[u];
        }
        dfs2 (v);
    }
}
int jump (int u,int v) {
    for (int i=20;i>=0;i--) {
        if (dep[fa[v][i]]>dep[u])  v=fa[v][i];
    }
    return v;
}
int getmid (int u,int v) {
    int mid=v;
    for (int i=20;i>=0;i--) {
        int x=fa[mid][i];
        if (dep[x]>dep[u]) {
            int disu=mind[u]+dep[x]-dep[u],disv=mind[v]+dep[v]-dep[x];
            if (disu>disv||(disu==disv&&bel[u]>bel[v])) mid=x;
        }
    }
    return mid;
}
void dfsdp (int u) {
    rmsiz[u]=siz[u];
    for (int v:ng[u]) {
        dfsdp(v);
        int w=jump(u,v);
        rmsiz[u]-=siz[w];
        if (bel[u]==bel[v]) res[bel[u]]+=siz[w]-siz[v];
        else {
            int mid=getmid(u,v);
            res[bel[u]]+=siz[w]-siz[mid];
            res[bel[v]]+=siz[mid]-siz[v];
        }
    }
    res[bel[u]]+=rmsiz[u];
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
    for (int i=1;i<=n;i++) mind[i]=inf;
    dfs(1,0);
    cin>>m;
    while (m--) {
        cin>>k;
        for (int i=1;i<=k;i++) {
            cin>>imp[i];
            mind[imp[i]]=0;
            bel[imp[i]]=imp[i];
            si.push_back(imp[i]);
        }
        build();
        dfs1 (1);
        dfs2 (1);
        dfsdp(1);
        for (int i=1;i<=k;i++) cout<<res[imp[i]]<<" \n"[i==k];
        for (int i=1;i<=k;i++) res[imp[i]]=0,mind[imp[i]]=inf;
        si.clear();
    }
    return 0;
}