/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e5+10;
int n,a[N];
signed main() {
    Cios;
    int T;
    cin>>T;
    while (T--) {
        cin>>n;
        for (int i=1;i<=n;i++) cin>>a[i];
        for (int i=n;i>1;i--) {
            if (a[i]>0) a[i-1]+=a[i];
        }
        int res=0;
        for (int i=1;i<=n;i++) res+=(a[i]>0);
        cout<<res<<"\n";
    }
    return 0;
}