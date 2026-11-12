/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e6+10;
constexpr intl inf=1ll<<60;
int a[N],ans[N];
signed main() {
    Cios;
    int T;
    cin>>T;
    while (T--) {
        int n,m;
        cin>>n>>m;
        for (int i=1;i<=m;i++) cin>>a[i];
        int tot=0;
        int target=m-1;
        for (int i=1;i<=m;i++) {
            if (a[i]-i==target) ans[++tot]=a[i];
        }
        cout<<tot<<"\n";
        for (int i=1;i<=tot;i++) {
            cout<<ans[i]<<" \n"[i==tot];
        }
    }
    return 0;
}