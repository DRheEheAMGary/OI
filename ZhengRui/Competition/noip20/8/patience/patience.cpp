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
#ifdef CLANGD_
#define N 10
#endif
int n,a[N];
int pre[N];
int maxl[N];
int res[N];
signed main() {
    Cios;
    freopen("patience6.in","r",stdin);
    freopen("patience.out","w",stdout);
    // freopen(".err","w",stderr);
    memset(pre,-1,sizeof pre);
    memset(res,-1,sizeof res);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) {
        if (~pre[a[i]]) maxl[a[i]]=max(maxl[a[i]],i-pre[a[i]]);
        else maxl[a[i]]=i;
        pre[a[i]]=i;
    }
    for (int i=1;i<=n;i++) {
        if (~pre[a[i]]) maxl[a[i]]=max(maxl[a[i]],n+1-pre[a[i]]);
        if (maxl[a[i]]) res[maxl[a[i]]]=max(res[maxl[a[i]]],a[i]);
    }
    // for (int i=1;i<=n;i++) cerr<<"i: "<<i<<" maxl: "<<maxl[i]<<" res: "<<res[i]<<"\n";
    int r=-1;
    for (int k=1;k<=n;k++) r=max(r,res[k]),cout<<r<<" ";
    return 0;
}

/*
g++ -g patience.cpp -o patience.exe -std=c++14 -O2 -static; echo "finish"; .\patience.exe; rm patience.exe
cd $work/ZhengRui/Competition/noip20/8/patience && g++ patience.cpp -o patience -std=c++14 -O2 && echo "finish" && ./patience && rm patience
*/