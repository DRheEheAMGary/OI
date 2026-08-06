/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define double long double
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define szof sizeof
constexpr double eps=1e-9;
intc N=5e5+10;
struct node {
    double c,d;
    bool operator < (const node &p) const {
        if (abs(c-p.c)<=eps) return d<p.d;
        return c>p.c;
    }
}p[N];
int n,k,a[N];
double d[N];
bool solve (double x) {
    for (int i=1;i<=n;i++) p[i]={a[i]-x*i,a[i]+x*i};
    sort(p+1,p+1+n);
    d[1]=p[1].d;
    int len=1;
    for (int i=2;i<=n;i++) {
        if (p[i].d>=d[len]) d[++len]=p[i].d;
        else {
            int j=upper_bound(d+1,d+1+len,p[i].d)-d;
            d[j]=p[i].d;
        }
    }
    return len>=n-k;
}
signed main() {
    Cios;
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    double l=0,r=1e9+10,res=0;
    for (int i=1;i<=75;i++) {
        double mid=(l+r)/2;
        if (solve(mid)) res=mid,r=mid;
        else l=mid;
    }
    cout<<fixed<<setprecision(9)<<res<<"\n";
    return 0;
}