/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
double dp[1<<15][15];
int n;
struct point {
    double x,y;
}p[16];
inline double dis (point x,point y) {return sqrt(pow(x.x-y.x,2)+pow(x.y-y.y,2));}
signed main() {
    Cios;
    cin>>n;
    for (int i=0;i<n;i++) cin>>p[i].x>>p[i].y;
    for (int i=0;i<(1<<n);i++) {
        for (int j=0;j<n;j++) {
            if ((1<<j)&i) dp[i][j]=1e20;
        }
    }
    for (int i=0;i<n;i++) dp[1<<i][i]=dis({0,0},p[i]);
    for (int i=0;i<(1<<n);i++) {
        for (int j=0;j<n;j++) {
            if (!((1<<j)&i)) continue;
            for (int k=0;k<n;k++) {
                if ((1<<k)&i) continue;
                dp[i|(1<<k)][k]=min(dp[i|(1<<k)][k],dp[i][j]+dis(p[j],p[k]));
            }
        }
    }
    double res=1e20;
    for (int i=0;i<n;i++) res=min(dp[(1<<n)-1][i],res);
    cout<<fixed<<setprecision(2)<<res<<"\n";
    return 0;
}