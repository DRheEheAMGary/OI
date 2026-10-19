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
int n,m;
struct segment {
    int l,r,h;
    bool operator < (const segment &p) const {return h<p.h;}
}s[N];
int p[N];
int maxr;
class segmentTree {
    struct node {
        int l,r,sum,lz;
        void tag (int k) {
            (sum=k*(r-l+1))%=mod;
            lz=k;
        }
    }tr[N<<2];
    inline int lc (int p) {return p<<1;}
    inline int rc (int p) {return p<<1|1;}
    inline node& lct (int p) {return tr[lc(p)];}
    inline node& rct (int p) {return tr[rc(p)];}
    void pushup (int p) {
        (tr[p].sum=lct(p).sum+rct(p).sum)%=mod;
    }
    void pushdown (int p) {
        if (tr[p].lz) {
            lct(p).tag(tr[p].lz);
            rct(p).tag(tr[p].lz);
        }
        tr[p].lz=0;
    }
    public:
    void build (int p=1,int l=0,int r=maxr) {
        tr[p]={l,r,0,0};
        if (l==r) {
            tr[p].sum=1;
            return;
        }
        int mid=(l+r)>>1;
        build(lc(p),l,mid);
        build(rc(p),mid+1,r);
        pushup(p);
    }
    void update (int ql,int qr,int val,int p=1,int l=0,int r=maxr) {
        if (ql<=l&&r<=qr) {
            tr[p].tag(val);
            return;
        }
        int mid=(l+r)>>1;
        pushdown(p);
        if (ql<=mid) update(ql,qr,val,lc(p),l,mid);
        if (qr> mid) update(ql,qr,val,rc(p),mid+1,r);
        pushup(p);
    }
    int query (int q,int p=1,int l=0,int r=maxr) {
        if (l==r) return tr[p].sum;
        int mid=(l+r)>>1;
        pushdown(p);
        if (q<=mid) return query(q,lc(p),l,mid);
        else return query(q,rc(p),mid+1,r);
    }
}seg;
signed main() {
    Cios;
    cin>>n>>m;
    for (int i=1;i<=m;i++) cin>>s[i].l>>s[i].r>>s[i].h,maxr=max(maxr,s[i].r);
    for (int i=1;i<=n;i++) cin>>p[i];
    sort(s+1,s+1+m);
    seg.build();
    for (int i=1;i<=m;i++) seg.update(s[i].l,s[i].r,seg.query(s[i].l)+seg.query(s[i].r));
    int res=0;
    for (int i=1;i<=n;i++) (res+=seg.query(p[i]))%=mod;
    cout<<res<<"\n";
    return 0;
}

/*
g++ -g mainf.cpp -o mainf.exe -std=c++14 -O2 -static; echo "finish"; .\mainf.exe
*/