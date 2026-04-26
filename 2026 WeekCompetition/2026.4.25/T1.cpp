/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define double long double
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e5+10;
int n,m,s;
struct edge {
    int to;
    int w;
    double coe;
    int sumw;
    edge (int to_,int w_,double coe_):to(to_),w(w_),coe(coe_) {
        int tmpw=w;
        sumw=0;
        while (tmpw) {
            sumw+=tmpw;
            tmpw=tmpw*10*coe/10;
        }
    }
};
struct nwedge {
    int to;
    int w;
    nwedge (int to_,int w_):to(to_),w(w_) {}
};
vector <edge> g[N];
vector <nwedge> ng[N];
int dfn[N],low[N],bel[N],dfncnt=0,cnt=0;
int nsump[N];
stack <int> st;
void Tarjan (int u) {
    low[u]=dfn[u]=++dfncnt;
    st.push(u);
    for (auto [v,w,coe,sumw]:g[u]) {
        if (!dfn[v]) {
            Tarjan(v);
            low[u]=min(low[v],low[u]);
        }
        else if (!bel[v]) low[u]=min(low[v],low[u]);
    }
    if (low[u]==dfn[u]) {
        cnt++;
        while (1) {
            int v=st.top();
            st.pop();
            bel[v]=cnt;
            if (v==u) break;
        }
    }
}
void dfs (int u,int nwres,int &res) {
    nwres+=nsump[u];
    res=max(res,nwres);
    for (auto [v,w]:ng[u]) dfs(v,nwres+w,res);
}
signed main() {
    Cios;
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
        int u,v,w;
        double k;
        cin>>u>>v>>w>>k;
        g[u].push_back(edge(v,w,k));
    }
    cin>>s;
    for (int i=1;i<=n;i++) {
        if (!dfn[i]) Tarjan(i);
    }
    for (int u=1;u<=n;u++) {
        for (edge e:g[u]) {
            int v=e.to;
            if (bel[u]!=bel[v]) ng[bel[u]].push_back(nwedge(bel[v],e.w));
            else nsump[bel[u]]+=e.sumw;
        }
    }
    int res=0;
    dfs(bel[s],0,res);
    cout<<res<<"\n";
    return 0;
}