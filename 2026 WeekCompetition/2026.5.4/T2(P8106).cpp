/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e5+10,mod=998244353;
int n,f[N],invf[N];
int qpow (int a,int b) {
    int res=1;
    while (b) {
        if (b&1) (res*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return res;
}
inline int C(int n,int m) {
    return (((f[n]*invf[m])%mod)*invf[n-m])%mod;
}
signed main() {
    Cios;
    f[0]=f[1]=1;
    for (int i=2;i<N;i++) f[i]=(i*f[i-1])%mod;
    invf[N-1]=qpow(f[N-1],mod-2);
    for (int i=N-2;i>=0;i--) invf[i]=((i+1)*invf[i+1])%mod;
    cin>>n;
    if (n<=2) cout<<0;
    else if (n%2==1) cout<<qpow(2,n-2);
    else cout<<((qpow(2,n-2)-C(n-2,(n-2)/2))%mod+mod)%mod;
    return 0;
}