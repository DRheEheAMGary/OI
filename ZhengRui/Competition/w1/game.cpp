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
    int t;
    cin>>t;
    while (t--) {
        int a;
        cin>>a;
        if (a==(a&(-a))) cout<<"Win\n";
        else cout<<"Lose\n";
    }
    return 0; 
}