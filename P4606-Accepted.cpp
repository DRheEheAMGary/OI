/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=5e5+10;
int n,m,sl;
int s[N];
vector <int> g[N],tr[N];
int dfn[N],low[N],dfncnt=0;
int cnt;
stack <int> st;
void Tarjan (int u) {
    dfn[u]=low[u]=++dfncnt;
    st.push(u);
    for (int v:g[u]) {
        if (!dfn[v]) {
            Tarjan(v);
            low[u]=min(low[u],low[v]);
            if (low[v]>=dfn[u]) {
                cnt++;
                int y;
                do {
                    y=st.top();
                    st.pop();
                    tr[cnt].push_back(y);
                    tr[y].push_back(cnt);
                } while (y!=v);
                tr[cnt].push_back(u);
                tr[u].push_back(cnt);
            }
        }
        else low[u]=min(low[u],dfn[v]);
    }
}
int dis[N];
int dfntr[N],dfntrcnt=0;
int fa[N][25],dep[N];
void dfstree (int u,int f) {
    dfntr[u]=++dfntrcnt;
    fa[u][0]=f;
    dep[u]=dep[f]+1;
    dis[u]=dis[f]+(u<=n);
    for (int i=1;i<=20;i++) fa[u][i]=fa[fa[u][i-1]][i-1];
    for (int v:tr[u]) {
        if (v==f) continue;
        dfstree(v,u);
    }
}
int lca (int u,int v) {
    if (dep[u]>dep[v]) swap(u,v);
    for (int i=20;i>=0;i--) {
        if (dep[fa[v][i]]>=dep[u]) v=fa[v][i];
    }
    if (u==v) return u;
    for (int i=20;i>=0;i--) {
        if (fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
    }
    return fa[u][0];
}
int getdis (int u,int v) {
    return dis[u]+dis[v]-2*dis[lca(u,v)];
}
signed main() {
    Cios;
    int T;
    cin>>T;
    while (T--) {
        cin>>n>>m;
        for (int i=1;i<=n*2;i++) {
            g[i].clear();
            tr[i].clear();
            dfn[i]=low[i]=dfntr[i]=0;
        }
        dfncnt=dfntrcnt=0;
        while (st.size()) st.pop();
        cnt=n;
        for (int i=1;i<=m;i++) {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        Tarjan(1);
        dfstree(1,0);
        int q;
        cin>>q;
        while (q--) {
            cin>>sl;
            for (int i=1;i<=sl;i++) cin>>s[i];
            sort (s+1,s+1+sl,[&] (int a,int b) {return dfntr[a]<dfntr[b];});
            int res=0;
            for (int i=1;i<sl;i++) res+=getdis(s[i],s[i+1]);
            res+=getdis(s[sl],s[1]);
            int tlca=lca(s[1],s[sl]);
            if (tlca<=n) res+=2;
            cout<<res/2-sl<<"\n";
        }
    }
    return 0;
}