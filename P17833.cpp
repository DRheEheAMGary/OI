/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e6+10;
intl n,d,x[N];
intl f1[N],f2[N],fii1[N];
intl lst[N],rst[N];
signed main() {
    Cios;
    int __c,T;
    cin>>__c>>T;
    while (T--) {
        cin>>n>>d;
        for (int i=1;i<=n;i++) cin>>x[i];
        for (int i=0;i<=n+5;i++) f1[i]=f2[i]=fii1[i]=0;
        for (intl l=1,r=1,i=1;i<=n;i++) {
            while (x[i]-x[l]>d) l++;
            while (r+1<=n&&x[r+1]-x[i]<=d) r++;
            lst[i]=l;
            rst[i]=r;
        }
        intl res=0;
        for (int i=1;i<=n;i++) {
            intl l=lst[i],r=rst[i];
            if (l<i) res+=f2[l];
            if (l+1<i) res+=fii1[l+1];
            if (i==r) continue;
            f1[r]++;
            if (lst[r]==i) f1[r]+=f1[i],f2[r]+=f2[i];
            if (lst[r]==i-1) f2[r]+=fii1[i];
            if (r-1>i) {
                fii1[r]++;
                if (lst[r-1]==i) fii1[r]+=f1[i];
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}