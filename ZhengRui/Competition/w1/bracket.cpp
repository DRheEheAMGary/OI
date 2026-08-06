/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e6+10;
int n,a[N],sum[N],bkt[N],d1[N],d2[N];
signed main() {
    Cios;
    string s;
    cin>>s;
    n=s.size();
    for (int i=0;i<=n;i++) a[i+1]=(s[i]=='('?1:-1),sum[i+1]=sum[i]+a[i+1];
    intl res=0;
    for (int i=1;i<=n;i++) res+=bkt[sum[i]]++;
    for (int i=1,l=1,r=0;i<=n;i++) {
        int k=(i>r)?1:min(d1[l+r-i],r-i+1);
        while (i-k>=1&&i+k<=n&&a[i-k]==a[i+k]) k++;
        d1[i]=k--;
        res+=d1[i];
        if (i+k>r) l=i-k,r=i+k;
    }
    for (int i=1,l=1,r=0;i<=n;i++) {
        int k=(i>r)?0:min(d2[l+r-i+1],r-i+1);
        while (i-k-1>=1&&i+k<=n&&a[i-k-1]==a[i+k]) k++;
        d2[i]=k--;
        res+=d2[i];
        if (i+k>r) l=i-k-1,r=i+k;
    }
    cout<<res<<"\n";
    return 0;
}