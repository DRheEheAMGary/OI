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
intc mod=1e9+7;
int a,x;
int f (int n);
int g (int n) {
    if (n<10) return (f(n+1)-f(n))%mod;
    return ((((n+1)%a==0)+g(n/2))%mod+mod)%mod;
}
int f (int n) {
    if (n==0) return 0;
    if (n==1) return x;
    if (n%2==0) return (n/a+2*f(n/2))%mod;
    return (n/a+2*f(n/2)+g(n/2))%mod;
}
signed main() {
    // freopen("test/ex_cross6.in","r",stdin);
    // freopen("ans.out","w",stdout);
    Cios;
    int c,T;
    cin>>c>>T;
    while (T--) {
        int n;
        cin>>n>>a>>x;
        cout<<(f(n))%mod<<"\n";
    } 
    return 0;
}