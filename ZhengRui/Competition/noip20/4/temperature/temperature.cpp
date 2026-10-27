/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=5e5+10;
int n,k,a[N];
signed main() {
    Cios;
    freopen("temperature.in","r",stdin);
    freopen("temperature.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i],a[i]%=k;
    sort (a+1,a+1+n);
    int maxl=0;
    for (int i=1;i<n;i++) maxl=max(maxl,a[i+1]-a[i]);
    maxl=max(maxl,k-a[n]+a[1]);
    cout<<(k-maxl+1)/2;
    return 0;
}

/*
g++ -g temperature.cpp -o temperature.exe -std=c++14 -O2 -static; echo "finish"; .\temperature.exe
g++  temperature.cpp -o temperature -std=c++14 -O2 && echo "finish" && ./temperature
*/
