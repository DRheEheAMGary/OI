/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=105;
int n,m,a[N];
signed main() {
    Cios;
    int T;
    cin>>T;
    while (T--) {
        cin>>n>>m;
        for (int i=0;i<=n;i++) cin>>a[i];
        int rres=-1;
        for (int i=1;i<=m;i++) {
            __int128 res=a[0]+__int128(a[1])*i;
            for (int j=2;j<=n;j++) res+=__int128(a[j])*(i^j);
            if (res==0) {
                rres=i;
                break;
            }
        }
        cout<<rres<<"\n";
    }
    return 0;
}

/*
g++ -g mainf.cpp -o mainf.exe -std=c++14 -O2 -static; echo "finish"; .\mainf.exe
*/