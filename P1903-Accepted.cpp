/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e6+10;
int n,m,k,sz;
struct ques {
    int idx,l,r,t,ans;
}q[N];
struct chag {
    int p,c;
}p[N];
int a[N];
int qcnt,pcnt;
struct answ {
    int sum,cnt[N];
    void add (int p) {
        cnt[p]++;
        if (cnt[p]==1) sum++;
    }
    void del (int p) {
        if (cnt[p]==1) sum--;
        cnt[p]--;
    }
}res;
int pos (int p) {return (p-1)/sz+1;}
signed main(){
    Cios;
    cin>>n>>m;
    sz=pow(n,2.0/3);
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++) {
        char op;
        int l,r;
        cin>>op>>l>>r;
        if (op=='Q') q[++qcnt]={qcnt,l,r,pcnt,-1};
        else p[++pcnt]={l,r};
    }
    sort (q+1,q+1+qcnt,
        [&] (ques a,ques b) {
            if (pos(a.l)!=pos(b.l)) return a.l<b.l;
            if (pos(a.r)!=pos(b.r)) return a.r<b.r;
            return a.t<b.t;
        }
    );
    for (int i=1,l=1,r=0,t=0;i<=qcnt;i++) {
        while (l>q[i].l) res.add(a[--l]);
        while (l<q[i].l) res.del(a[l++]);
        while (r>q[i].r) res.del(a[r--]);
        while (r<q[i].r) res.add(a[++r]);
        while (t<q[i].t) {
            int tmp=p[++t].p;
            if (l<=tmp&&tmp<=r) {
                res.del(a[tmp]);
                res.add(p[t].c);
            }
            swap(a[tmp],p[t].c);
        }
        while (t>q[i].t) {
            int tmp=p[t].p;
            if (l<=tmp&&tmp<=r) {
                res.del(a[tmp]);
                res.add(p[t].c);
            }
            swap(a[tmp],p[t--].c);
        }
        q[i].ans=res.sum;
    }
    sort (q+1,q+1+qcnt,
        [&] (ques a,ques b) {
            return a.idx<b.idx;
        }
    );
    for (int i=1;i<=qcnt;i++) cout<<q[i].ans<<"\n";
    return 0;
}