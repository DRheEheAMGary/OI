/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=5e4+10,B=2.4e2+10;
int n,m,size,pos[N];
struct question {
    int idx,l,r;
    pair<int,int> ans={0,0};
    inline static bool cmp (question a,question b) {
        if (pos[a.l]==pos[b.l]) {
            if (pos[a.l]%2==0) return a.r>b.r;
            else return a.r<b.r;
        }
        return pos[a.l]<pos[b.l];
    }
    inline static bool cmp_idx (question a,question b) {
        return a.idx<b.idx;
    }
}q[N];
struct answer {
    int cnt[N]={};
    int r=0;
    inline void add (int col) {
        r+=cnt[col]*2+1;
        cnt[col]++;
    }
    inline void del (int col) {
        r+=-cnt[col]*2+1;
        cnt[col]--;
    }
}res;
int a[N];
int gcd (int a,int b) {
    return b?gcd(b,a%b):a;
}
signed main(){
    Cios;
    cin>>n>>m;
    size=sqrt(n*2.0/3);
    for (int i=1;i<=n;i++) {
        pos[i]=(i-1)/size+1;
        cin>>a[i];
    }
    for (int i=1;i<=m;i++) {
        cin>>q[i].l>>q[i].r;
        q[i].idx=i;
    }
    sort(q+1,q+1+m,question::cmp);
    for (int i=1,l=1,r=0;i<=m;i++) {
        while (r<q[i].r) res.add(a[++r]);
        while (r>q[i].r) res.del(a[r--]);
        while (l<q[i].l) res.del(a[l++]);
        while (l>q[i].l) res.add(a[--l]);
        if (l==r) {
            q[i].ans={0,1};
            continue;
        }
        q[i].ans.first =res.r-(r-l+1);
        q[i].ans.second=(r-l+1)*(r-l);
        int _gcd=gcd(q[i].ans.first,q[i].ans.second);
        q[i].ans.first/=_gcd;
        q[i].ans.second/=_gcd;
    }
    sort(q+1,q+1+m,question::cmp_idx);
    for (int i=1;i<=m;i++) cout<<q[i].ans.first<<"/"<<q[i].ans.second<<"\n";
    return 0;
}