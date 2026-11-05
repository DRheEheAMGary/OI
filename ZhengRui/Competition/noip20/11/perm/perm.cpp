/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e6+10;
constexpr intl mod=998244353;
int n,a[N];
signed main() {
    Cios;
    freopen("perm.in","r",stdin);
    freopen("perm.out","w",stdout);
    cin>>n;
    int cnt0=0,cnt1=0;
    for (int i=1;i<=n;i++) cin>>a[i],cnt0+=(a[i]==0),cnt1+=(a[i]==1);
    int need0=n/2,need1=(n+1)/2;
    if (need0!=cnt0||need1!=cnt1) return cout<<"0\n",0;
    if (n%2==1) {
        intl res=1,c=1;
        for (int i=n;i>=1;i--) {
            if (c<=0) return cout<<"0\n",0;
            (res*=c)%=mod;
            if (a[i]==0) c++;
            else c--;
        }
        if (c!=0) res=0;
        cout<<res<<"\n";
    }
    else {
        intl f0=1,f1=0,c=1;
        for (int i=n;i>=1;i--) {
            if (c<=0) return cout<<"0\n",0;
            intl nf0,nf1;
            if (a[i]==0) nf0=f0*c,nf1=f1*(c-1)+f0,c++;
            else nf0=f0*(c-1),nf1=f1*(c-1),c--;
            f0=nf0%mod;
            f1=nf1%mod;
        }
        if (c!=1) f1=0;
        cout<<f1<<"\n";
    }
    return 0;
}

/*
g++ -g perm.cpp -o perm.exe -std=c++14 -O2 -static; echo "finish"; .\perm.exe; rm perm.exe
cd $work/ZhengRui/Competition/noip20/11/perm && g++ perm.cpp -o perm -std=c++14 -O2 && echo "finish" && ./perm && rm perm
*/