/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e6+5;
int n,k,a[N],q[N],ans[N];
signed main() {
    Cios;
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    int h=1,t=0;
    for (int i=1;i<=n;i++) {
        while (h<=t&&a[q[t]]>=a[i]) t--;
        q[++t]=i;
        if (q[h]<=i-k) h++;
        if (i>=k) ans[i]=a[q[h]];
    }
    for (int i=k;i<=n;i++) cout<<ans[i]<<" ";
    cout<<"\n";
    h=1,t=0;
    for (int i=1;i<=n;i++) {
        while (h<=t&&a[q[t]]<=a[i]) t--;
        q[++t]=i;
        if (q[h]<=i-k) h++;
        if (i>=k) ans[i]=a[q[h]];
    }
    for (int i=k;i<=n;i++) cout<<ans[i]<<" ";
    cout<<"\n";
    return 0;
}