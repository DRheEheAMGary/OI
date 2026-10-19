/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e5+10;
int p[N];
signed main() {
    Cios;
    freopen("inv.in","r",stdin);
    freopen("inv.out","w",stdout);
    int T;
    cin>>T;
    while (T--) {
        int n;
        cin>>n;
        int maxval=-1,res=0;
        for (int i=1;i<=n;i++) cin>>p[i],maxval=max(maxval,p[i]),res+=(maxval==i);
        cout<<res<<"\n";
    }
    return 0;
}

/*
g++ -g inv.cpp -o inv.exe -std=c++14 -O2 -static; echo "finish"; .\inv.exe
*/