/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=3e5+10;
#ifdef CLANGD_
#define N 10
#endif
int n,q;
struct Log {
    int t,b;
}li[N];
struct Query {
    int r,id;
};
vector <Query> qu;
int res[N];
class segmentTree {
    struct node {
        int mx,lz;
        inline void tag (int k) {mx+=k,lz+=k;}
    }tr[N<<2];
    inline int lc (int p) {return p<<1;}
    inline int rc (int p) {return p<<1|1;}
    inline void pushup (int p) {
        tr[p].mx=max(tr[lc(p)].mx,tr[rc(p)].mx);
    }
    inline void pushdown (int p) {
        if (tr[p].lz) {
            tr[lc(p)].tag(tr[p].lz);
            tr[rc(p)].tag(tr[p].lz);
        }
        tr[p].lz=0;
    }
    public:
    inline void update (int ql,int qr,int val,int l=1,int r=n,int p=1) {
        if (ql<=l&&r<=qr) {
            tr[p].tag(val);
            return;
        }
        int mid=(l+r)>>1;
        pushdown(p);
        if (ql<=mid) update(ql,qr,val,l,mid,lc(p));
        if (qr> mid) update(ql,qr,val,mid+1,r,rc(p));
        pushup(p);
    }
    inline int query (int ql,int qr,int l=1,int r=n,int p=1) {
        if (ql<=l&&r<=qr) return tr[p].mx;
        int mid=(l+r)>>1,res=0;
        pushdown(p);
        if (ql<=mid) res+=query(ql,qr,l,mid,lc(p));
        if (qr> mid) res+=query(ql,qr,mid+1,r,rc(p));
        return res;
    }
};
int
signed main() {
    Cios;
    freopen("login.in","r",stdin);
    freopen("login.out","w",stdout);
    cin>>n>>q;
    for (int i=1;i<=n;i++) {
        cin>>li[i].t>>li[i].b;
    }
    while (q--) {
        int l,r;
        cin>>l>>r;
    }
    return 0;
}

/*
g++ -g login.cpp -o login.exe -std=c++14 -O2 -static; echo "finish"; .\login.exe
*/