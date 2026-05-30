/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define double long double
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
signed main() {
    Cios;
    int T;
    cin>>T;
    while (T--) {
        int x1,x2,y1,y2,r1,r2;
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        double dis=sqrtl(powl(x1-x2,2)+powl(y1-y2,2));
        if (dis<=r1+r2&&dis>=abs(r1-r2)) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}