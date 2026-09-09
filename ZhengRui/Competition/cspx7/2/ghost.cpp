/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=5e5+10;
int n,m,k,a[N];
inline int f (int x) {return (x+abs(x))/2;}
signed main() {
    Cios;
    freopen ("ghost.in","r",stdin);
    freopen ("ghost.out","w",stdout);
    cin>>n>>m>>k;
    int sum=0;
    for (int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
    int nres=0;
    for (int i=1;i<=m;i++) nres+=f(a[i]-k);
    int res=nres;
    for (int i=m+1;i<=n;i++) {
        nres=nres-f(a[i-m]-k)+f(a[i]-k);
        res=max(res,nres);
    }
    cout<<sum-res<<"\n";
    return 0;
}

/*
g++ -g ghost.cpp -o ghost.exe -O2 -std=c++14 -static ; .\ghost.exe

5 2 1
1 3 0 1 4
*/