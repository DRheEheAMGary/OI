/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define szof sizeof
intc N=1e5+10;
int n,x[N],p[N];
signed main() {
    Cios;
    cin>>n;
    int idx=0;
    for (int i=1;i<=n;i++) cin>>x[i];
    for (int i=1;i<=n;i++) {
        if (x[i]-x[i-1]!=1) p[x[i]]=++idx;
    }
    for (int i=1;i<=n;i++) {
        if (!p[i]) p[i]=++idx;
    }
    for (int i=1;i<=n;i++) cout<<p[i]<<" ";
    return 0;
}