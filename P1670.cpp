/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e4+10;
vector <int> g[N];
int n;
int res[N],siz[N];
void dfs (int u,int f) {
    res[u]=-1;
    siz[u]=1;
    for (int v:g[u]) {
        if (v==f) continue;
        dfs(v,u);
        siz[u]+=siz[v];
        res[u]=max(res[u],siz[v]);
    }
    res[u]=max(res[u],n-siz[u]);
}
signed main() {
    Cios;
    cin>>n;
    for (int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    int sum=0,mid=n/2;
    for (int i=1;i<=n;i++) {
        if (res[i]<=mid) sum++,cout<<i<<"\n";
    }
    if (sum==0) cout<<"NONE\n";
    return 0;
}