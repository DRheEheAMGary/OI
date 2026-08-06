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
intc N=1e5+10;
int n,a[N],p[N],q[N],dmg[N],m,maxd=-1;
int exgcd (int a,int b,int &x,int &y) {
    if (!b) return x=1,y=0,a;
    int x1,y1;
    int d=exgcd(b,a%b,x1,y1);
    x=y1;
    y=x1-a/b*y1;
    return d;
}
int exCRT (){
    int res=0;
    __int128 lcm=1;
    for (int i=1;i<=n;i++) {
        int ga=(__int128)q[i]*lcm%p[i],
            gb=p[i],
            gc=(a[i]-q[i]*res%p[i]+p[i])%p[i];
        int x,y,g;
        g=exgcd(ga,gb,x,y);
        x=(x%gb+gb)%gb;
        if (gc%g) return -1;
        res+=(__int128)(gc/g)*(__int128)x%(gb/g)*(__int128)lcm%(lcm*gb/g);
        lcm*=gb/g;
        res%=lcm;
    }
    if (res<maxd) res+=((maxd-res-1)/lcm+1)*lcm;
    return res;
}
signed main() {
    Cios;
    int T;
    cin>>T;
    while (T--) {
        cin>>n>>m;
        for (int i=1;i<=n;i++) cin>>a[i];
        for (int i=1;i<=n;i++) cin>>p[i];
        for (int i=1;i<=n;i++) cin>>dmg[i];
        multiset <int> s;
        maxd=-1;
        for (int i=1;i<=m;i++) {
            int a;
            cin>>a;
            s.insert(a);
        }
        for (int i=1;i<=n;i++) {
            auto u=s.upper_bound(a[i]);
            if (u!=s.begin()) u--;
            q[i]=(*u);
            s.erase(u);
            s.insert(dmg[i]);
            maxd=max(maxd,(a[i]-1)/q[i]+1);
        }
        cout<<exCRT()<<"\n";
    }
    return 0;
}