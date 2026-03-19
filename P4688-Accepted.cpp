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
intc N=1e5+10,M=N/3+10;
int n,m,nwm=0,a[N];
class Solution {
    int sz;
    struct ques {
        int idx,l,r;
    }q[N*3];
    bitset<N> bi[M],nw;
    int len,qcnt,res[M],cnt[N];
    inline int pos (int p) {return (p-1)/sz+1;}
    void add (int p) {
        nw.set(p+cnt[p]);
        cnt[p]++;
    } 
    void del (int p) {
        cnt[p]--;
        nw.reset(p+cnt[p]);
    }
    public:
    void Solve () {
        sz=sqrt(n);
        len=0;
        qcnt=0;
        nw.reset();
        memset(cnt,0,sizeof cnt);
        for (len=1;len<=M-5&&nwm<m;len++) {
            nwm++;
            res[len]=0;
            bi[len].set();
            for (int i=1;i<=3;i++) {
                int l,r;
                cin>>l>>r;
                q[++qcnt]={len,l,r};
                res[len]+=r-l+1;
            }
        }
        sort (q+1,q+1+qcnt,
            [&] (ques a,ques b) {
                if (pos(a.l)!=pos(b.l)) return pos(a.l)<pos(b.l);
                if (pos(a.l)%2==0) return a.r>b.r;
                return a.r<b.r;
            }
        );
        for (int i=1,l=1,r=0;i<=qcnt;i++) {
            while (l>q[i].l) add(a[--l]);
            while (r<q[i].r) add(a[++r]);
            while (l<q[i].l) del(a[l++]);
            while (r>q[i].r) del(a[r--]);
            bi[q[i].idx]&=nw;
        }
        for (int i=1;i<len;i++) cout<<res[i]-bi[i].count()*3<<"\n";
    }
}sl;
vector <int> disc;
signed main() {
    Cios;
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i],disc.push_back(a[i]);
    sort (all(disc));
    for (int i=1;i<=n;i++) a[i]=lower_bound(all(disc),a[i])-disc.begin()+1;
    sl.Solve();
    sl.Solve();
    sl.Solve();
    return 0;
}