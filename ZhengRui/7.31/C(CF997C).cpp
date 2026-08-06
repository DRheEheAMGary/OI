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
int n,C[N],pw[N],pwn[N],inv[N];
int qpow (int a,int b) {
    a=(a%mod+mod)%mod;
    int res=1;
    while (b) {
        if (b&1) (res*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return res%mod;
}
signed main() {
    Cios;
    cin>>n;
    C[1]=n;
    for (int i=1;i<=n;i++) inv[i]=qpow(i,mod-2);
    for (int i=2;i<=n;i++) C[i]=(((C[i-1]*inv[i])%mod)*(n-i+1))%mod;
    pw[0]=1;
    pw[1]=3;
    for (int i=2;i<=n;i++) pw[i]=pw[i-1]*3%mod;
    pwn[0]=1;
    pwn[1]=pw[n];
    for (int i=2;i<=n;i++) (pwn[i]=pwn[i-1]*pwn[1]%mod)%=mod;
    int res=0;
    for (int i=1;i<=n;i++) (res+=(((((C[i]*(i%2==1?(1):(-1))*pw[i])%mod+mod)%mod)*pwn[n-i])%mod+mod)%mod)%=mod;
    res*=2;
    res%=mod;
    int tmp=0;
    for (int i=1;i<=n;i++) (tmp+=(((((((C[i]*qpow(pwn[i],mod-2)%mod+mod)%mod)*(i%2==0?(1):(-1)))%mod+mod)%mod)*(qpow(1-qpow(pw[n-i],mod-2),n)-1)%mod+mod)%mod+mod)%mod)%=mod;
    tmp=(tmp*((pwn[n]*3)%mod))%mod;
    tmp*=-1;
    tmp=(tmp%mod+mod)%mod;
    res+=tmp;
    res%=mod;
    cout<<(res+mod)%mod<<"\n";
    return 0;
}