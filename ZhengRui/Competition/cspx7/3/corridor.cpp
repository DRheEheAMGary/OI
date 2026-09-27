/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e5+10;
int n;
string a;
signed main() {
    Cios;
    freopen("corridor.in","r",stdin);
    freopen("corridor.out","w",stdout);
    int T;
    cin>>T;
    while (T--) {
        cin>>n;
        cin>>a;
        a="&"+a;
        int res=0;
        for (int i=1;a[i]=='L';i++) res++;
        for (int i=n;a[i]=='R';i--) res++;
        cout<<res<<"\n";
    }
     return 0;
}

/*
g++ -g corridor.cpp -o corridor.exe -O2 -std=c++14 -static ;echo "finish"; .\corridor.exe

4
4
LLRR
5
LRLRR
4
RLLR
6
RRRLLL

4
3
1
0
*/