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
int n,q,a[N],sum[N];
signed main() {
    Cios;
    int T;
    cin>>T;
    while (T--) {
        cin>>n>>q;
        for (int i=1;i<=n;i++) cin>>a[i];
        sort (a+1,a+1+n);
        for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
        while (q--) {
            int x,k,m;
            cin>>x>>k>>m;
            int l=0,r=n+1,res=0;
            while (l<=r) {
                int mid=(l+r)>>1;
                if (sum[mid]<=x) res=mid,l=mid+1;
                else r=mid-1;
            }
            res=min({res,n-k,m});
            cout<<sum[res+k]-sum[res]<<"\n";
        }
    
    }
    return 0;
}

/*
g++ -g mainc.cpp -o mainc.exe -std=c++14 -O2 -static; echo "finish"; .\mainc.exe
cd $work && g++  mainc.cpp -o mainc -std=c++14 -O2 && echo "finish" && ./mainc
*/