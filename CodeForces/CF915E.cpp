/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1.5e7;
class DynamicSegmentTree {
    struct treenode {
        int lc,rc,sum,lz;
        void tag (int l,int r,int dta) {
            sum=dta*(r-l+1);
            lz=dta;
        }
    }tr[N];
    int n,cnt,rt;
    inline int& lc (int p) {return tr[p].lc;}
    inline int& rc (int p) {return tr[p].rc;}
    int newnode () {
        tr[++cnt]={0,0,0,-1};
        return cnt;
    }
    void pushup (int p) {
        tr[p].sum=tr[lc(p)].sum+tr[rc(p)].sum;
    }
    void pushdown (int l,int r,int p) {
        if (~tr[p].lz) {
            int mid=(l+r)>>1;
            if (!lc(p)) lc(p)=newnode();
            if (!rc(p)) rc(p)=newnode();
            tr[lc(p)].tag(l,mid,tr[p].lz);
            tr[rc(p)].tag(mid+1,r,tr[p].lz);
        }
        tr[p].lz=-1;
    }
    void update (int ul,int ur,int &p,int l,int r,int v) {
        if (!p) p=newnode();
        if (ul<=l&&r<=ur) {
            tr[p].tag(l,r,v);
            return;
        }
        pushdown(l,r,p);
        int mid=(l+r)>>1;
        if (mid>=ul) update(ul,ur,lc(p),l,mid,v);
        if (mid< ur) update(ul,ur,rc(p),mid+1,r,v);
        pushup(p);
    }
    public:
    void Init (int _n) {
        n=_n;
        cnt=0;
        rt=newnode();
    }
    void Update (int l,int r,int v) {
        update(l,r,rt,1,n,v);
    }
    int Query () {return tr[rt].sum;}
}dst;
int n,q;
signed main() {
    Cios;
    cin>>n;
    dst.Init(n);
    cin>>q;
    while (q--) {
        int l,r,k;
        cin>>l>>r>>k;
        dst.Update(l,r,k%2);
        cout<<n-dst.Query()<<"\n";
    }
    return 0;
}