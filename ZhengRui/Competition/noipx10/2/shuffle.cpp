/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=6005,mod=998244353;
int n,a[N],b[N];
int c[N][N],e[N][N],f[N],g[N],iv[N];
vector <int> br[N],bl[N];
intl qpow (intl a,intl b) {
    intl res=1;
    while (b) {
        if (b&1) (res*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return res;
}
inline intl inv (intl x) {return qpow(x,mod-2);}
signed main() {
    Cios;
    cin>>n;
    int hn=2*n;
    for (int i=1;i<=n;i++) iv[i]=inv(i);
    for (int i=1;i<=n;i++) {
        cin>>a[i]>>b[i];
        int l=min(a[i],b[i]),r=max(a[i],b[i]);
        c[l][r]++;
        br[r].push_back(i);
        bl[l].push_back(i);
    }
    for (int l=hn;l>=1;l--) {
        for (int r=1;r<=hn;r++) c[l][r]+=c[l+1][r]+c[l][r-1]-c[l+1][r-1];
    }
    memset(g,0,sizeof g);
    for (int l=hn;l>=1;l--) {
        for (int i:bl[l]) {
            int ri=max(a[i],b[i]);
            for (int r=ri;r<=hn;r++) {
                if (a[i]+1<=r) (g[r]+=e[a[i]+1][r])%=mod;
            }
        }
        f[l-1]=0;
        for (int r=l;r<=hn;r++) {
            f[r]=f[r-1];
            for (int i:br[r]) {
                int li=min(a[i],b[i]);
                if (li>=l&&a[i]-1>=l) (f[r]+=e[l][a[i]-1])%=mod;
            }
            if (c[l][r]>0) e[l][r]=(1+1ll*(f[r]+g[r])%mod*iv[c[l][r]])%mod;
        }
    }
    cout<<e[1][hn]<<"\n";
    return 0;
}

/*
g++ -g shuffle.cpp -o shuffle.exe -O2 -std=c++14 -static ; echo "finish" ; .\shuffle.exe

*/