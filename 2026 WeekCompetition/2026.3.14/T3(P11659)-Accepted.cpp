/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=4e5+10;
int n,m,size,a[N];
struct ques {
    int idx,l,r,res;
}q[N];
struct answ {
    int sum;
    int sum2[N],sum3[N],sum4[N],suml[N],sumr[N];
    void updl (int p,int v) {
        if (p%2==0) sumr[p/2]+=sum3[p/2]*v,sum2[p/2]+=v;
        if (p%3==0) sum3[p/3]+=v;
        if (p%4==0) sum+=sumr[p/4]*v,suml[p/4]+=sum2[p/4]*v,sum4[p/4]+=v;
    }
    void updr (int p,int v) {
        if (p%2==0) suml[p/2]+=sum4[p/2]*v,sum2[p/2]+=v;
        if (p%3==0) sum+=suml[p/3]*v,sumr[p/3]+=sum2[p/3]*v,sum3[p/3]+=v;
        if (p%4==0) sum4[p/4]+=v;
    }
}res;
int pos (int p) {return (p-1)/size+1;}
signed main(){
    Cios;
    cin>>n>>m;
    size=sqrt(n);
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++) {
        int l,r;
        cin>>l>>r;
        q[i]={i,l,r,0};
    }
    sort (q+1,q+1+m,
        [&] (ques a,ques b) {
            if (pos(a.l)!=pos(b.l)) return pos(a.l)<pos(b.l);
            if (a.r!=b.r) {
                if (pos(a.l)%2==0) return a.r>b.r;
                return a.r<b.r;
            }
            return a.idx<b.idx;
        }
    );
    for (int i=1,l=1,r=0;i<=m;i++) {
        while (l<q[i].l) res.updl(a[l++],-1);
        while (l>q[i].l) res.updl(a[--l],1);
        while (r<q[i].r) res.updr(a[++r],1);
        while (r>q[i].r) res.updr(a[r--],-1);
        q[i].res=res.sum;
    }
    sort (q+1,q+1+m,
        [&] (ques a,ques b) {
            return a.idx<b.idx;
        }
    );
    for (int i=1;i<=m;i++) cout<<q[i].res<<"\n";
    return 0;
}