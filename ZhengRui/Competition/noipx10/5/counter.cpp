/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e5+10,inf=0x3f3f3f3f;
int n,b;
inline int gcd (int a,int b) {
    return b?gcd(b,a%b):a;
}
signed main() {
    freopen("counter.in","r",stdin);
    freopen("counter.out","w",stdout);
    Cios;
    cin>>n>>b;
    int maxv=-inf,g=0;
    int last_t,last_v;
    cin>>last_t>>last_v;
    maxv=max(maxv,last_v);
    int last_d=last_v-last_t;
    for (int i=2;i<=n;i++) {
        int t,v;
        cin>>t>>v;
        maxv=max(maxv,v);
        int d=v-t;
        g=gcd(g,abs(d-last_d));
        last_d=d;
    }
    if (maxv>=b) {
        cout<<0<<"\n";
        return 0;
    }
    if (g==0) {
        cout<<b-maxv<<"\n";
        return 0;
    }
    int res=0;
    for (int i=1;i<=g/i;i++) {
        if (g%i==0) {
            if (i>maxv&&i<=b) res++;
            int oth=g/i;
            if (i!=oth&&oth>maxv&&oth<=b) res++;
        }
    }
    cout<<res<<"\n";
    return 0;
}