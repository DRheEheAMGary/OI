/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e5+10;
int n,m,sz,a[N],pos[N];
struct ques {
    int l,r,a,b,idx,res,resc;
    ques () =default;
    ques (int l_,int r_,int a_,int b_,int idx_,int res_=0,int resc_=0) :l(l_),r(r_),a(a_),b(b_),idx(idx_),res(res_),resc(resc_) {}
}q[N];
struct Fenwick {
    int tr[N];
    inline int lb (int p) {return p&(-p);}
    inline void Update (int p,int w) {
        while (p<N) {
            tr[p]+=w;
            p+=lb(p);
        }
    }
    inline int Query (int p) {
        int res=0;
        while (p) {
            res+=tr[p];
            p-=lb(p);
        }
        return res;
    }
    inline int QueryInterval (int l,int r) {
        return Query(r)-Query(l-1);
    }
}bit,bitc;
struct answ {
    int cnt[N];
    void add (int p) {
        cnt[p]++;
        if (cnt[p]==1) bitc.Update(p,1);
        bit.Update(p,1);
    }
    void del (int p) {
        if (cnt[p]==1) bitc.Update(p,-1);
        cnt[p]--;
        bit.Update(p,-1);
    }
}res;
signed main() {
    Cios;
    cin>>n>>m;
    sz=sqrt(n);
    for (int i=1;i<=n;i++) cin>>a[i],pos[i]=(i-1)/sz+1;
    for (int i=1;i<=m;i++) {
        int l,r,a,b;
        cin>>l>>r>>a>>b;
        q[i]=ques(l,r,a,b,i);
    }
    sort (q+1,q+1+m,
        [&] (ques a,ques b) {
            if (pos[a.l]!=pos[b.l]) return pos[a.l]<pos[b.l];
            if (pos[a.l]%2==0) return a.r>b.r;
            return a.r<b.r;
        }
    );
    for (int i=1,l=1,r=0;i<=m;i++) {
        while (l>q[i].l) res.add(a[--l]);
        while (r<q[i].r) res.add(a[++r]);
        while (l<q[i].l) res.del(a[l++]);
        while (r>q[i].r) res.del(a[r--]);
        q[i].res=bit.QueryInterval(q[i].a,q[i].b);
        q[i].resc=bitc.QueryInterval(q[i].a,q[i].b);
    }
    sort (q+1,q+1+m,[&](ques a,ques b) {return a.idx<b.idx;});
    for (int i=1;i<=m;i++) cout<<q[i].res<<" "<<q[i].resc<<"\n";
    return 0;
}