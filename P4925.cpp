/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intl k,l,p,s,w;
intl qpow (intl a,intl b) {
    a%=p;
    intl res=1;
    while (b) {
        if (b&1) (res*=a)%=p;
        (a*=a)%=p;b>>=1;
    }
    return res;
}
signed main() {
    Cios;
    cin>>k>>l>>p>>s>>w;
    if (s) {
        if (l==1) cout<<1<<"\n";
        else if (l==2) cout<<(k-1)%p<<"\n";
        else cout<<(((k-1)%p)*(qpow(k-2,l-2))%p)%p<<"\n";
    } 
    else {
        if (l==1) cout<<k%p<<"\n";
        else if (l==2) cout<<((k%p)*((k-1)%p))%p<<"\n";
        else cout<<((((k%p)*((k-1)%p))%p)*qpow(k-2,l-2))%p<<"\n";
    }
    return 0;
}

/*
g++ -g mainc.cpp -o mainc.exe -std=c++14 -O2 -static; echo "finish"; .\mainc.exe; rm mainc.exe
cd $work && g++  mainc.cpp -o mainc -std=c++14 -O2 && echo "finish" && ./mainc && rm mainc
*/