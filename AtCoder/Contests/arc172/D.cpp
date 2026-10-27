/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=500;
int n,a[N],b[N],res[N][N];
signed main() {
    Cios;
    cin>>n;
    for (int i=1;i<=n*(n-1)/2;i++) cin>>a[i]>>b[i];
    for (int i=1;i<=n;i++) res[i][i]=1e8;
    for (int i=1;i<=n*(n-1)/2;i++) res[b[i]][a[i]]+=n*(n-1)/2-i+1;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) cout<<res[i][j]<<" \n"[j==n];
    }
    return 0;
}

/*
g++ -g mainf.cpp -o mainf.exe -std=c++14 -O2 -static; echo "finish"; .\mainf.exe
g++  mainf.cpp -o mainf -std=c++14 -O2 && echo "finish" && ./mainf
*/