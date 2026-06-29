/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e5+10,M=2e5+10;
int n,m;
vector <int> g[N],ng[N+M],nwc;
stack <int> st;
int cnt,dfncnt=0,dfn[N],low[N];
intl res,sz[N+M],wei[N+M];
void Tarjan (int u,int fa) {
    st.push(u);
    dfn[u]=low[u]=++dfncnt;
    for (int v:g[u]) {
        if (v==fa) continue;
        if (!dfn[v]) {
            Tarjan (v,u);
            low[u]=min(low[u],low[v]);
            if (low[v]>=dfn[u]) {
                cnt++;
                while (1) {
                    int sv=st.top();
                    st.pop();
                    ng[sv].push_back(cnt);
                    ng[cnt].push_back(sv);
                    if (sv==v) break;
                }
                ng[u].push_back(cnt);
                ng[cnt].push_back(u);
            }
        }
        else low[u]=min(low[u],dfn[v]);
    }
}
void dfs1 (int u,int fa) {
    nwc.push_back(u);
    for (int v:ng[u]) {
        if (v==fa) continue;
        dfs1(v,u);
    }
}
void dfs2 (int u,int fa,intl tot) {
    sz[u]=(u<=n);
    for (int v:ng[u]) {
        if (v==fa) continue;
        dfs2(v,u,tot);
        sz[u]+=sz[v];
    }
    intl pr=0;
    if (u<=n) {
        intl sum=0;
        for (int v:ng[u]) {
            if (v==fa) continue;
            sum+=(intl)sz[v]*(sz[v]-1);
        }
        sum+=(tot-sz[u])*(tot-sz[u]-1);
        pr+=tot*(tot-1)-sum;
    }
    else {
        intl sum=0;
        for (int v:ng[u]) {
            if (v==fa) continue;
            sum+=sz[v]*sz[v];
        }
        sum+=(tot-sz[u])*(tot-sz[u]);
        pr+=tot*tot-sum;
    }
    res+=pr*wei[u];
}
signed main() {
    Cios;
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cnt=n;
    for (int i=1;i<=n;i++) wei[i]=-1;
    for (int i=1;i<=n;i++) {
        if (!dfn[i]) {
            Tarjan (i,0);
            nwc.clear();
            st.pop();
            dfs1(i,0);
            intl tot=0;
            for (int u:nwc) {
                if (u<=n) tot++;
                else wei[u]=ng[u].size();
            }
            dfs2(i,0,tot);
        }
    }
    cout<<res<<"\n";
    return 0;
}