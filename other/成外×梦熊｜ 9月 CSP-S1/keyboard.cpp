/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=5005,M=2e4+10;
int n,m,p,q,t,l;
int c[N],s[N];
int idx[N],iidx[N];
signed main() {
    Cios;
    freopen ("keyboard.in","r",stdin);
    freopen ("keyboard.out","w",stdout);
    cin>>n>>m>>p>>q>>t;
    for (int i=1;i<=n;i++) {
        cin>>c[i];
        for (int j=1;j<=c[i];j++) {
            int _w;
            cin>>_w;
            idx[_w]=i;
            iidx[_w]=j;
        }
    }
    cin>>l;
    for (int i=1;i<=l;i++) cin>>s[i];
    int nwt=1,res=0;
    for (int i=1;i<=l;i++) {
        int ns=s[i];
        int ni=idx[ns];
        int ii=iidx[ns];
        int k=nwt%c[ni];
        if (k==0) k=c[ni];
        cout<<ns<<" "<<ni<<" "<<ii<<" "<<k<<"\n";
        if (k==ii) res+=p;
        else {
            int _tt=(k<ii)?(ii-k):(c[ni]-k+ii);
            if (t*_tt+p<q+abs(k-ii)) res+=t*_tt+p,nwt+=_tt;
            else res+=q+abs(k-ii);
        }
    }
    cout<<res<<"\n";
    return 0;
}

/*
2 5 3 7 2
2 1 3
3 2 4 5
6
1 3 4 5 2 3

2 7 2 20 1
5 3 1 5 7 2
2 4 6
8
3 6 7 4 2 1 5 3

g++ -g keyboard.cpp -o keyboard.exe -O2 -std=c++11 -static
*/