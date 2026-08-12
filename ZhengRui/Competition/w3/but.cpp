/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define szof sizeof
int a,b;
signed main() {
    // freopen("test/but/ex_but4.in","r",stdin);
    // freopen("ans.out","w",stdout);
    Cios;
    int c,T;
    cin>>c>>T;
    while (T--) {
        cin>>a>>b;
        int ai=floor(sqrtl(a));
        int bi=floor((sqrtl(1+4*b)-1)/2);
        if (ai>bi) cout<<"AWaDa!\n";
        else cout<<"AKTang!\n";
    }
    return 0;
}