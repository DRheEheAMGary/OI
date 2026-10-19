/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e6+10;
#ifdef CLANGD_
#define N 10
#endif
int n,m,a[N],sum[2*N+5],val[N];
// vector <int> b[N];
signed main() {
    Cios;
    // freopen ("file/file9.in","r",stdin);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int nwi=n;
    for (int i=2*N;i>=1;i--) {
        sum[i]+=sum[i+1];
        if (i==a[nwi]) sum[i]++,nwi--;
    }
    // for (int i=1;i<=2*n*m;i++) cout<<sum[i]<<" ";
    // cout<<"\n";
    // for (int i=2*N;i>=1;i--) sum[i]+=sum[i+1];
    // for (int i=1;i<=2*n*m;i++) cout<<sum[i]<<" ";
    // cout<<"\n";
    for (int i=1;i<=m;i++) {
        int l;
        cin>>l;
        for (int j=1;j<=l;j++) {
            int b;
            cin>>b;
            val[i]+=sum[b];
        }
    }
    sort(val+1,val+1+m);
    val[0]=(1+n)*n/2;
    int res=0;
    // for (int i=1;i<=n;i++) cout<<val[i]<<" ";
    // cout<<"\n";
    for (int i=1;i<=m;i++) val[i]+=val[i-1],res+=val[i];
    // for (int i=1;i<=n;i++) cout<<val[i]<<" ";
    // cout<<"\n";
    cout<<res<<"\n";
    return 0;
}

/*
g++ -g file.cpp -o file.exe -std=c++14 -O2 -static; echo "finish"; .\file.exe
*/