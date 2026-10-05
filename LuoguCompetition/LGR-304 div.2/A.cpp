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
int n,q,a[N],ma[N];
signed main() {
    Cios;
    int T;
    cin>>T;
    while (T--) {
        cin>>n>>q;
        int res=0x3f3f3f3f3f3f3f3f;
        ma[0]=0x3f3f3f3f3f3f3f3f;
        for (int i=1;i<=n;i++) {
            cin>>a[i];
            ma[i]=min(ma[i-1],a[i]);
            res=min(res,ma[i]*i);
        }
        cout<<res<<" ";
        while (q--) {
            int x,y;
            cin>>x>>y;
            if (ma[x]>a[y]) cout<<(res=min(res,a[y]*x))<<" ";
            else cout<<res<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

/*
g++ -g A.cpp -o A.exe -std=c++14 -O2 -static; echo "finish"; .\A.exe
*/