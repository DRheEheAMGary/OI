/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
inline int val (int x,int i) {return (x>>i)&1;}
inline int gcd (int a,int b) {return b?gcd(b,a%b):a;}
signed main() {
    Cios;
    // freopen ("maxval.in","r",stdin);
    // freopen ("maxval.out","w",stdout);
    // for (int i=1;i<=20;i++) {
    //     int maxval=-1;
    //     for (int st=0;st<(1<<i);st++) {
    //         int g=0,sz=0;
    //         for (int j=0;j<i;j++) {
    //             if (val(st,j)) g=gcd(j+1,g),sz++;
    //         }
    //         maxval=max(maxval,g^sz);
    //     }
    //     cout<<i<<": "<<maxval<<"\n";
    // }
    int T;
    cin>>T;
    while (T--) {
        int n;
        cin>>n;
        if (n==1) cout<<0<<"\n";
        else cout<<(n+!(n%2))<<"\n";
    }
    return 0;
}

/*
g++ -g maxval.cpp -o maxval.exe -O2 -std=c++14 -static ; echo "finish" ; .\maxval.exe

*/