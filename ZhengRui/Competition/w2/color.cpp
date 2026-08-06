/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define szof sizeof
intc N=1e6+10;
vector <int> g[N];
int n,m,a[N],vis[N];
int dfs (int u,int fa) {
    if (vis[u]) return 0;
    vis[u]=1;
    int res=a[u];
    for (int v:g[u]) {
        if (v==fa) continue;
        res=min(res,dfs(v,u));
    }
    return res;
}
signed main() {
    // freopen ("test/color/ex_color5.in","r",stdin);
    // freopen ("ans.out","w",stdout);
    Cios;
    int res=0;
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i=1;i<=n;i++) {
        if (!vis[i]) res+=dfs(i,0);
    }
    cout<<res<<"\n";
    return 0;
}

/*
clang++ -g color.cpp -o color -std=c++14 -O2 -Wall
*/