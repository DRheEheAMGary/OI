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
int n,m,p,q,fa[N],col[N];
int find (int u) {
    if (fa[u]==u) return u;
    return fa[u]=find(fa[u]);
}
signed main() {
    Cios;
    cin>>n>>m>>p>>q;
    for (int i=1;i<=n;i++) fa[i]=i;
    for (int i=m;i>=1;i--) {
        int l=(i*p+q)%n+1,r=(i*q+p)%n+1;
        if (l>r) swap(l,r);
        for (int j=r;j>=l;) {
            if (j==find(j)) col[j]=i,fa[j]=find(j-1);
            j=fa[j];
        }
    }
    for (int i=1;i<=n;i++) cout<<col[i]<<"\n";
    return 0;
}