/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e5+10;
int n,s,k,x[N];
signed main() {
    Cios;
    freopen ("vis.in","r",stdin);
    freopen ("vis.out","w",stdout);
    cin>>n>>s>>k;
    for (int i=1;i<=n;i++) cin>>x[i];
    sort(x+1,x+1+n);
    int lb=lower_bound(x+1,x+1+n,s)-x;
    int res=0;
    if (k==0) res=min(s-x[1],x[n]-s)+x[n]-x[1];
    else {
        if (x[lb]==s) res=x[n]-x[1];
        else res=min(s-x[lb-1],x[lb]-s)+x[n]-x[1];
    }
    cout<<res<<"\n";
    return 0;
}