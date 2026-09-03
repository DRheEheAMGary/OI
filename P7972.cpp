/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=3e5+10,mod=1e9+7;
int n,a[N],f[N],l[N],r[N];
class Fenwick {
    int tr[N];
    inline int lb (int x) {return x&(-x);}
    public:
    inline void update (int x,int v) {
        while (x<N) {
            (tr[x]+=v)%=mod;
            x+=lb(x);
        }
    }
    inline int query (int x) {
        int res=0;
        while (x) {
            (res+=tr[x])%=mod;
            x-=lb(x);
        }
        return res;
    }
    inline int query (int l,int r) {return query(r)-query(l-1);}
}bit;
signed main() {
    Cios;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    stack<int> s;
    for (int i=1;i<=n+1;i++) {
        while (s.size()&&a[s.top()]>a[i]) r[s.top()]=i-1,s.pop();
        s.push(i);
    }
    while (s.size()) s.pop();
    for (int i=n;i>=0;i--) {
        while (s.size()&&a[s.top()]>a[i]) l[s.top()]=i+1,s.pop();
        s.push(i);
    }
    bit.update(1,1);
    for (int i=1;i<=n;i++) {
        f[i]=(bit.query(l[i],n)%mod+mod)%mod;
        bit.update(r[i],f[i]);
    }
    int res=0,mi=(1ll<<60);
    for (int i=n;i>=1;i--) mi=min(mi,a[i]),(res+=((int)(mi==a[i]))*f[i])%=mod;
    cout<<res<<"\n";
    return 0;
}