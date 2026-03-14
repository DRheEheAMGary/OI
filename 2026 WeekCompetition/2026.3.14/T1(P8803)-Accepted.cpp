/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
const int month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
intc N=1005,M=5005;
int n,m,k;
struct node {
    int d,v;
    bool operator < (const node& p) const {
        return d<p.d;
    }
}a[N];
int dp[N][M],pre[N];
signed main(){
    Cios;
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++) {
        int _m,d,v;
        cin>>_m>>d>>v;
        for (int j=1;j<_m;j++) d+=month[j];
        a[i]={d,v};
    }
    sort (a+1,a+1+n);
    for (int i=1;i<=n;i++) {
        for (int j=i-1;j>=0;j--) {
            if (a[i].d-a[j].d>=k) {
                pre[i]=j;
                break;
            }
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=m;j>=a[i].v;j--) dp[i][j]=max(dp[i-1][j],dp[pre[i]][j-a[i].v]+a[i].v);
    }
    cout<<dp[n][m]<<"\n";
    return 0;
}