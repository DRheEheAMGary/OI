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
    freopen("ppip.in","r",stdin);
    freopen("ppip.out","w",stdout);
    int res;
    string s;
    cin>>s;
    for (char c:s) res+=(c=='P'?1:(-1));
    cout<<abs(res);
    return 0;
}

/*
g++ -g ppip.cpp -o ppip.1 -O2 -std=c++14; echo "finish"; ./ppip.1
*/