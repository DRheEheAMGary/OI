/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e5+10;
int n,m,size,a[N];
struct question {
    int idx,l,r,ans;
}q[N];
struct answer {
    int cnt[N],r;
    void add (int p) {
        cnt[p]++;
        if (cnt[p]==2) r++;
    }
    void del (int p) {
        if (cnt[p]==2) r--;
        cnt[p]--;
    }
}res;
int Pos (int p) {return (p-1)/size+1;}
signed main(){
    Cios;
    cin>>n>>m;
    size=sqrt(n);
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++) {
        int l,r;
        cin>>l>>r;
        q[i]={i,l,r,-1};
    }
    sort (q+1,q+1+m,
        [&] (question a,question b) {
            if (Pos(a.l)==Pos(b.l)) {
                if (Pos(a.l)%2==0) return a.r>b.r;
                else return a.r<b.r;
            }
            return Pos(a.l)<Pos(b.l);
        }
    );
    for (int i=1,l=1,r=0;i<=m;i++) {
        while (l>q[i].l) res.add(a[--l]);
        while (r<q[i].r) res.add(a[++r]);
        while (l<q[i].l) res.del(a[l++]);
        while (r>q[i].r) res.del(a[r--]);
        q[i].ans=!res.r;
    }
    sort (q+1,q+1+m,
        [&] (question a,question b) {
            return a.idx<b.idx;
        }
    );
    for (int i=1;i<=m;i++) cout<<(q[i].ans?"Yes\n":"No\n");
    return 0;
}