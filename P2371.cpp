/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=5e5+10,inf=2e18;
int n,l,r,a[20],dis[N];
int gcd (int a,int b) {
    return b==0?a:gcd(b,a%b);
}
int getans (int x,int m) {
    if (x<0) return 0;
    int res=0;
    for (int i=0;i<m;i++) {
        if (dis[i]<=x) res+=(x-dis[i])/m+1;
    }
    return res;
}
signed main() {
    Cios;
    cin>>n>>l>>r;
    int idx=0;
    for (int i=1;i<=n;i++) {
        int vl;
        cin>>vl;
        if (vl!=0) a[++idx]=vl;
    }
    n=idx;
    if (n==0) {
        cout<<0<<"\n";
        return 0;
    }
    sort (a+1,a+1+n);
    int m=a[1];
    for (int i=1;i<m;i++) dis[i]=inf;
    dis[0]=0;
    for (int i=2;i<=n;i++) {
        int step=a[i]%m;
        if (step==0) continue;
        int d=gcd(step,m);
        for (int st=0;st<d;st++) {
            int cur=st;
            for (int rd=0;rd<2;rd++) {
                for (int cnt=0;cnt<m/d;cnt++) {
                    int nxt=(cur+step)%m;
                    if (dis[cur]!=inf&&dis[nxt]>dis[cur]+a[i]) dis[nxt]=dis[cur]+a[i];
                    cur=nxt;
                }
            }
        }
    }
    cout<<getans(r,a[1])-getans(l-1,a[1])<<"\n";
    return 0;
}