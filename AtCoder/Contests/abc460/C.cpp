/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e5+10;
int n,m,a[N],b[N];
signed main() {
    Cios;
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int j=1;j<=m;j++) cin>>b[j];
    sort(a+1,a+1+n,[&] (int a,int b) {return a>b;});
    sort(b+1,b+1+m,[&] (int a,int b) {return a>b;});
    int res=0;
    for (int i=1,j=1;i<=n&&j<=m;) {
        if (b[j]>a[i]*2) j++;
        else i++,j++,res++;
    }
    cout<<res<<"\n";
    return 0;
}