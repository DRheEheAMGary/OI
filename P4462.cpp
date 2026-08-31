/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e5+10;
int n,m,k,sz,a[N];
struct ques {
    int idx,l,r,res;
}q[N];
struct answ {
    int res=0;
    int cnt[N]={1};
    void add (int p) {
        res+=cnt[p^k];
        cnt[p]++;
    }
    void del (int p) {
        cnt[p]--;
        res-=cnt[p^k];
    }
}res;
int pos (int p) {return (p-1)/sz+1;}
signed main() {
    Cios;
    cin>>n>>m>>k;
    sz=pow(n,2.0/3);
    for (int i=1;i<=n;i++) cin>>a[i],a[i]^=a[i-1];
    for (int i=1;i<=m;i++) {
        int l,r;
        cin>>l>>r;
        q[i]={i,l,r,0};
    }
    sort (q+1,q+1+m,
        [&] (ques a,ques b) {
            if (pos(a.l)!=pos(b.l)) return pos(a.l)<pos(b.l);
            if (pos(a.l)%2==0) return a.r>b.r;
            else return a.r<b.r;
        }
    );
    for (int i=1,l=0,r=0;i<=m;i++) {
        while (l<q[i].l-1) res.del(a[l++]);
        while (l>q[i].l-1) res.add(a[--l]);
        while (r<q[i].r) res.add(a[++r]);
        while (r>q[i].r) res.del(a[r--]);
        q[i].res=res.res;
    } 
    sort (q+1,q+1+m,[&] (ques a,ques b) {return a.idx<b.idx;});
    for (int i=1;i<=m;i++) cout<<q[i].res<<"\n";
    return 0;
}