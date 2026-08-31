/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=5e5+10,inf=0x3f3f3f3f;
int n,m,dfn[N],low[N],dfncnt=0;
int stk[N],top=0;
bool ins[N],onc[N];
bool visd[N],deld=0;
vector<int> g[N],res;
void tarjan(int u,int fa) {
    dfn[u]=low[u]=++dfncnt;
    stk[++top]=u;
    ins[u]=1;
    for (int v:g[u]) {
        if (v==fa) continue;
        if (!dfn[v]) {
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
        }
        else if (ins[v]) low[u] = min(low[u], dfn[v]);
    }
    if (low[u]==dfn[u]) {
        if (stk[top]!=u) { 
            while (top>0) {
                int x=stk[top--];
                ins[x]=0;
                onc[x]=1;
                if (x==u) break;
            }
        }
        else ins[u]=0,top--;
    }
}
void dfs(int u,int fa,int fbk) {
    int j=0;
    for (int i=0;i<g[u].size();i++) {
        int v=g[u][i];
        if (v==fa||visd[v]) continue;
        j=max(j,i+1);
        while (j<g[u].size()&&(g[u][j]==fa||visd[g[u][j]])) j++;
        int nxt=(j<g[u].size())?g[u][j]:fbk;
        if (!deld&&onc[u]&&onc[v]&&nxt==fbk&&v>fbk) {
            deld=1;
            continue;
        }
        visd[v]=1;
        res.push_back(v);
        dfs(v,u,nxt);
    }
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
    for (int i=1;i<=n;i++) sort(g[i].begin(),g[i].end());
    if (m==n) tarjan(1,0);
    visd[1]=1;
    res.push_back(1);
    dfs(1,0,inf);
    for (int i=0;i<n;i++) cout<<res[i]<<(i==n-1?"":" ");
    cout<<"\n";
    return 0;
}