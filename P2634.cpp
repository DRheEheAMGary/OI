/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e4+10;
struct edge {
    int to,w;
};
int n,rt,rs,res,minn;
int vis[N],cnt[4],sum[4],siz[N];
vector <edge> g[N];
int gcd (int a,int b) {return b?gcd(b,a%b):a;}
void getroot (int u,int f) {
    siz[u]=1;
    int tmp=0;
    for (edge e:g[u]) {
        int v=e.to;
        if (v==f||vis[v]) continue;
        getroot(v,u);
        siz[u]+=siz[v];
        tmp=max(tmp,siz[v]);
    }
    tmp=max(tmp,rs-siz[u]);
    if (tmp<minn) minn=tmp,rt=u;
}
void dfsres (int u,int f,int w) {
    cnt[w%3]++;
    for (edge e:g[u]) {
        int v=e.to,w_=e.w;
        if (vis[v]||v==f) continue;
        dfsres(v,u,w+w_);
    }
}
int getres (int u) {
    int tmp=1;
    sum[0]=sum[1]=sum[2]=0;
    for (edge e:g[u]) {
        int v=e.to,w=e.w;
        if (vis[v]) continue;
        cnt[0]=cnt[1]=cnt[2]=0;
        dfsres(v,u,w);
        tmp+=sum[0]*cnt[0];
        tmp+=sum[1]*cnt[2];
        tmp+=sum[2]*cnt[1];
        tmp+=cnt[0];
        sum[0]+=cnt[0];
        sum[1]+=cnt[1];
        sum[2]+=cnt[2];
    }
    return tmp;
}
void solve (int u) {
    vis[u]=1;
    res+=getres(u);
    for (edge e:g[u]) {
        int v=e.to;
        if (vis[v]) continue;
         rs=siz[v];
         minn=(1<<30);
         getroot(v,u);
         solve(rt);
    }
}
signed main() {
    Cios;
    cin>>n;
    for (int i=1;i<n;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    rs=n;
    minn=(1<<30);
    getroot(1,0);
    solve(rt);
    int a=res*2-n,b=n*n;
    int g=gcd(a,b);
    a/=g,b/=g;
    cout<<a<<"/"<<b<<"\n";
    return 0;
}