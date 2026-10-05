/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=100;
int f[N],invf[N];
intl qpow (intl a,int b,intl mod) {
    intl res=1;
    while (b) {
        if (b&1) (res*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return res;
}
intl inv (intl a,intl mod) {return qpow(a,mod-2,mod);}
void getf (int mod) {
    f[0]=f[1]=1;
    for (int i=2;i<N;i++) f[i]=f[i-1]*i%mod;
    invf[N-1]=inv(f[N-1],mod);
    for (int i=N-2;i>=0;i--) invf[i]=invf[i+1]*(i+1)%mod;
}
intl C (int a,int b,int mod) {
    if (a<b||a<0||b<0) return 0;
    return f[a]*invf[b]%mod*invf[a-b]%mod;
}
intl A (int a,int b,int mod) {
    if (a<b||a<0||b<0) return 0;
    return f[a]*invf[a-b]%mod;
}
signed main() {
    Cios;
    freopen("prefixsort.in","r",stdin);
    freopen("prefixsort.out","w",stdout);
    int T;
    cin>>T;
    for (int _taskid=1;_taskid<=T;_taskid++) {
        cout<<"Case #"<<_taskid<<": ";
        intl n,k,q;
        const intl &mod=q;
        cin>>n>>k>>q;
        getf(q);
        k=min(n,k);
        intl res=0,mul=A(k,k,q);
        res+=mul;
        
    }
    return 0;
}

/*
g++ -g prefixsort.cpp -o prefixsort.exe -std=c++14 -O2 -static; echo "finish"; .\prefixsort.exe
*/