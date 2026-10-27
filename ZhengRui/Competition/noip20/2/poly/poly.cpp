/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=3e5+10;
int m[2],q,p;
intl a[2][35],b[2][35];
intl qpow (intl a,int b) {
    if (b==0) return 1;
    intl res=1;
    while (b) {
        if (b&1) (res*=a)%=p;
        (a*=a)%=p;
        b>>=1;
    }
    return res;
}
intl f[2][N];
intl g[2][32][N];
signed main() {
    Cios;
    // freopen("poly.in","r",stdin);
    // freopen("poly.out","w",stdout);
    cin>>m[0]>>m[1]>>q>>p;
    for (int i=1;i<=m[0];i++) cin>>a[0][i]>>b[0][i],a[0][i]%=p;
    for (int i=1;i<=m[1];i++) cin>>a[1][i]>>b[1][i],a[1][i]%=p;
    for (int x=0;x<p;x++) {
        intl res0=0,res1=0;
        for (int i=1;i<=m[0];i++) (res0+=a[0][i]%p*qpow(x,b[0][i]))%=p;
        for (int i=1;i<=m[1];i++) (res1+=a[1][i]%p*qpow(x,b[1][i]))%=p;
        f[0][x]=res0%p;
        f[1][x]=res1%p;
    }
    for (int x=0;x<p;x++) g[1][0][x]=f[0][f[1][x]%p],g[0][0][x]=f[1][f[0][x]%p];
    for (int s=0;s<=1;s++) {
        for (int i=1;i<=30;i++) {
            for (int x=0;x<p;x++) g[s][i][x]=g[s][i-1][g[s][i-1][x]%p]%p;
        }
    }
    while (q--) {
        intl x,y;
        int s;
        cin>>x>>y>>s;
        x%=p;
        if (y%2==1) {
            x=f[s][x];
            s^=1;
        }
        y/=2;
        for (int bit=0;y>0;bit++,y/=2) {
            if (y&1) x=g[s][bit][x]%p;
        }
        cout<<x<<"\n";
    }
    return 0;
}

/*
g++ poly.cpp -o poly -std=c++14 -O2; echo "finish"; ./poly
*/