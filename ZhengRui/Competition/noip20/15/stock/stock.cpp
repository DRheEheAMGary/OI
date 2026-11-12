/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e6+10,lN=22,inf=1ll<<30;
int n,P,Q;
int a[N];
class STable {
    int lg[N],maxl[lN][N],minl[lN][N];
    public:
    void init () {
        lg[0]=-1;
        for (int i=1;i<=n;i++) lg[i]=lg[i/2]+1;
        int l=lg[n];
        for (int i=1;i<=n;i++) maxl[0][i]=minl[0][i]=a[i];
        for (int i=1;i<=l;i++) {
            for (int j=1;j+(1<<(i-1))<=n;j++) {
                maxl[i][j]=max(maxl[i-1][j],maxl[i-1][j+(1<<(i-1))]);
                minl[i][j]=min(minl[i-1][j],minl[i-1][j+(1<<(i-1))]);
            }
        }
    }
    int querymax (int l,int r) {
        int i=lg[r-l+1]; 
        return max(maxl[i][l],maxl[i][r-(1<<i)+1]);
    }
    int querymin (int l,int r) {
        int i=lg[r-l+1];
        return min(minl[i][l],minl[i][r-(1<<i)+1]);
    }
}st;
int sum[N];
int pl[N];
class SegmentTree {
    int tr[(N<<3)+5];
    int que[N<<1],nxt[N<<1];
    int exp=0;
    int hd[N<<1],tl[N<<1];
    bool empty (int k) {return hd[k]==-1;}
    void push (int k,int p) {
        que[++exp]=p;
        if (hd[k]==-1) hd[k]=tl[k]=exp;
        else nxt[tl[k]]=exp,tl[k]=exp;
    }
    void pop (int k) {
        if (hd[k]==tl[k]) hd[k]=tl[k]=-1;
        else hd[k]=nxt[hd[k]];
    }
    inline int lc (int p) {return p<<1;}
    inline int rc (int p) {return p<<1|1;}
    inline int lct (int p) {return tr[lc(p)];}
    inline int rct (int p) {return tr[rc(p)];}
    inline void pushup (int p) {tr[p]=min(lct(p),rct(p));}
    void update (int k,int id,int p=1,int l=1,int r=N<<1) {
        if (l==r) return tr[p]=id,void();
        int mid=(l+r)>>1;
        if (k<=mid) update(k,id,lc(p),l,mid);
        else update(k,id,rc(p),mid+1,r);
        pushup(p);
    }
    int query (int ql,int qr,int p,int l=1,int r=N<<1) {
        if (ql<=l&&r<=qr) return tr[p];
        int mid=(l+r)>>1;
        int res=inf;
        if (ql<=mid) res=min(res,query(ql,qr,lc(p),l,mid));
        if (qr>mid) res=min(res,query(ql,qr,rc(p),mid+1,r));
        return res;
    }
    public:
    void init () {memset(hd,-1,sizeof hd);}
    void build (int p=1,int l=1,int r=N<<1) {
        if (l==r) return tr[p]=inf,void();
        int mid=(l+r)>>1;
        build (lc(p),l,mid);
        build (rc(p),mid+1,r);
        pushup(p);
    }
    void insert (int k,int id) {
        k=k+N;
        if (empty(k)) update(k,id);
        push(k,id);
    }
    void del (int k) {
        k=k+N;
        pop(k);
        update(k,(empty(k)?inf:que[hd[k]]));
    }
    int query (int rawl,int rawr) {
        return query(max(1,rawl+N),rawr+N,1);
    }
}seg;
signed main() {
    Cios;
    // freopen("stock6.in","r",stdin);
    // freopen("stock.out","w",stdout);
    cin>>n>>P>>Q;
    for (int i=1;i<=n;i++) cin>>a[i];
    st.init();
    for (int i=2;i<=n;i++) {
        if (a[i]>a[i-1]) sum[i]=sum[i-1]+1;
        else if (a[i]<a[i-1]) sum[i]=sum[i-1]-1;
        else sum[i]=sum[i-1];
    }
    seg.init();
    seg.build();
    for (int i=1;i<=n;i++) {
        int l=1,r=i,res=i;
        while (l<=r) {
            int mid=(l+r)>>1;
            if (st.querymax(mid,i)-st.querymin(mid,i)<=P) res=mid,r=mid-1;
            else l=mid+1;
        }
        pl[i]=res;
    }
    int res=0,resl=1;
    for (int l=1,r=1;r<=n;r++) {
        seg.insert(sum[r],r);
        while (l<pl[r]) seg.del(sum[l++]);
        int rel=seg.query(sum[r]-Q,sum[r]+Q);
        if (res<r-rel+1) res=r-rel+1,resl=rel;
        else if (res==r-rel+1) resl=min(resl,rel);
    }
    cout<<res<<" "<<resl<<"\n";
    return 0;
}

/*
g++ -g stock.cpp -o stock.exe -std=c++14 -O2 -static; echo "finish"; .\stock.exe; rm stock.exe
cd $work/ZhengRui/Competition/noip20/15/stock && g++ stock.cpp -o stock -std=c++14 -O2 && echo "finish" && ./stock && rm stock
*/