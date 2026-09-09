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
    freopen ("past.in","r",stdin);
    freopen ("past.out","w",stdout);
    int x,y,z,a,b;
    int T;
    cin>>T;
    while (T--) {
        cin>>x>>y>>z>>a>>b;
        if (x>y) swap(x,y);
        if (y>z) swap(y,z);
        if (x>y) swap(x,y);
        if (y>z) swap(y,z);
        if (x>y) swap(x,y);
        if (y>z) swap(y,z);
        if (x>y) swap(x,y);
        if (y>z) swap(y,z);
        if (a>b) swap(a,b);
        if (x<=a&&y<=b) cout<<"Track complete\n";
        else cout<<"Track lost\n";
    }
    return 0;
}

/*
g++ -g past.cpp -o past.exe -O2 -std=c++14 -static

3
5 5 5 4 10
1 2 3 1 3
2 1 2 1 2

10
10 1 1 1 1
5 10 2 7 7
7 10 3 5 7
3 5 6 7 1
10 9 7 9 2
1 9 6 4 5
2 6 10 4 7
6 5 2 10 10
7 9 7 1 4
1 1 9 5 6
*/