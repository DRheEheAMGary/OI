/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc mod=1e9+7;
int a,b,k;
inline int qpow (int _a,int b) {
    __int128 res=1;
    __int128 a=_a;
    while (b) {
        if (b&1) res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}
signed main() {
    int T;
    cin>>T;
    while (T--) {
        cin>>k;
        cin>>a>>b;
        cout<<qpow (2,(b-a+1)-max(b/k-(a-1),0ll))%mod<<"\n";
    }
    return 0;
}
