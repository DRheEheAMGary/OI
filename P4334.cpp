/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e5+10,M=5e5+10;
int n,e;
vector <int> g[N],ng[N+M];
int cnt,dfncnt=0,dfn[N],low[N];
stack <int> st;
map <pair<int,int>,int> mp;
void Tarjan (int u,int fa) {
    low[u]=dfn[u]=++dfncnt;
    st.push(u);
    for (int v:g[u]) {
        if (v==fa) continue;
        if (!dfn[v]) {
            Tarjan (v,u);
            low[u]=min(low[u],low[v]);
            if (low[v]>=dfn[u]) {
                cnt++;
                if (low[v]>dfn[u]) mp[{min(u,v),max(u,v)}]=cnt;
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
int siz[N+M],fa[N+M],hv[N+M],top[N+M],dep[N+M];
void dfs1 (int u) {
    siz[u]=1;
    dep[u]=dep[fa[u]]+1;
    for (int v:ng[u]) {
        if (v==fa[u]) continue;
        fa[v]=u;
        dfs1(v);
        siz[u]+=siz[v];
        if (siz[v]>siz[hv[u]]) hv[u]=v;
    }
}
void dfs2 (int u,int rt) {
    top[u]=rt;
    if (hv[u]) dfs2(hv[u],rt);
    for (int v:ng[u]) {
        if (v==fa[u]||v==hv[u]) continue;
        dfs2(v,v);
    }
}
int lca (int u,int v) {
    while (top[u]!=top[v]) {
        if (dep[top[u]]<dep[top[v]]) swap(u,v);
        u=fa[top[u]];
    }
    return dep[u]>dep[v]?v:u;
}
signed main() {
    Cios;
    cin>>n>>e;
    for (int i=1;i<=e;i++) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cnt=n;
    Tarjan(1,0);
    dfs1(1);
    dfs2(1,1);
    int q;
    cin>>q;
    while (q--) {
        int op,a,b,g1,g2,c;
        cin>>op>>a>>b;
        if (op==1) {
            cin>>g1>>g2;
            c=mp[{min(g1,g2),max(g1,g2)}];
            if (c==0) {
                cout<<"yes\n";
                continue;
            }
        }
        else cin>>c;
        int lca_ab=lca(a,b),lca_ac=lca(a,c),lca_bc=lca(b,c);
        if (lca_ab==c) cout<<"no\n";
        else if ((lca_ac==c&&lca_bc!=c)||(lca_bc==c&&lca_ac!=c)) cout<<"no\n";
        else cout<<"yes\n";
    }
    return 0;
}