/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int n,a[10005],b[10005];
signed main() {
    Cios;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) b[i]=a[i]==a[n-i+1];
    for (int i=1;i<=n;i++) cout<<b[i]<<" ";
    return 0;
}