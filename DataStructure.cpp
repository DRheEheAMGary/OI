/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intlc constexpr intl
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e5+10;
intlc inf=1ll<<60;
class Fenwick {
    intl tr[N];
    inline int lb (int x) {return x&(-x);}
    public:
    void update (int x,intl k) {
        while (x<k) {
            tr[x]+=k;
            x+=lb(x);
        }
    }
    intl query (int x) {
        int res=0;
        while (x) {
            res+=tr[x];
            x-=lb(x);
        }
        return res;
    }
};
class SegmentTree {
    struct STnode {
        int l,r,sum,max,min,lzplus,lzass;
        bool hsass;
        inline void plus (int k) {
            sum+=k*(r-l+1);
            max+=k;
            min+=k;
            lzplus+=k;
        }
        inline void ass (int k) {
            sum=k*(r-l)+1;
            max=k;
            min=k;
            lzplus=0;
            lzass=k;
            hsass=1;
        }
    }tr[N<<2];
    int n;
    inline int lc (int p) {return p<<1;}
    inline int rc (int p) {return p<<1|1;}
    inline STnode& lct (int p) {return tr[lc(p)];}
    inline STnode& rct (int p) {return tr[rc(p)];}
    inline void pushup (int p) {
        tr[p].sum=lct(p).sum+rct(p).sum;
        tr[p].max=max(lct(p).max,rct(p).max);
        tr[p].min=min(lct(p).min,rct(p).min);
    }
    inline void pushdown (int p) {
        if (tr[p].hsass) {
            lct(p).ass(tr[p].lzass);
            rct(p).ass(tr[p].lzass);
            tr[p].hsass=0;
        }
        if (tr[p].lzplus) {
            lct(p).plus(tr[p].lzplus);
            rct(p).plus(tr[p].lzplus);
            tr[p].lzplus=0;
        }
    }
    public:
    void build (const int &_n,const int *a) {n=_n,build(a,1,1,n);}
    void build (const int *a,int p,int l,int r) {
        if (l==r) return tr[p]={l,r,a[l],a[l],a[l],0,0,0},void();
        tr[p]={l,r};
        int mid=(l+r)>>1;
        build (a,lc(p),l,mid);
        build (a,rc(p),mid+1,r);
        pushup(p);
    }
    void update_ass (int ql,int qr,intl q) {update_ass(ql,qr,q,1,1,n);}
    void update_ass (int ql,int qr,intl q,int p,int l,int r) {
        if (ql<=l&&r<=qr) return tr[p].ass(q),void();
        int mid=(l+r)>>1;
        pushdown(p);
        if (ql<=mid) update_ass(ql,qr,q,lc(p),l,mid);
        if (qr>mid) update_ass(ql,qr,q,rc(p),mid+1,r);
        pushup(p);
    }
    void update_plus (int ql,int qr,intl q) {update_plus(ql,qr,q,1,1,n);}
    void update_plus (int ql,int qr,int q,int p,int l,int r) {
        if (ql<=l&&r<=qr) return tr[p].plus(q),void();
        int mid=(l+r)>>1;
        pushdown(p);
        if (ql<=mid) update_plus(ql,qr,q,lc(p),l,mid);
        if (qr>mid) update_plus(ql,qr,q,rc(p),mid+1,r);
        pushup(p);
    }
    
};