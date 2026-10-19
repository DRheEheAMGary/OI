/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define szof sizeof
intc N=1e6+10,mod=998244353;
int n,m,fac[N],ifac[N];
inline int C (int a,int b) {return ((fac[a]*ifac[b]%mod)*ifac[a-b])%mod;}
inline int invC (int a,int b) {return ((ifac[a]*fac[b]%mod)*fac[a-b])%mod;}
int qpow (int a,int b) {
    int res=1;
    while (b) {
        if (b&1) (res*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return res;
}
signed main() {
    Cios;
    cin>>n>>m;
    int res=0;
    fac[0]=1;
    for (int i=1;i<N;i++) fac[i]=(fac[i-1]*i)%mod;
    ifac[N-1]=qpow(fac[N-1],mod-2);
    for (int i=N-2;i>=0;i--) ifac[i]=(ifac[i+1]*(i+1))%mod;
    for (int i=1;i<=min(n,m);i++) (res+=(C(2*i,i)*C(n+m-2*i,n-i))%mod)%=mod;
    (res*=(invC(n+m,n)*ifac[2])%mod)%=mod;
    cout<<(res+max(n,m))%mod<<"\n";
    return 0;
}