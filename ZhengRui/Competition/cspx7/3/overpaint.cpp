/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=4005,M=1e8+10,mod=998244353;
int n,m,p[N];
int f[N],invf[N];
inline int C (int a,int b) {
    if (a<0||b<0||a<b) return 0;
    return ((f[a]*invf[b])%mod*invf[a-b])%mod;
}
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
    if (n>2*m) return cout<<0<<"\n",0;
    f[0]=1;
    for (int i=1;i<N;i++) f[i]=f[i-1]*i%mod;
    invf[N-1]=qpow(f[N-1],mod-2);
    for (int i=N-2;i>=0;i--) invf[i]=invf[i+1]*(i+1)%mod;
    p[1]=1;
    int cmr=1;
    int res=(n==2)?1:0;
    for (int r=2;r<=min(m,n-1);r++) {
        int rres=0;
        for (int j=r;j>=1;j--) {
            if (2*j>r+1) p[j]=0;
            else (p[j]=2*j*p[j]+(r-2*j+2)*p[j-1])%=mod;
            (rres+=p[j]*C(r-j,n-r-j))%=mod;
        }
        cmr=cmr*(m-r+1)%mod*qpow(r-1,mod-2)%mod;
        (res+=(cmr*rres)%mod)%=mod;
    }
    cout<<res<<"\n";
    return 0; 
}