/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=6e5+10;
int n,q;
int nw=0;
int c[N];
struct Fenwick {
    int tr[N];
    inline int lb (int x) {return x&(-x);}
    int query (int x) {
        if (x<=0) return 0;
        int res=0;
        while (x) {
            res+=tr[x];
            x-=lb(x);
        }
        return res;
    }
    void update (int x,int v) {
        while (x<N) {
            tr[x]+=v;
            x+=lb(x); 
        }
    }
}bit;
signed main() {
    Cios;
    cin>>n>>q;
    bit.update(1,n);
    for (int i=1;i<=n;i++) {
        c[i]=1;
    }
    while (q--) {
        int op,x;
        cin>>op>>x;
        if (op==1) {
            bit.update(c[x],-1);
            bit.update(++c[x],1);
            if (bit.query(nw+1)==0) nw++;
        }
        else cout<<n-(bit.query(x+nw))<<"\n";
    }
    return 0;
}