/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=5e5+10,mod=998244353;
inline int& add (int& a,int b) {
    a+=b;
    if (a>=mod) a-=mod;
    return a;
}
inline int& sub (int& a,int b) {
    a-=b;
    if (a<0) a+=mod;
    return a;
}
class Fenwick {
    int tr[N];
    inline int lb (int x) {return x&(-x);}
    public:
    inline void update (int p,int v) {
        p++;
        while (p<N) {
            add(tr[p],v);
            p+=lb(p);
        }
    }
    inline int query (int p) {
        p++;
        if (p<1) return 0;
        int res=0;
        while (p) {
            add(res,tr[p]);
            p-=lb(p);
        }
        return res;
    }
    inline int query (int l,int r) {
        if (l>r) return 0;
        return ((query(r)-query(l-1))%mod+mod)%mod;
    }
}bit[2];
int n,q[N],p[N],f[N];
string s;
vector <pair <int,int>> dll[N<<1];
signed main() {
    Cios;
    cin>>n;
    cin>>s;s=" "+s;
    int lsl=0;
    for (int i=1;i<=n;i++) q[i]=lsl,lsl=(s[i]=='L'?i:lsl);
    int lsr=n+1;
    for (int i=n;i>=1;i--) p[i]=lsr,lsr=(s[i]=='R'?i:lsr);
    for (int j=1;j<=n;j++) {
        for (auto itm:dll[j]) bit[itm.first&1].update(itm.first,(mod-itm.second)%mod);
        int curr=0;
        if (q[j]==0) curr=1;
        int mins=max(1ll,2*q[j]-j);
        if (mins<=j-1) add(curr,bit[j&1].query(mins,j-1));
        int mind=max(1ll,2*q[j]-j+1);
        if (mind<=j-1) add(curr,bit[(j&1)^1].query(mind,j-1));
        f[j]=curr;
        int mul=(s[j]=='?')+1;
        int val=f[j]*mul%mod;
        bit[j&1].update(j,val);
        int deli=2*p[j]-j;
        if (deli<=2*n+2) dll[deli].push_back({j,val});
    }
    int res=0;
    for (int i=1;i<=n;i++) {
        if (p[i]>n) add(res,f[i]*((s[i]=='?')+1)%mod);
    }
    cout<<res<<"\n";
    return 0;
}

/*
g++ -g shugenja2.cpp -o shugenja.exe -O2 -std=c++14 -static ; .\shugenja.exe

3
L??

5
?LR??
*/