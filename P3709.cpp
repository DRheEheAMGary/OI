/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(a) a.begin(),a.end()
intc N=2e5+10;
int n,m,sz,a[N];
vector <int> disc;
struct ques {
    int idx,l,r,res;
}q[N];
struct answ {
    int res;
    int cnt[N],tot[N];
    void add (int p) {
        tot[cnt[p]]--;
        tot[++cnt[p]]++;
        res=max(res,cnt[p]);
    }
    void del (int p) {
        tot[cnt[p]]--;
        if (cnt[p]==res&&tot[cnt[p]]==0) res--;
        tot[--cnt[p]]++;
    }
}res;
int pos (int p) {return (p-1)/sz+1;}
signed main() {
    Cios;
    cin>>n>>m;
    sz=pow(n,2.0/3);
    for (int i=1;i<=n;i++) cin>>a[i],disc.push_back(a[i]);
    sort(all(disc));
    disc.erase(unique(all(disc)),disc.end());
    for (int i=1;i<=n;i++) a[i]=lower_bound(all(disc),a[i])-disc.begin();
    for (int i=1;i<=m;i++) {
        int l,r;
        cin>>l>>r;
        q[i]={i,l,r,0};
    }
    sort (q+1,q+1+m,
        [&] (ques a,ques b) {
            if (pos(a.l)!=pos(b.l)) return pos(a.l)<pos(b.l);
            if (pos(a.l)%2==0) return a.r>b.r;
            return a.r<b.r;
        }
    );
    for (int i=1,l=1,r=0;i<=m;i++) {
        while (l<q[i].l) res.del(a[l++]);
        while (l>q[i].l) res.add(a[--l]);
        while (r<q[i].r) res.add(a[++r]);
        while (r>q[i].r) res.del(a[r--]);
        q[i].res=res.res;
    }
    sort (q+1,q+1+m,[&] (ques a,ques b) {return a.idx<b.idx;});
    for (int i=1;i<=m;i++) cout<<-q[i].res<<"\n";
    return 0;
}