/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e6+10;
int n,k,a[N];
bool solve (int res) {
    int idx=0,nw=0;
    for (int i=1;i<=n;i++) {
        nw+=a[i];
        if (nw>=res) idx++,nw=0;
    }
    if (nw>=res) idx++;
    return idx>=n-k;
}
signed main() {
    Cios;
    int c,q;
    cin>>c>>q;
    while (q--) {
        cin>>n>>k;
        int l=0,r=0,res=0x3f3f3f3f3f3f3f3f;
        for (int i=1;i<=n;i++) cin>>a[i],r+=a[i],res=min(res,a[i]);
        while (l<=r) {
            int mid=(l+r)>>1;
            if (solve(mid)) l=mid+1,res=mid;
            else r=mid-1;
        }
        cout<<res<<"\n";
    }
    return 0;
}