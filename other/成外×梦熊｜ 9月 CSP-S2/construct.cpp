/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int n;
signed main() {
    Cios;
    freopen("construct.in","r",stdin);
    freopen("construct.out","w",stdout);
    cin>>n;
    int l=min((int)ceil(powl(n,1.0l/3)),100);
    int base=1;
    cout<<(l-1)*3+1<<"\n";
    for (int i=0;i<=2;i++) {
        for (int j=1;j<l;j++) cout<<j*base<<" ";
        base*=l;
    }
    cout<<n;
    return 0;
}

/*
g++ -g construct.cpp -o construct.exe -O2 -std=c++14 -static ; echo "finish"; .\construct.exe

*/