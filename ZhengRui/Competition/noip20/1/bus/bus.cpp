/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int 
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e6+10;
#ifdef CLANGD_
#define N 10
#endif
int n,m,k;
vector <int> g[N];
bool vis[N];
void dfs (int u,int fa,int& sz,bool& cir) {
    sz++;
    vis[u]=1;
    for (int v:g[u]) {
        if (v==fa) continue;
        if (vis[v]) return cir=1,void();
        dfs(v,u,sz,cir);
    }
}
signed main() {
    Cios;
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for (int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int res=0,mind=0;
    for (int i=1;i<=n;i++) {
        if (vis[i]) continue;
        int sz=0;
        bool cir=0;
        dfs(i,0,sz,cir);
        res+=sz/k*k;
        if (sz>=k) mind+=(sz+k-1)/k-!cir;
    }
    cout<<res<<" "<<mind<<"\n";
    return 0;
}

/*
g++ -g bus.cpp -o bus -std=c++14 -O2; echo "finish"; ./bus
*/