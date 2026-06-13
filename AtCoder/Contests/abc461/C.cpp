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
int n,k,m;
struct gem {
    int c,v;
    bool operator < (const gem &a) const {
        return v>a.v;
    }
}g[N];
map <int,bool> mp;
bool imp[N];
signed main() {
    Cios;
    cin>>n>>k>>m;
    for (int i=1;i<=n;i++) {
        cin>>g[i].c>>g[i].v;
    }
    sort (g+1,g+1+n);
    int res=0,chose=0;
    for (int i=1;i<=n;i++) {
        if (chose==m) break;
        if (mp[g[i].c]) continue;
        mp[g[i].c]=1;
        imp[i]=1;
        res+=g[i].v;
        chose++;
    }
    for (int i=1;i<=n;i++) {
        if (chose==k) break;
        if (imp[i]) continue;
        res+=g[i].v;
        chose++;
    }
    cout<<res<<"\n";
    return 0;
}