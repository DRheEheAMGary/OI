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
    int cnte=0,cntw=0;
    string s;
    cin>>s;
    for (char c:s) {
        if (c=='E') cnte++;
        else cntw++;
    }
    cout<<(cnte<cntw?"West":"East");
    return 0;
}