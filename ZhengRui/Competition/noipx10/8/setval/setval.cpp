/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2005,K_MAX=1425,M_SQRT=715,mod=1e9+7;
constexpr intl inf=1ll<<60;
struct block {
    int len,id;
};
int n,m,sq,tot,p[N];
int val[K_MAX],id1[M_SQRT],id2[M_SQRT];
block blk[105000];
int head[K_MAX],sz[K_MAX],blk_cnt;
int dp[N][K_MAX];
intl cur_s[K_MAX];
inline int get_id (int x) {
    return x<=sq?id1[x]:id2[m/x];
}
void calc_s (int u) {
    for (int i=1;i<=tot;i++) {
        intl s=0;
        int ed=head[i]+sz[i];
        for (int j=head[i];j<ed;j++) s+=1ll*blk[j].len*dp[u][blk[j].id];
        cur_s[i]=s%mod;
    }
}
signed main () {
    freopen("setval.in","r",stdin);
    freopen("setval.out","w",stdout);
    Cios;
    cin>>n>>m;
    for (int i=2;i<=n;i++) cin>>p[i];
    sq=sqrt(m);
    for (int l=1,r;l<=m;l=r+1) {
        int v=m/l;
        r=m/v;
        val[++tot]=v;
        if (v<=sq) id1[v]=tot;
        else id2[m/v]=tot;
    }
    reverse(val+1,val+tot+1);
    for (int i=1;i<=tot;i++) {
        if (val[i]<=sq) id1[val[i]]=i;
        else id2[m/val[i]]=i;
    }
    for (int i=1;i<=tot;i++) {
        int t=val[i];
        head[i]=blk_cnt;
        for (int l=1,r;l<=t;l=r+1) {
            int v=t/l;
            r=t/v;
            blk[blk_cnt++]={r-l+1,get_id(v)};
        }
        sz[i]=blk_cnt-head[i];
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=tot;j++) dp[i][j]=1;
    }
    for (int u=n;u>=2;u--) {
        calc_s(u);
        for (int i=1;i<=tot;i++) dp[p[u]][i]=1ll*dp[p[u]][i]*cur_s[i]%mod;
    }
    calc_s(1);
    cout<<cur_s[tot]<<"\n";
    return 0;
}

/*
g++ -g setval.cpp -o setval.exe -std=c++14 -O2 -static; echo "finish"; .\setval.exe; rm setval.exe
cd $work/ZhengRui/Competition/noipx10/8/setval && g++ setval.cpp -o setval -std=c++14 -O2 && echo "finish" && ./setval && rm setval
*/