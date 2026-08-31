/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=5e4+10,inf=(1ll<<30);
int n,m,qcnt,minv=inf,maxv=-inf,res[N];
struct node {
    int x,y,k,idx,op;
}q[N<<1],q1[N<<1],q2[N<<1];
struct SegmentTree {
    struct node {
        int sum,lz;
    }tr[N<<2];
    inline int lc (int p) {return (p<<1);}
    inline int rc (int p) {return (p<<1|1);}
    inline void pushup (int p) {
        tr[p].sum=tr[lc(p)].sum+tr[rc(p)].sum;
    }
    inline void pushdown (int p,int l,int r) {
        if (tr[p].lz) {
            int lc_=lc(p),rc_=rc(p);
            int k=tr[p].lz;
            int mid=(l+r)>>1;
            tr[lc_].sum+=(mid-l+1)*k;
            tr[rc_].sum+=(r-mid)*k;
            tr[lc_].lz+=k;
            tr[rc_].lz+=k;
        }
        tr[p].lz=0;
    }
    void Update (int ql,int qr,int w,int p=1,int l=1,int r=n) {
        if (ql<=l&&r<=qr) {
            tr[p].sum+=w*(r-l+1);
            tr[p].lz+=w;
            return;
        }
        int mid=(l+r)>>1;
        pushdown(p,l,r);
        if (ql<=mid) Update (ql,qr,w,lc(p),l,mid);
        if (qr> mid) Update (ql,qr,w,rc(p),mid+1,r);
        pushup(p);
    }
    int Query (int ql,int qr,int p=1,int l=1,int r=n) {
        if (ql<=l&&r<=qr) return tr[p].sum;
        int mid=(l+r)>>1;
        pushdown(p,l,r);
        int res=0;
        if (ql<=mid) res+=Query(ql,qr,lc(p),l,mid);
        if (qr> mid) res+=Query(ql,qr,rc(p),mid+1,r);
        return res;
    }
}st;
void Solve (int vl,int vr,int ql,int qr) {
    if (ql>qr) return;
    if (vl==vr) {
        for (int i=ql;i<=qr;i++) {
            if (q[i].op) res[q[i].idx]=vl;
        }
        return;
    }
    int mid=(vl+vr)>>1;
    int cnt1=0,cnt2=0;
    for (int i=ql;i<=qr;i++) {
        if (q[i].op) {
            int sum=st.Query(q[i].x,q[i].y);
            if (sum>=q[i].k) q2[++cnt2]=q[i];
            else q[i].k-=sum,q1[++cnt1]=q[i];
        }
        else {
            if (q[i].k>mid) st.Update(q[i].x, q[i].y, 1),q2[++cnt2]=q[i];
            else q1[++cnt1]=q[i];
        }
    }
    for (int i=1;i<=cnt2;i++) {
        if (!q2[i].op) st.Update(q2[i].x,q2[i].y,-1);
    }
    for (int i=1;i<=cnt1;i++) q[i+ql-1]=q1[i];
    for (int i=1;i<=cnt2;i++) q[i+ql+cnt1-1]=q2[i];
    Solve(vl,mid,ql,ql+cnt1-1);
    Solve(mid+1,vr,ql+cnt1,qr);
}
signed main() {
    Cios;
    cin>>n>>m;
    int qr=0;
    for (int i=1;i<=m;i++) {
        int op,l,r,k;
        cin>>op>>l>>r>>k;
        q[++qcnt]={l,r,k,i,op-1};
        if (op==2) q[qcnt].idx=++qr;
        if (op==1) minv=min(minv,k),maxv=max(maxv,k);
    }
    Solve(minv,maxv,1,qcnt);
    for (int i=1;i<=qr;i++) cout<<res[i]<<"\n";
    return 0;
}