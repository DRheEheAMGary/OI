/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e5+10;
int n,k;
int res;
struct segment {
    int w,l;
}s[N];
signed main() {
    Cios;
    freopen("seq.in","r",stdin);
    freopen("seq.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
        cin>>s[i].l;
        for (int j=1;j<=s[i].l;j++) {
            int a;
            cin>>a;
            res+=a*j;
            s[i].w+=a;
        }
    }
    sort(s+1,s+1+n,[&] (segment a,segment b) {
        if (a.w==0) return true;
        if (b.w==0) return false;
        return a.l*b.w>a.w*b.l;
    });
    int pref=0;
    for (int i=1;i<=n;i++) res+=s[i].w*pref,pref+=s[i].l;
    if (k==1) {
        cout<<res<<"\n";
        return 0;
    }
    int dta=0x7fffffffffffffff;
    for (int i=1;i<n;i++) dta=min(dta,s[i].l*s[i+1].w-s[i+1].l*s[i].w);
    cout<<res-dta<<"\n";
    return 0;
}

/*
clang++ -g seq.cpp -o seq -std=c++14 -O2 && echo "finish" && .\seq
*/