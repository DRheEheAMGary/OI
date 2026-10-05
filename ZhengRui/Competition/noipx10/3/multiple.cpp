/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
signed main() {
    Cios;
    freopen("multiple.in","r",stdin);
    freopen("multiple.out","w",stdout);
    int res=0x3f3f3f3f;
    int a,b;
    cin>>a>>b;
    for (int dta=0;b-dta>0;dta++) {
        int a1=a%(b-dta),a2=a%(b+dta);
        if (a1<a) res=min(res,a1+dta);
        if (a2<a) res=min(res,a2+dta);
        res=min({res,(b-a1),(b-a2+dta*2)});
    }
    cout<<res<<"\n";
    return 0;
}

/*
g++ -g multiple.cpp -o multiple.exe -std=c++14 -O2 -static; echo "finish"; .\multiple.exe
*/