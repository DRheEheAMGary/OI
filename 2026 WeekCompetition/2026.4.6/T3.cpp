/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e4+10,M=5e4+10;
int n,m;
vector<pair<int,int>> g[N];
int dfn[N],low[N],dfncnt;
bool imp[M];
int col[N];
vector<int> ng[N];
int fa[N][30],dep[N];
bool vis[N];
void Tarjan(int u,int fid) {
    dfn[u]=low[u]=++dfncnt;
    for (auto [v,id]:g[u]) {
        if (id==fid) continue;
        if (!dfn[v]) {
            Tarjan(v,id);
            low[u]=min(low[u],low[v]);
            if (low[v]>dfn[u]) imp[id]=1;
        }
        else low[u]=min(low[u],dfn[v]);
    }
}
void dfs(int u,int cid) {
    col[u]=cid;
    for (auto [v,id]:g[u]) {
        if (col[v]||imp[id]) continue;
        dfs(v,cid);
    }
}
void dfslca(int u,int f) {
    vis[u]=1;
    fa[u][0]=f;
    for (int k=1;k<20;k++) fa[u][k]=fa[fa[u][k-1]][k-1];
    for (int v:ng[u]) {
        if (v==f) continue;
        dep[v]=dep[u]+1;
        dfslca(v,u);
    }
}
int lca(int u,int v) {
    if (dep[u]<dep[v]) swap(u,v);
    for (int k=20;k>=0;k--) {
        if (dep[fa[u][k]]>=dep[v]) u=fa[u][k];
    }
    if (u==v) return u;
    for (int k=20;k>=0;k--) {
        if (fa[u][k]!=fa[v][k]) u=fa[u][k],v=fa[v][k];
    }
    return fa[u][0];
}
string toBinary(int x) {
    if (x==0) return "0";
    string s;
    while (x>0) {
        s.push_back((x&1)?'1':'0');
        x>>=1;
    }
    reverse(s.begin(),s.end());
    return s;
}
signed main() {
    Cios;
    cin>>n>>m;
    vector <pair<int,int>> edges;
    for (int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        int u_=min(u,v),v_=max(u,v);
        edges.push_back({u_,v_});
    }
    sort (edges.begin(),edges.end());
    edges.erase(unique(edges.begin(),edges.end()),edges.end());
    int idx=0;
    for (auto [u,v]:edges) {
        idx++;
        g[u].push_back({v,idx});
        g[v].push_back({u,idx});
        imp[idx]=0;
        
    }
    dfncnt=0;
    for (int i=1;i<=n;i++) {
        if (!dfn[i]) Tarjan(i, -1);
    }
    int ccnt=0;
    for (int i=1;i<=n;i++) {
        if (!col[i]) {
            ++ccnt;
            dfs(i, ccnt);
        }
    }
    for (int i=1;i<=ccnt;i++) ng[i].clear();
    for (int u=1;u<=n;u++) {
        for (auto [v,eid]:g[u]) {
            if (u<v&&imp[eid]) {
                int cu=col[u];
                int cv=col[v];
                if (cu!=cv) {
                    ng[cu].push_back(cv);
                    ng[cv].push_back(cu);
                }
            }
        }
    }
    for (int i=1;i<=ccnt;i++) {
        if (!vis[i]) {
            dep[i]=0;
            dfslca(i,-1);
        }
    }
    int tot;
    cin>>tot;
    while (tot--) {
        int a,b;
        cin>>a>>b;
        int ca=col[a];
        int cb=col[b];
        if (ca==cb) cout<<"1\n";
        else {
            int lc=lca(ca, cb);
            int dist=dep[ca]+dep[cb]-2*dep[lc]+1;
            cout<<toBinary(dist)<<"\n";
        }
    }
    return 0;
}
