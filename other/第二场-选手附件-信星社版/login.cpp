/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=3e5+10;
#ifdef CLANGD_
#define N 10
#endif
int n,q;
struct Log {
    int t,b;
}li[N];
signed main() {
    Cios;
    freopen("login.in","r",stdin);
    freopen("login.out","w",stdout);
    cin>>n>>q;
    for (int i=1;i<=n;i++) {
        cin>>li[i].t>>li[i].b;
    }
    while (q--) {
        int l,r;
        cin>>l>>r;
        vector <bool> st(n+1,0);
        int res=0,rres=0;
        for (int i=l;i<=r;i++) {
            if (li[i].t==1) {
                if (st[li[i].b]==0) res++;
                st[li[i].b]=1;
            }
            else {
                if (st[li[i].b]==1) res--;
                st[li[i].b]=0;
            }
            rres=max(res,rres);
        }
        cout<<rres<<"\n";
    }
    return 0;
}

/*
g++ -g login.cpp -o login.exe -std=c++14 -O2 -static; echo "finish"; .\login.exe
*/