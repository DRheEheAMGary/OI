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
    int n,v;
    cin>>n>>v;
    while (n--) { 
        int a;
        cin>>a;
        v+=1*a-1*(!a);
        if (v>10) v=10;
        if (v<0) v=0;
    }
    cout<<v;
    return 0;
}