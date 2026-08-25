/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1.82e6+10,A=5005;
int n,a[N],sufmex[N];
class SegmentTree{
    struct TreeNode{
        int max;
    }tr[N<<2];
    inline int lc (int p) {return p<<1;}
    inline int rc (int p) {return p<<1|1;}
    inline TreeNode& lt (int p) {return tr[lc(p)];}
    inline TreeNode& rt (int p) {return tr[rc(p)];}
    void pushup (int p) {
        tr[p].max=max(lt(p).max,rt(p).max);
    }
    public:
    void Build (int p=1,int l=1,int r=n) {
        if (l==r) {
            tr[p].max=a[l];
            return;
        }
        int mid=(l+r)>>1;
        Build(lc(p),l,mid);
        Build(rc(p),mid+1,r);
        pushup(p);
    }
    int QueryMax (int ql,int qr,int p=1,int l=1,int r=n) {
        if (ql<=l&&r<=qr) return tr[p].max;
        int mid=(l+r)>>1,res=-1;
        if (ql<=mid) res=max(res,QueryMax(ql,qr,lc(p),l,mid));
        if (qr>mid) res=max(res,QueryMax(ql,qr,rc(p),mid+1,r));
        return res;
    }
}st;
signed main () {
    Cios;
    int c,T;
    cin>>c>>T;
    while (T--) {
        cin>>n;
        for (int i=1;i<=n;i++) cin>>a[i];
        bitset<A> vis;
        int mex=0;
        for (int i=n;i>=1;i--) {
            if (a[i]<A) vis.set(a[i]);
            while (mex<A&&vis[mex]) mex++;
            sufmex[i]=mex;
        }
        st.Build();
        int mn=a[1];
        intl res=0;
        for (int r1=1;r1<=n-2;r1++) {
            mn=min(mn,a[r1]);
            int l=r1+1,r=n-1,pos=n;
            while (l<=r) {
                int mid=(l+r)>>1;
                int _max=st.QueryMax(r1+1,mid);
                int _mex=sufmex[mid+1];
                if (_max-_mex>=mn) {
                    pos=mid;
                    r=mid-1;
                }
                else l=mid+1;
            }
            if (pos==n) continue;
            if (st.QueryMax(r1+1,pos)-sufmex[pos+1]!=mn) continue;
            l=pos;
            r=n-1;
            int last=pos;
            while (l<=r) {
                int mid=(l+r)>>1;
                int _max=st.QueryMax(r1+1,mid);
                int _mex=sufmex[mid+1];
                if (_max-_mex<=mn) {
                    last=mid;
                    l=mid+1;
                }
                else r=mid-1;
            }
            res+=last-pos+1;
        }
        cout<<res<<"\n";
    }
    return 0;
}