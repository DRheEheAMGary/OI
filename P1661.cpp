/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int n;
struct node {
    int x,y;
}p[55];
int dis (node a,node b) {return abs(a.x-b.x)+abs(a.y-b.y);}
int fa[55],sz[55];
int find (int x) {
    if (fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
void merge (int x,int y) {
    x=find(x);
    y=find(y);
    if (x==y) return;
    if (sz[x]>sz[y]) swap(x,y);
    fa[x]=y;
    sz[y]+=sz[x];
}
bool check (int time) {
    for (int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
    for (int a=1;a<=n;a++) {
        for (int b=a+1;b<=n;b++) {
            int di=dis(p[a],p[b]);
            if (di<=2*time) merge(a,b);
        }
    }
    return sz[find(1)]==n;
}
signed main() {
    Cios;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i].x>>p[i].y;
    int l=0,r=1e9+10,res=-1;
    while (l<=r) {
        int mid=(l+r)>>1;
        if (check(mid)) r=mid-1,res=mid;
        else l=mid+1;
    }
    cout<<res<<"\n";
    return 0;
}