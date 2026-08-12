/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define szof sizeof
intc N=1e5+10;
int n,m,mod;
vector <int> g[N],ng[N];
int dfncnt,scccnt,dfn[N],low[N],scc[N],sz[N];
int in[N],f[N],f2[N];
stack <int> st;
struct edge {
    int u,v;
    bool operator < (const edge &p) const {
        if (u!=p.u) return u<p.u;
        return v<p.v;
    }
    bool operator == (const edge &p) const {return u==p.u&&v==p.v;}
};
void Tarjan (int u) {
    dfn[u]=low[u]=++dfncnt;
    st.push(u);
    for (int v:g[u]) {
        if (!dfn[v]) {
            Tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if (!scc[v]) low[u]=min(low[u],dfn[v]);
    }
    if (dfn[u]==low[u]) {
        scccnt++;
        while (1) {
            int v=st.top();
            st.pop();
            scc[v]=scccnt;
            sz[scccnt]++;
            if (v==u) break;
        }
    }
}
signed main() {
    Cios;
    cin>>n>>m>>mod;
    for (int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
    }
    for (int i=1;i<=n;i++) {
        if (!dfn[i]) Tarjan(i);
    }
    vector <edge> es;
    for (int u=1;u<=n;u++) {
        for (int v:g[u]) {
            if (scc[u]!=scc[v]) es.push_back({scc[u],scc[v]});
        }
    }
    sort(es.begin(),es.end());
    es.erase(unique(es.begin(),es.end()),es.end());
    for (auto [u,v]:es) {
        ng[u].push_back(v);
        in[v]++;
    }
    queue<int> q;
    for (int i=1;i<=scccnt;i++) {
        f[i]=sz[i];
        f2[i]=1%mod;
        if (in[i]==0) q.push(i);
    }
    while (q.size()) {
        int u=q.front();
        q.pop();
        for (int v:ng[u]) {
            if (f[u]+sz[v]>f[v]) {
                f[v]=f[u]+sz[v];
                f2[v]=f2[u];
            }
            else if (f[u]+sz[v]==f[v]) f2[v]=(f2[v]+f2[u])%mod;
            in[v]--;
            if (in[v]==0) q.push(v);
        }
    }
    int maxk=0,res=0;
    for (int i=1;i<=scccnt;i++) maxk=max(maxk,f[i]);
    for (int i=1;i<=scccnt;i++) {
        if (f[i]==maxk) res=(res+f2[i])%mod;
    }
    cout<<maxk<<"\n"<<res<<"\n";
    return 0;
}