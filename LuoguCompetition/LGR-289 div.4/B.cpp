/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
signed main() {
    Cios;
    int h,m;
    cin>>h>>m;
    if (h<7||h==7&&m<30) cout<<"EARLY\n";
    else if (h==7&&m>=30||h==8&&m==0) cout<<"ON TIME\n";
    else cout<<"LATE\n";
    return 0;
}