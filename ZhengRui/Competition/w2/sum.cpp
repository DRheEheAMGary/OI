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
intc N=2e5+10,inf=1<<30,mod=998244353;
int n,a[N];
class SegmentTree {
    struct node {
        int l,r,min,max;
    }tr[N<<2];
    #define lc(p) ((p)<<1)
    #define rc(p) ((p)<<1|1)
    inline void pushup (int p) {
        tr[p].max=max(tr[lc(p)].max,tr[rc(p)].max);
        tr[p].min=min(tr[lc(p)].min,tr[rc(p)].min);
    }
    public:
    void build (int p=1,int l=1,int r=n) {
        tr[p]={l,r,0,0};
        if (l==r) return tr[p]={l,r,a[l],a[l]},void();
        int mid=(l+r)>>1;
        build(lc(p),l,mid);
        build(rc(p),mid+1,r);
        pushup(p);
    }
    int querymin (int ql,int qr,int p=1,int l=1,int r=n) {
        if (l<=ql&&qr<=r) return tr[p].min;
        int mid=(l+r)>>1,res=inf;
        if (ql<=mid) res=min(res,querymin(ql,qr,lc(p),l,mid));
        if (qr> mid) res=min(res,querymin(ql,qr,rc(p),mid+1,r));
        return res;
    }
    int querymax (int ql,int qr,int p=1,int l=1,int r=n) {
        if (l<=ql&&qr<=r) return tr[p].max;
        int mid=(l+r)>>1,res=0;
        if (ql<=mid) res=max(res,querymax(ql,qr,lc(p),l,mid));
        if (qr> mid) res=max(res,querymax(ql,qr,rc(p),mid+1,r));
        return res;
    }
}st;
signed main() {
    Cios;
    int c,T;
    cin>>c>>T;
    while (T--) {
        cin>>n;
        for (int i=1;i<=n;i++) cin>>a[i];
        st.build();
        int res[5]={0,0,0,0,0};
        for (int l=1;l<=n;l++) {
            for (int r=l;r<=n;r++) {
                int mina=st.querymin(l, r);
                int maxa=st.querymax(l, r);
                res[0]+=mina+maxa;
                res[1]+=mina-maxa;
                res[2]+=mina*maxa;
                res[3]+=mina/maxa;
                res[4]+=mina%maxa;
                for (int i=0;i<=4;i++) res[i]=(res[i]%mod+mod)%mod;
            }
        }
        for (int i=0;i<=4;i++) cout<<res[i]<<" ";
        cout<<"\n";
    }
    return 0;
}

/*
clang++ -g sum.cpp -o sum -std=c++14 -O2 -Wall
*/