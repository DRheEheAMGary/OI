/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=5e5+10;
int n,q;
int fa[N],v[N],sz[N],col[N],l[N],r[N];
void init () {
    for (int i=1;i<=n;i++) {
        fa[i]=i;
        col[i]=i;
        v[i]=1;
        sz[i]=1;
        l[i]=r[i]=i;
    }
}
int find (int x) {
    if (x==fa[x]) return x;
    return fa[x]=find(fa[x]);
}
void merge (int u,int v) {
    u=find(u);
    v=find(v);
    if (sz[u]>sz[v]) fa[v]=u,sz[u]+=sz[v],l[u]=min(l[u],l[v]),r[u]=max(r[u],r[v]);
    else fa[u]=v,sz[v]+=sz[u],l[v]=min(l[u],l[v]),r[v]=max(r[u],r[v]);
}
signed main() {
    Cios;
    cin>>n>>q;
    init();
    while (q--) {
        int op;
        cin>>op;
        if (op==1) {
            int x,c;
            cin>>x>>c;
            x=find(x);
            v[col[x]]-=sz[x];
            col[x]=c;
            v[col[x]]+=sz[x];
            if (col[find(l[x]-1)]==c) merge(l[x]-1,x);
            if (col[find(r[x]+1)]==c) merge(r[x]+1,x);
        }
        else {
            int c;
            cin>>c;
            cout<<v[c]<<"\n";
        }
    }
    return 0;
}