/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e5+10,inf=1<<30;
int n,k;
int dis[N];
void chg (int i) {
    if (i>n) return;
    if (dis[i]>=inf) return;
    int tmp=dis[i];
    dis[i]=min(i>1?dis[i-1]:inf,i>k?dis[i-k]+1:inf);
    if (tmp!=dis[i]) {
        chg(i+1);
        chg(i+k);
    }
}
signed main() {
    Cios;
    // freopen("dino.in","r",stdin);
    // freopen("dino.out","w",stdout);
    // freopen("dino.err","w",stderr);
    int q;
    cin>>n>>q>>k;
    while (q--) {
        int op,x;
        cin>>op>>x;
        if (op==1) {
            dis[x]=inf;
            chg(x+1);
            chg(x+k);
        }
        else if (op==2) cout<<((dis[x]>=inf)?-1:dis[x])<<"\n";
        // for (int i=1;i<=n;i++) cerr<<dis[i]<<" \n"[i==n];
    }
    return 0;
}

/*
g++ -g dino.cpp -o dino.exe -std=c++14 -O2 -static; echo "finish"; .\dino.exe
g++  dino.cpp -o dino -std=c++14 -O2 && echo "finish" && ./dino
*/