/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e6+10;
int n,m;
vector <int> g[N];
int low[N],dfn[N],dfncnt=0,cnt=0,bel[N];
stack<int> s;
void Tarjan (int u) {
    dfn[u]=low[u]=++dfncnt;
    s.push(u);
    for (int v:g[u]) {
        if (!dfn[v]) {
            Tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if (!bel[v]) low[u]=min(low[u],low[v]);
    }
    if (dfn[u]==low[u]) {
        cnt++;
        while (1) {
            int v=s.top();
            s.pop();
            bel[v]=cnt;
            if (v==u) break;
        }
    }
}
signed main() {
    Cios;
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
        int x,a,y,b;
        cin>>x>>a>>y>>b;
        g[x+!a*n].push_back(y+b*n);
        g[y+!b*n].push_back(x+a*n);
    }
    for (int i=1;i<=2*n;i++) {
        if (!dfn[i]) Tarjan(i);
    }
    for (int i=1;i<=n;i++) {
        if (bel[i]==bel[i+n]) {
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
    }
    cout<<"POSSIBLE\n";
    for (int i=1;i<=n;i++) {
        if (bel[i]<bel[i+n]) cout<<"0 ";
        else cout<<"1 ";
    }
    return 0;
}