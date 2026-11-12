/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e5+10;
int n;
intl a[N];
intl p[N],premax[N],premin[N],sufmax[N],sufmin[N];
signed main() {
    Cios;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) p[i]=p[i-1]+a[i];
    premax[0]=premin[0]=p[0];
    for (int i=1;i<=n;i++) premax[i]=max(premax[i-1],p[i]),premin[i]=min(premin[i-1],p[i]);
    sufmax[n]=sufmin[n]=p[n];
    for (int i=n-1;i>=0;i--) sufmax[i]=max(sufmax[i+1],p[i]),sufmin[i]=min(sufmin[i+1],p[i]);
    intl res=premax[n]-premin[n]+1;
    for (int i=1;i<=n;i++) res=max(res,max(premax[i-1],sufmax[i]-2*a[i])-min(premin[i-1],sufmin[i]-2*a[i])+1);
    cout<<res<<"\n";
    return 0;
}

/*
g++ -g mainc.cpp -o mainc.exe -std=c++14 -O2 -static; echo "finish"; .\mainc.exe; rm mainc.exe
cd $work && g++  mainc.cpp -o mainc -std=c++14 -O2 && echo "finish" && ./mainc && rm mainc
*/