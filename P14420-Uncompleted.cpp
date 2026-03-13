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
class Block {
    int n,m,sz,num;
    int a[N],cnt[N],bl[N],br[N],pos[N];
    vector <int> disc;
    int res=-1;
    struct ques {
        int idx,l,r,ans;
    }q[N];
    void add (int p) {
        cnt[p]++;
        res=max(res,cnt[p]*disc[p]);
    }
    void del (int p) {
        cnt[p]--;
    }
    int query (int l,int r) {
        int res=0;
        for (int i=l;i<=r;i++) cnt[a[i]]++;
        for (int i=l;i<=r;i++) res=max(res,cnt[a[i]]*disc[a[i]]);
        for (int i=l;i<=r;i++) cnt[a[i]]--;
        return res;
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
        for (int i=1;i<=n;i++) a[i]=_a[i],pos[i]=(i-1)/sz+1,disc.push_back(a[i]);
        sort (disc.begin(),disc.end());
        disc.erase (unique (disc.begin(),disc.end()),disc.end());
        for (int i=1;i<=n;i++) a[i]=lower_bound(disc.begin(),disc.end(),a[i])-disc.begin();
        sort (q+1,q+1+m,
            [&] (ques a,ques b) {
                if (pos[a.l]!=pos[b.l]) return pos[a.l]<pos[b.l];
                return a.r<b.r;
            }
        );
        for (int i=1;i<=num;i++) {
            bl[i]=(i-1)*sz+1;
            br[i]=min(n,i*sz);
        }
    }
    void solve () {
        int qidx=1;
        for (int i=1;i<=num&&qidx<=m;i++) {
            res=0;
            memset(cnt,0,sizeof cnt);
            int l=br[i]+1,r=br[i];
            for (;qidx<=m&&pos[q[qidx].l]==i;qidx++) {
                int ql=q[qidx].l,qr=q[qidx].r,idx=q[qidx].idx;
                if (qr<=br[i]) q[qidx].ans=query(ql,qr);
                else {
                    while (r<qr) add(a[++r]);
                    int tmp=res;
                    while (l>ql) add(a[--l]);
                    q[qidx].ans=res;
                    res=tmp;
                    while (l<=br[i]) del(a[l++]);
                }
            }
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