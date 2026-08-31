/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e5+10;
int n,m;
vector <int> g[N];
int deg[N];
int s=-1,t=-1;
int cur[N];
inline void noans() {cout<<"No\n";exit(0);}
stack<int> stk;
void dfs (int u) {
    for (int i=cur[u];i<g[u].size();i=cur[u]) {
        cur[u]=i+1;
        dfs(g[u][i]);
    }
    stk.push(u);
}
signed main() {
    Cios;
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        deg[u]++;
        deg[v]--;
    }
    for (int i=1;i<=n;i++) {
        sort(g[i].begin(),g[i].end());
        if (deg[i]==1) {
            if (~s) noans();
            s=i;
        }
        else if (deg[i]==-1) {
            if (~t) noans();
            t=i;
        }
        else if (deg[i]!=0) noans();
    }
    if (~s&&~t);
    else if (!(~s||~t)) s=1,t=1;
    else noans();
    dfs(s);
    while (stk.size()) cout<<stk.top()<<" ",stk.pop();
    return 0;
}