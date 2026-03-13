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
class Block {
    int n,m,sz,num;
    int a[N],cnt[N],bl[N],br[N],pos[N];
    int mex=0;
    struct ques {
        int idx,l,r,ans;
    }q[N];
    void add (int p) {
        // if (p>n) return;
        cnt[p]++;
    }
    void del (int p) {
        // if (p>n) return;
        cnt[p]--;
        if (cnt[p]==0) mex=min(mex,p);
    }
    public:
    void pushQues (int idx,int l,int r) {
        q[idx]={idx,l,r};
    }
    void init (int _n,int _m,int* _a) {
        n=_n;
        m=_m;
        sz=sqrt(n);
        num=(n-1)/sz+1;
        for (int i=1;i<=n;i++) {
            a[i]=_a[i];
            pos[i]=(i-1)/sz+1;
        }
        sort (q+1,q+1+m,
            [&] (ques a,ques b) {
                if (pos[a.l]!=pos[b.l]) return pos[a.l]<pos[b.l];
                return a.r>b.r;
            }
        );
        for (int i=1;i<=num;i++) {
            bl[i]=(i-1)*sz+1;
            br[i]=min(n,i*sz);
        }
    }
    void solve () {
        int qidx=1;
        int l=1,r=n;
        for (int i=1;i<=n;i++) {
            // if (a[i]>n) continue;
            cnt[a[i]]++;
        }
        for (int i=0;i<=n;i++) {
            if (!cnt[i]) {
                mex=i;
                break;
            }
        }
        for (int i=1;i<=num&&qidx<=m;i++) {
            while (l<bl[i]) del(a[l++]);
            int tmp_=mex;
            for (;qidx<=m&&pos[q[qidx].l]==i;qidx++) {
                int ql=q[qidx].l,qr=q[qidx].r,idx=q[qidx].idx;
                while (r>qr) del(a[r--]);
                int tmp=mex;
                while (l<ql) del(a[l++]);
                q[qidx].ans=mex;
                while (l>bl[i]) add(a[--l]);
                mex=tmp;
            }
            mex=tmp_;
            while (r<n) add(a[++r]);
        }
    }
    void printAns () {
        sort (q+1,q+1+m,
            [&] (ques a,ques b) {
                return a.idx<b.idx;
            }
        );
        for (int i=1;i<=m;i++) cout<<q[i].ans<<"\n";
    }
}bl;
int n,m,a[N];
signed main(){
    Cios;
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++) {
        int l,r;
        cin>>l>>r;
        bl.pushQues(i,l,r);
    }
    bl.init(n,m,a);
    bl.solve();
    bl.printAns();
    return 0;
}