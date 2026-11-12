/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e5+10;
int n;
intl a[N],fl[N],fr[N],pl[N],pr[N];
signed main() {
    Cios;
    int T;
    cin>>T;
    while (T--) {
        cin>>n;
        for (int i=0;i<=n+2;i++) a[i]=fl[i]=fr[i]=pl[i]=pr[i]=0;
        for (int i=1;i<=n;i++) cin>>a[i];
        intl p=0,t=0;
        for (int i=1;i<=n;i++) {
            if (p<a[i]) t+=a[i]-p,p=a[i]-p;
            else p=a[i];
            fl[i]=t;
            pl[i]=p;
        }
        p=0,t=0;
        for (int i=n;i>=1;i--) {
            if (p<a[i]) t+=a[i]-p,p=a[i]-p;
            else p=a[i];
            fr[i]=t;
            pr[i]=p;
        }
        intl mint=1l<<60;
        for (int i=1;i<=n;i++) mint=min(mint,fl[i-1]+fr[i+1]+(abs(a[i]-pl[i-1]-pr[i+1])+(a[i]-pl[i-1]-pr[i+1]))/2);
        cout<<mint<<"\n";
    }
    return 0;
}