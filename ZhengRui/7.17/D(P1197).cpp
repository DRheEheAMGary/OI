/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=4e5+10;
int n,m;
int fa[N],sz[N];
bool dest[N];
vector<int> g[N];
int a[N];
void init () {
    for (int i=0;i<n;i++) {
        fa[i]=i;
        sz[i]=1;
    }
}
int find (int x) {
    if (x==fa[x]) return x;
    return fa[x]=find(fa[x]);
}
void merge (int u,int v) {
    u=find(u);
    v=find(v);
    if (u==v) return;
    if (sz[v]>sz[u]) swap(u,v);
    fa[v]=u;
    sz[u]+=sz[v];
}
signed main () {
    Cios;
    cin>>n>>m;
    init();
    for (int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int k;
    cin>>k;
    for (int i=0;i<k;i++) {
        cin>>a[i];
        dest[a[i]]=1;
    }
    int cur=0;
    for (int i=0;i<n;i++) {
        if (dest[i]) continue;
        for (int v:g[i]) {
            if (!dest[v]) merge(i,v);
        }
    }
    for (int i=0;i<n;i++) {
        if (!dest[i]&&find(i)==i) cur++;
    }
    vector<int> ans;
    ans.push_back(cur);
    for (int i=k-1;i>=0;i--) {
        int x=a[i];
        dest[x]=0;
        cur++;
        for (int v:g[x]) {
            if (!dest[v]) {
                if (find(x)!=find(v)) {
                    merge(x,v);
                    cur--;
                }
            }
        }
        ans.push_back(cur);
    }
    for (int i=k;i>=0;i--) cout<<ans[i]<<'\n';
    return 0;
}