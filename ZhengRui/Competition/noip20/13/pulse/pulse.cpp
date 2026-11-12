/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e5+10;
constexpr intl inf=1ll<<60;
int n,q;
int fv[N];
intl fx[N];
class SegmentTree {
    struct STnode {
        int cnt;
        intl wl,wr;
        int vl,vr;
        intl mpm,mmp;
        intl lzc;
        int lzs;
        void apply (intl c,int s) {
            wl+=vl*c;
            vl*=s;
            wr+=c*vr;
            vr*=s;
            if (mpm<inf/2) mpm-=2*c;
            if (mmp<inf/2) mmp+=2*c;
            if (s==-1) swap(mpm,mmp);
            lzc+=lzs*c;
            lzs*=s;
        }
    }tr[N<<2];
    inline int lc (int p) {return p<<1;}
    inline int rc (int p) {return p<<1|1;}
    inline auto& lct (int p) {return tr[lc(p)];}
    inline auto& rct (int p) {return tr[rc(p)];}
    inline void pushdown (int p) {
        if (tr[p].lzc!=0||tr[p].lzs!=1) {
            intl &c=tr[p].lzc;
            int &s=tr[p].lzs;
            if (lct(p).cnt) lct(p).apply(c,s);
            if (rct(p).cnt) rct(p).apply(c,s);
            c=0;
            s=1;
        }
    }
    inline void pushup (int p) {
        auto &t=tr[p];
        auto &tl=lct(p),&tr=rct(p);
        t.cnt=tl.cnt+tr.cnt;
        if (!tl.cnt) {
            t.wl=tr.wl;
            t.vl=tr.vl;
            t.wr=tr.wr;
            t.vr=tr.vr;
            t.mpm=tr.mpm;
            t.mmp=tr.mmp;
            return ;
        }
        if (!tr.cnt) {
            t.wl=tl.wl;
            t.vl=tl.vl;
            t.wr=tl.wr;
            t.vr=tl.vr;
            t.mpm=tl.mpm;
            t.mmp=tl.mmp;
            return ;
        }
        t.wl=tl.wl,t.vl=tl.vl;
        t.wr=tr.wr,t.vr=tr.vr;
        t.mpm=min(tl.mpm,tr.mpm);
        t.mmp=min(tl.mmp,tr.mmp);
        intl diff=tr.wl-tl.wr;
        if (tl.vr==1&&tr.vl==-1) t.mpm=min(t.mpm,diff);
        else if (tl.vr==-1&&tr.vl==1) t.mmp=min(t.mmp,diff);
    }
    public:
    inline void build (int p=1,int l=1,int r=n) {
        if (l==r) return tr[p]={1,fx[l],fx[l],fv[l],fv[l],inf,inf,0,1},void();
        tr[p].lzc=0;
        tr[p].lzs=1;
        int mid=(l+r)>>1;
        build (lc(p),l,mid);
        build (rc(p),mid+1,r);
        pushup(p);
    }
    inline void ModifyRange (int p,int l,int r,intl ql,intl qr,intl q) {
        if (!tr[p].cnt) return;
        intl pmin=tr[p].wl+tr[p].vl*q,pmax=tr[p].wr+tr[p].vr*q;
        if (pmax<ql||pmin>qr) return;
        if (ql<=pmin&&pmax<=qr) return tr[p].apply(2*q,-1);
        pushdown(p);
        int mid=(l+r)>>1;
        ModifyRange(lc(p),l,mid,ql,qr,q);
        ModifyRange(rc(p),mid+1,r,ql,qr,q);
        pushup(p);
    }
    inline void EraseK (int p,int l,int r,int k) {
        if (l==r) {
            tr[p].cnt=0;
            tr[p].mmp=tr[p].mpm=inf;
            return;
        }
        pushdown(p);
        int mid=(l+r)>>1;
        if (k<=lct(p).cnt) EraseK(lc(p),l,mid,k);
        else EraseK(rc(p),mid+1,r,k-lct(p).cnt);
        pushup(p);
    }
    inline int Query (int p,int l,int r) {
        pushdown(p);
        auto &lct=SegmentTree::lct(p),&rct=SegmentTree::rct(p);
        int mid=(l+r)>>1;
        if (lct.cnt&&lct.mpm==tr[p].mpm) return Query(lc(p),l,mid);
        if (lct.cnt&&rct.cnt) {
            intl diff=rct.wl-lct.wr;
            if (lct.vr==1&&rct.vl==-1&&diff==tr[p].mpm) return lct.cnt;
        }
        return lct.cnt+Query(rc(p),mid+1,r);
    }
    inline bool QueryRoot (intl cur) {return tr[1].cnt>=2&&tr[1].mpm<=2*cur;}
    inline int GetAnswer () {return tr[1].cnt;}
}seg;
signed main() {
    Cios;
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>fx[i]>>fv[i];
    seg.build(1,1,n);
    intl cur=0;
    while (q--) {
        int l,r,d;
        cin>>l>>r>>d;
        seg.ModifyRange(1,1,n,l,r,cur);
        cur+=d;
        while (seg.QueryRoot(cur)) {
            int pos=seg.Query(1,1,n);
            seg.EraseK(1,1,n,pos+1);
            seg.EraseK(1,1,n,pos);
        }
        cout<<seg.GetAnswer()<<"\n";
    }
    return 0;
}