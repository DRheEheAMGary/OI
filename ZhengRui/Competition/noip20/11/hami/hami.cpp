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
constexpr intl inf=1ll<<60;
int n,k,dcnt,dpcnt;
int a[N],cnt[10],val[10],c[10],idd[1<<22],iddp[1<<22];
intl mxtr[8][1000],btr[2000];
struct edge {
    int to,rev;
    intl c,cost;
};
signed main() {
    Cios;
    freopen("hami.in","r",stdin);
    freopen("hami.out","w",stdout);
    int T;
    cin>>T;
    while (T--) {
        
    }
    return 0;
}

/*
g++ -g hami.cpp -o hami.exe -std=c++14 -O2 -static; echo "finish"; .\hami.exe; rm hami.exe
cd $work && g++ hami.cpp -o hami -std=c++14 -O2 && echo "finish" && ./hami && rm hami
*/