/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=205;
const intl inf=1ll<<60;
int n,amx,bmx;
// int c[N],u[N],v[N];
// bool chs[N];
// int dp[N][N][N];
// void dfs (int nowi,int rea,int reb,int suma,int sumb,int &maxval) {
//     if (nowi>n||(rea<=0&&reb<=0)) return maxval=max(maxval,suma+sumb),void();
//     for (int i=1;i<=n;i++) {
//         if (chs[i]) continue;
//         chs[i]=1;
//         dfs(nowi+1,rea-(rea>=c[i])*c[i],reb-(reb>=c[i])*c[i],suma+(rea>=c[i])*u[i],sumb+(reb>=c[i])*v[i],maxval);
//         chs[i]=0;
//     }
// }
struct item {
    int c;
    intl u,v;
}it[N];
intl dp[N][N][N];
signed main() {
    Cios;
    // freopen("greedy.in","r",stdin);
    // freopen("greedy.out","w",stdout);
    cin>>n>>amx>>bmx;
    for (int i=1;i<=n;i++) cin>>it[i].c>>it[i].u>>it[i].v;
    sort(it+1,it+1+n,[] (const item& p,const item& q) {return p.c>q.c;});
    int rmx=min(amx,bmx);
    for (int i=0;i<=rmx;i++) {
        for (int j=0;j<=amx;j++) {
            for (int k=0;k<=bmx;k++) dp[i][j][k]=-inf;
        }
    }
    for (int i=0;i<=rmx;i++) dp[i][amx-i][bmx-i]=0;
    for (int i=1;i<=n;i++) {
        auto [c,u,v]=it[i];
        for (int r=0;r<=rmx;r++) {
            for (int a=0;a+r<=amx;a++) {
                for (int b=0;b+r<=bmx;b++) {
                    intl val=dp[r][a][b];
                    if (val==-inf) continue;
                    if (c<=r) dp[r-c][a][b]=max(dp[r-c][a][b],val+u+v);
                    if (c<=a&&c>b) dp[r][a-c][b]=max(dp[r][a-c][b],val+u);
                    if (c<=b&&c>a) dp[r][a][b-c]=max(dp[r][a][b-c],val+v);
                }
            }
        }
    }
    intl res=-1;
    for (int i=0;i<=amx;i++) {
        for (int j=0;j<=bmx;j++) res=max(res,dp[0][i][j]);
    }
    cout<<res<<"\n";
    return 0;
}

/*
g++ -g greedy.cpp -o greedy.exe -std=c++14 -O2 -static; echo "finish"; .\greedy.exe
g++  greedy.cpp -o greedy -std=c++14 -O2 && echo "finish" && ./greedy
*/