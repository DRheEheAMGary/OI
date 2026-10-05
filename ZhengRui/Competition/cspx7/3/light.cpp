/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc mod=998244353;
int n;
string s;
int qpow (int a,int b) {
    if (b<0) return 0;
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
    freopen("light.in","r",stdin);
    freopen("light.out","w",stdout);
    int T;
    cin>>T;
    while (T--) {
        cin>>n;
        cin>>s;
        int res=0;
        int l=0;
        for (int i=0;i<n;i++) l+=(s[i]=='?');
        for (int i=0;i<n;i++) {
            int pi=(i-1+n)%n;
            if (s[i]=='1'&&s[pi]=='0') (res+=qpow(2,l))%=mod;
            if (s[i]=='1'&&s[pi]=='?') (res+=qpow(2,l-1))%=mod;
            if (s[i]=='?'&&s[pi]=='0') (res+=qpow(2,l-1))%=mod;
            if (s[i]=='?'&&s[pi]=='?') (res+=qpow(2,l-2))%=mod;
        }
        int _0=0;
        for (int i=0;i<n;i++) {_0+=s[i]=='0';}
        res+=!_0;
        cout<<res<<"\n";
    }
    return 0;
}

/*
g++ -g light.cpp -o light.exe -O2 -std=c++14 -static ; echo "finish" ; .\light.exe

1
3
???

1
4
0101
*/