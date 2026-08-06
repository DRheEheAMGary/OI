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
#define int128 __int128
int exgcd (int a,int b,int &x,int &y) {
    if (b==0) return x=1,y=0,a;
    int x1,y1;
    int d=exgcd(b,a%b,x1,y1);
    x=y1;
    y=x1-a/b*y1;
    return d;
}
int n;
signed main() {
    Cios;
    cin>>n;
    int m,x;
    for (int i=1;i<=n;i++) {
        int a,b;
        cin>>a>>b;
        if (i==1) m=a,x=b%a;
        else {
            int c=((b-x)%a+a)%a;
            int t,y,d=exgcd(m,a,t,y);
            int mod=a/d;
            t=(t%mod+mod)%mod;
            t=(int)((int128)t*(c/d)%mod);
            x=x+t*m;
            m=m/d*a;
            x=(x%m+m)%m;
        }
    }
    cout<<x<<"\n";
    return 0;
}