/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=5e3+10;
constexpr intl mod=998244353;
int n;
intl m;
vector <int> g[N];
int dis[N];
void dfs (int u,int fa,int dep,int &maxdep,int &maxi) {
    if (dep>maxdep) maxdep=dep,maxi=u;
    dis[u]=dep;
    for (int v:g[u]) {
        if (v==fa) continue;
        dfs(v,u,dep+1,maxdep,maxi);
    }
}
intl qpow (intl a,intl b) {
    intl res=1;
    while (b>0) {
        if (b&1) (res*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return res;
}
class DisjointSetUnion {
    int n;
    int fa[N];
    public:
    void Init (int _n) {
        n=_n;
        for (int i=1;i<=n;i++) fa[i]=i;
    }
    int find (int u) {
        if (u==fa[u]) return u;
        return fa[u]=find(fa[u]);
    }
    void merge (int u,int v) {
        u=find(u),v=find(v);
        fa[v]=u;
    }
}dsu;
intl rescnt[N];
signed main() {
    Cios;
    freopen("chengdu1.in","r",stdin);
    freopen("chengdu.out","w",stdout);
    cin>>n>>m;
    m++;
    for (int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int resdep=-1,resi=-1;
    dfs(1,0,0,resdep,resi);
    int resfar=-1;resdep=-1;
    dfs(resi,0,0,resdep,resfar);
    int d=resdep,r=d/2;
    dsu.Init(n);
    if (d%2==1) {
        int mid1=-1,mid2=-1;
        for (int i=1;i<=n;i++) {
            if (dis[i]==r) mid1=i;
            if (dis[i]==r+1) mid2=i;
            if (~mid1&&~mid2) break;
        }
        int _r1=-1,_r2=-1;
        int cnt1=0,cnt2=0;
        memset(dis,-1,sizeof dis);
        dfs(mid1,mid2,0,_r1,_r2);
        for (int i=1;i<=n;i++) {
            if (!~dis[i]) dsu.merge(mid2,i);
            if (dis[i]==r) cnt1++;
        }
        _r1=-1,_r2=-1;
        memset(dis,-1,sizeof dis);
        dfs(mid2,mid1,0,_r1,_r2);
        for (int i=1;i<=n;i++) {
            if (!~dis[i]) dsu.merge(mid1,i);
            if (dis[i]==r) cnt2++;
        }
        rescnt[mid1]=cnt1;
        rescnt[mid2]=cnt2;
    }
    else {
        int mid=-1;
        for (int i=1;i<=n;i++) {
            if (dis[i]==r) {
                mid=i;
                break;
            }
        }
        for (int v:g[mid]) {
            int _r1=-1,_r2=-1;
            memset(dis,-1,sizeof dis);
            dfs(mid,v,0,_r1,_r2);
            for (int i=1;i<=n;i++) {
            }
        }
    }
    return 0;
}

/*
g++ -g chengdu.cpp -o chengdu.exe -std=c++14 -O2 -static; echo "finish"; .\chengdu.exe; rm chengdu.exe
cd $work/ZhengRui/Competition/noip20/10 && g++ chengdu.cpp -o chengdu -std=c++14 -O2 && echo "finish" && ./chengdu && rm chengdu
*/

/*

*/