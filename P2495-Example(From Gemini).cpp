/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=5e5+10;
const int INF = 1e15;

struct edge {
    int v,w;
};
vector <edge> g[N];
vector <int> ng[N]; // 虚树邻接表
int n,m,k;
int dep[N],sz[N],hv[N],dfn[N],top[N],fa[N],minw[N];
int dfncnt=0;
int imp[N], is_imp[N];

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
Stack <int> s;

void dfs1 (int u) {
    dep[u]=dep[fa[u]]+1;
    sz[u]=1;
    for (edge v:g[u]) {
        if (v.v==fa[u]) continue;
        fa[v.v]=u;
        minw[v.v]=min(minw[u], v.w); // 维护根到 u 路径上的最小边权
        dfs1(v.v);
        sz[u]+=sz[v.v];
        if (sz[v.v]>sz[hv[u]]) hv[u]=v.v;
    }
}

void dfs2 (int u,int tp) {
    dfn[u]=++dfncnt;
    top[u]=tp;
    if (hv[u]) dfs2(hv[u],tp);
    for (edge v:g[u]) {
        if (v.v==fa[u]||v.v==hv[u]) continue;
        dfs2(v.v,v.v);
    }
}

int lca (int u,int v) {
    while (top[u]!=top[v]) {
        if (dep[top[u]] < dep[top[v]]) swap(u,v);
        u=fa[top[u]];
    }
    return (dep[u]<dep[v])?u:v;
}

// 虚树加边
void add_edge(int u, int v) {
    ng[u].push_back(v);
}

// 虚树 DP
int solve(int u) {
    if (is_imp[u]) return minw[u];
    int sum = 0;
    for (int v : ng[u]) {
        sum += solve(v);
    }
    ng[u].clear(); // 用完后直接清空，避免 memset 带来的 O(N) 开销
    return min(minw[u], sum);
}

void build () {
    sort (imp+1,imp+1+k,[&] (int a,int b) {return dfn[a]<dfn[b];});
    s.clear();
    s.push(1);
    ng[1].clear();
    for (int i = 1; i <= k; i++) {
        int u = imp[i];
        if (u == 1) continue;
        int lc = lca(u, s.top());
        if (lc != s.top()) {
            while (dfn[lc] < dfn[s.ptop()]) {
                add_edge(s.ptop(), s.top());
                s.pop();
            }
            if (dfn[lc] > dfn[s.ptop()]) {
                ng[lc].clear();
                add_edge(lc, s.top());
                s.pop();
                s.push(lc);
            } else {
                add_edge(lc, s.top());
                s.pop();
            }
        }
        ng[u].clear();
        s.push(u);
    }
    while (s.size() > 1) {
        add_edge(s.ptop(), s.top());
        s.pop();
    }
}

signed main() {
    Cios;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    minw[1] = INF;
    dfs1(1);
    dfs2(1, 1);

    cin >> m;
    while (m--) {
        cin >> k;
        for (int i = 1; i <= k; i++) {
            cin >> imp[i];
            is_imp[imp[i]] = 1;
        }
        build();
        cout << solve(1) << "\n";
        for (int i = 1; i <= k; i++) is_imp[imp[i]] = 0; // 重置标记
    }
    return 0;
}