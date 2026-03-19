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
int n,m,k,sz,a[N];
class Slovtion {
    int pos[N],pre[N],cnt[N];
    vector <int> b;
    struct ques1 {
        int idx,l,r,res;
    }q[N];
    struct ques2 {
        int idx,l,r,op;
    };
    vector <ques2> q2[N];
    public:
    void pushQues (int idx,int l,int r) {
        q[idx]={idx,l,r,0};
    }
    void Init () {
        sz=sqrt(n);
        for (int i=1;i<=n;i++) pos[i]=(i-1)/sz+1;
        sort (q+1,q+1+m,
            [&] (ques1 a,ques1 b) {
                if (pos[a.l]!=pos[b.l]) return pos[a.l]<pos[b.l];
                return a.r<b.r;
            }
        );
        for (int i=0;i<(1<<14);i++) {
            if (__builtin_popcount(i)==k) b.push_back(i);
        }
        for (int i=1;i<=n;i++) {
            pre[i]=cnt[a[i]];
            for (int bv:b) cnt[a[i]^bv]++;
        }
    }
    void Slove () {
        int l=1,r=0;
        for (int i=1;i<=m;i++) {
            if (r<q[i].r) q2[l-1].emplace_back(i,r+1,q[i].r,-1);
            while (r<q[i].r) q[i].res+=pre[++r];
            if (r>q[i].r) q2[l-1].emplace_back(i,q[i].r+1,r,1);
            while (r>q[i].r) q[i].res-=pre[r--];
            if (l>q[i].l) q2[r].emplace_back(i,q[i].l,l-1,1);
            while (l>q[i].l) q[i].res-=pre[--l]+(k==0);
            if (l<q[i].l) q2[r].emplace_back(i,l,q[i].l-1,-1);
            while (l<q[i].l) q[i].res+=pre[l++]+(k==0);
        }
        memset (cnt,0,sizeof cnt);
        for (int i=1;i<=n;i++) {
            for (int vb:b) cnt[a[i]^vb]++;
            for (ques2 vq2:q2[i]) {
                for (int k=vq2.l;k<=vq2.r;k++) q[vq2.idx].res+=vq2.op*cnt[a[k]];
            }
        }
    }
    void PrintAns () {
        for (int i=2;i<=m;i++) q[i].res+=q[i-1].res;
        sort (q+1,q+1+m,[&] (ques1 a,ques1 b) {return a.idx<b.idx;});
        for (int i=1;i<=m;i++) cout<<q[i].res<<"\n";
    }
}sl;
signed main() {
    Cios;
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=m;i++) {
        int l,r;
        cin>>l>>r;
        sl.pushQues(i,l,r);
    }
    sl.Init();
    sl.Slove();
    sl.PrintAns();
    return 0;
}