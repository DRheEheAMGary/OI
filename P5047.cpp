/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(a) a.begin(),a.end()
intc N=1e5+10;
int n,m,sz,a[N];
class Block {
    static const int B=320;
    int n,sz,num;
    int bl[B],br[B],pos[N],sum[B],cnt[N];
    public:
    void Init (int v) {
        n=v;
        sz=sqrt(v);
        num=(n-1)/sz+1;
        for (int i=1;i<=n;i++) pos[i]=(i-1)/sz+1;
        for (int i=1;i<=num;i++) {
            bl[i]=(i-1)*sz+1;
            br[i]=min(n,i*sz);
        }
    }
    void Clear () {
        for (int i=1;i<=num;i++) sum[i]=0;
        for (int i=1;i<=n;i++) cnt[i]=0;
    }
    void Update (int p) {
        for (int i=p;i<=br[pos[p]];i++) cnt[i]++;
        for (int i=pos[p]+1;i<=num;i++) sum[i]++;
    }
    int Queryr (int r) {
        if (r<1) return 0;
        if (r>n) r=n;
        return sum[pos[r]]+cnt[r];
    }
    int Queryl (int l) {
        if (l>n) return 0;
        if (l<1) l=1;
        return Queryr(n)-Queryr(l-1);
    }
};
class Solution {
    int maxa=-1;
    int s1[N],s2[N],pos[N],cnt[N];
    intl res[N];
    vector <int> disc;
    struct ques1 {
        int idx,l,r;
        intl res;
    }q[N];
    struct ques2 {
        int ty,idx,l,r,op;
    };
    vector <ques2> q2[N];
    Block bl;
    public:
    inline void PushNum (int _a) {
        disc.push_back(_a);
    }
    inline void PushQues (int i,int l,int r) {
        q[i]={i,l,r,0};
    }
    inline void Init () {
        sz=sqrt(n);
        for (int i=1;i<=n;i++) pos[i]=(i-1)/sz+1;
        sort (all(disc));
        disc.erase(unique(all(disc)),disc.end());
        for (int i=1;i<=n;i++) a[i]=lower_bound(all(disc),a[i])-disc.begin()+1;
        maxa=disc.size();
        sort (q+1,q+1+m,
            [&] (ques1 a,ques1 b) {
                if (pos[a.l]!=pos[b.l]) return pos[a.l]<pos[b.l];
                else {
                    if (pos[a.l]%2==0) return a.r>b.r;
                    else return a.r<b.r;
                }
            }
        );
        bl.Init(maxa);
        for (int i=1;i<=n;i++) {
            s1[i]=bl.Queryl(a[i]+1);
            s2[i]=bl.Queryr(a[i]-1);
            bl.Update(a[i]);
        }
    }
    inline void Slove () {
        for (int i=1,l=1,r=0;i<=m;i++) {
            int ql=q[i].l,qr=q[i].r;
            if (l>ql) q2[r].push_back({2,i,ql,l-1,1});
            while (l>ql) q[i].res-=s2[--l];
            if (r<qr) q2[l-1].push_back({1,i,r+1,qr,-1});
            while (r<qr) q[i].res+=s1[++r];
            if (l<ql) q2[r].push_back({2,i,l,ql-1,-1});
            while (l<ql) q[i].res+=s2[l++];
            if (r>qr) q2[l-1].push_back({1,i,qr+1,r,1});
            while (r>qr) q[i].res-=s1[r--];
        }
        bl.Clear();
        for (int i=1;i<=n;i++) {
            bl.Update(a[i]);
            for (ques2 v:q2[i]) {
                int ty=v.ty,vi=v.idx,vl=v.l,vr=v.r,op=v.op;
                for (int k=vl;k<=vr;k++) {
                    if (ty==1) q[vi].res+=bl.Queryl(a[k]+1)*op;
                    else q[vi].res+=bl.Queryr(a[k]-1)*op;
                }
            }
        }
    }
    inline void PrintAnswer () {
        for (int i=1;i<=m;i++) q[i].res+=q[i-1].res;
        for (int i=1;i<=m;i++) res[q[i].idx]=q[i].res;
        for (int i=1;i<=m;i++) cout<<res[i]<<"\n";
    }
}sl;
inline int read() {
	int x=0;
	char ch=getchar();
	while (!isdigit(ch)) ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
signed main() {
    n=read();
    m=read();
    for (int i=1;i<=n;i++) a[i]=read(),sl.PushNum(a[i]);
    for (int i=1;i<=m;i++) {
        int l,r;
        l=read();
        r=read();
        sl.PushQues(i,l,r);
    }
    sl.Init();
    sl.Slove();
    sl.PrintAnswer();
    return 0;
}