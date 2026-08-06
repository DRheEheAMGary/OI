/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e5+10;
class DynamicSegmentTree {
    struct treeNode {
        int lc,rc,sum;
        treeNode () =default;
        
    }tr[N*20];
    #define lc(p) (tr[(p)].lc)
    #define rc(p) (tr[(p)].rc)
    int rt[N],cnt;
    void pushup (int p) {tr[p].sum=tr[lc(p)].sum+tr[rc(p)].sum;}
    void update (int &p,int pre,int l,int r,int q) {
        p=++cnt;
        tr[p]=tr[pre];
        tr[p].sum++;
        if (l==r) return;
        int mid=(l+r)>>1;
        if (q<=mid) update (tr[p].lc,tr[pre].lc,l,mid,q);
        else update (tr[p].rc,tr[pre].rc,mid+1,r,q);
        pushup(p);
    }
    int query (int p,int q,int l,int r,int k) {
        if (l==r) return l;
        int mid=(l+r)>>1;
        int s=tr[tr[p].lc].sum-tr[tr[q].lc].sum;
        if (s>=k) return query(tr[p].lc,tr[q].lc,l,mid,k);
        else return query(tr[p].rc,tr[q].rc,mid+1,r,k-s);
    }
}dst;
signed main() {
    Cios;
    return 0;
}