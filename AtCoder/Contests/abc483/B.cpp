/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int n,q;
int a[105];
signed main() {
    Cios;
    cin>>n>>q;
    for (int i=1;i<=n;i++) a[i]=i;
    while (q--) {
        int k;
        cin>>k;
        reverse(a+1,a+1+k);
        for (int i=1;i<=k;i++) a[i]=-a[i];
    }
    for (int i=1;i<=n;i++) cout<<a[i]<<"\n";
    return 0;
}