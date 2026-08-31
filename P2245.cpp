/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e5+10,M=3e5+10;
int n,m,q;
struct Edge {
    int u,v,w;
    bool operator < (const Edge p) const {return w<p.w;}
}e[M];
int cnt,w[N+M];
vector <int> g[N+M];
int bel[N],belp[N];
int find (int x) {
    if (x==bel[x]) return x;
    return bel[x]=find(bel[x]);
}
bool merge (int x,int y) {
    int fx=find(x),fy=find(y);
    if (fx==fy) return 0;
    bel[fy]=x;
    return 1;
}
int pcnt;
void Kruskal () {
    sort(e+1,e+1+m);
    for (int i=1;i<=n;i++) belp[i]=i;
    for (auto [u,v,wi]:e) {
        int fu=find(u);
        int fv=find(v);
        bool suc=merge(u,v);
        if (suc) {
            pcnt++;
            w[pcnt]=wi;
            g[belp[fu]].push_back(pcnt);
            g[belp[fv]].push_back(pcnt);
            g[pcnt].push_back(belp[fu]);
            g[pcnt].push_back(belp[fv]);
            belp[fu]=belp[fv]=pcnt;
        }
    }
}
int fa[N+M][25],dep[N+M];
void dfs (int u) {
    dep[u]=dep[fa[u][0]]+1;
    for (int i=1;i<25;i++) fa[u][i]=fa[fa[u][i-1]][i-1];
    for (int v:g[u]) {
        if (v==fa[u][0]) continue;
        fa[v][0]=u;
        dfs(v);
    }
}
int lca (int u,int v) {
    if (dep[u]<dep[v]) swap(u,v);
    for (int i=24;i>=0;i--) {
        if (dep[fa[u][i]]>=dep[v]) u=fa[u][i];
    }
    if (u==v) return u;
    for (int i=24;i>=0;i--) {
        if (fa[u][i]!=fa[v][i]) {
            u=fa[u][i];
            v=fa[v][i];
        }
    }
    return fa[u][0];
}
signed main() {
    Cios;
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        if (u==v) continue;
        e[i]={u,v,w};
    }
    for (int i=1;i<=n;i++) bel[i]=i;
    pcnt=n;
    Kruskal();
    for (int i=pcnt;i>=0;i--) {
        if (dep[i]==0) dfs(i);
    }
    cin>>q;
    while (q--) {
        int u,v;
        cin>>u>>v;
        if (find(u)!=find(v)) cout<<"impossible\n";
        else cout<<w[lca(u,v)]<<"\n";
    }
    return 0;
} 