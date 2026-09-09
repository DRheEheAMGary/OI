/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=5e5+10;
int n,l[N];
signed main() {
    Cios;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>l[i];
    sort(l+1,l+1+n);
    int tot=n;
    int nw_fir=1;
    int res=0;
    while (tot>1) {
        int use=l[nw_fir++];
        tot--;
        if (use<=tot-1) res+=use,tot-=use;
        else res+=tot,tot=1;
    }
    cout<<res;
    return 0;
}