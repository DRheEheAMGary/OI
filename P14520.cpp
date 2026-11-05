/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e5+10;
int T,n;
intl a[N];
signed main() {
    Cios;
    cin>>T;
    while (T--) {
        cin>>n;
        for (int i=1;i<=n;i++) cin>>a[i],a[i]+=a[i-1];
        for (int m=1;m<n;m++) cout<<(a[m]>a[n]-a[m]);
        cout<<"\n";
    }
    return 0;
}

/*
g++ -g P14520.cpp -o P14520.exe -std=c++14 -O2 -static; echo "finish"; .\P14520.exe; rm P14520.exe
cd $work && g++ P14520.cpp -o P14520 -std=c++14 -O2 && echo "finish" && ./P14520 && rm P14520
*/