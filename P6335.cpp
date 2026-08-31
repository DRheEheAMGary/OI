/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e5+10;
int n,m;
vector <int> g[N];
int dfn[N],low[N],fa[N];
bool iscyc[N];
int dfncnt;
struct Cycle {
    vector <int> ver;
    int len,subf;
};
vector <Cycle> cyc[N];
vector <int> brch[N];
int dp1[N],dp2[N];
vector <int> post;
void dfs (int u,int p) {
    dfn[u]=low[u]=++dfncnt;
    fa[u]=p;
    for (int v:g[u]) {
        if (v==p) continue;
        if (!dfn[v]) {
            dfs(v,u);
            low[u]=min(low[u],low[v]);
        }
        else if (dfn[v]<dfn[u]) {
            low[u]=min(low[u],dfn[v]);
            Cycle c;
            int cur=u;
            while (cur!=v) {
                c.ver.push_back(cur);
                iscyc[cur]=1;
                cur=fa[cur];
            }
            c.ver.push_back(v);
            reverse(c.ver.begin(),c.ver.end());
            c.len=c.ver.size();
            c.subf=0;
            cyc[v].push_back(c);
        }
    }
    post.push_back(u);
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
    dfs(1,0);
    for (int i=2;i<=n;i++) {
        if (!iscyc[i]&&fa[i]) brch[fa[i]].push_back(i);
    }
    for (int u:post) {
        int sumf=0;
        for (auto &c:cyc[u]) {
            int curf=c.len;
            for (int v:c.ver) {
                if (v!=u) curf+=dp1[v];
            }
            c.subf=curf;
            sumf+=curf;
        }
        dp1[u]=sumf;
        dp2[u]=dp1[u];
        for (int v:brch[u]) dp2[u]=max(dp2[u],dp1[u]+1+dp2[v]);
        for (auto &c:cyc[u]) {
            int base=dp1[u]-c.subf;
            int k=c.len;
            int mxcw=0,curs=0;
            for (int i=1;i<k;i++) {
                int v=c.ver[i];
                mxcw=max(mxcw,i+curs+dp2[v]);
                curs+=dp1[v];
            }
            int mxccw=0;
            curs=0;
            for (int i=k-1;i>=1;i--) {
                int v=c.ver[i];
                mxccw=max(mxccw,(k-i)+curs+dp2[v]);
                curs+=dp1[v];
            }
            dp2[u]=max(dp2[u],base+max(mxcw,mxccw));
        }
    }
    cout<<dp2[1]<<"\n";
    return 0;
}