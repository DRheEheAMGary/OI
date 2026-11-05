/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e6+10,M=1e5+10,inf=0x3f3f3f3f;
int n,l[N],r[N];
vector<int> nums;
inline int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline int getid (int x) {return lower_bound(nums.begin(),nums.end(),x)-nums.begin()+1;}
class SegmentTree {
    int tr[N<<2];
    void pushup (int u) {
        tr[u]=min(tr[u<<1],tr[u<<1|1]);
    }
public:
    void init (int sz) {
        for (int i=1;i<=sz*4;i++) tr[i]=inf;
    }
    void update (int u,int l,int r,int ql,int qr,int v) {
        if (ql>qr) return;
        if (tr[u]==v) return;
        if (ql<=l&&r<=qr) {
            tr[u]=v;
            return;
        }
        int mid=(l+r)>>1;
        if (ql<=mid) update(u<<1,l,mid,ql,qr,v);
        if (qr>mid) update(u<<1|1,mid+1,r,ql,qr,v);
        pushup(u);
    }
    int query (int u,int l,int r,int ql,int qr) {
        if (ql>qr||tr[u]==inf) return inf;
        if (ql<=l&&r<=qr) return tr[u];
        int mid=(l+r)>>1;
        int res=inf;
        if (ql<=mid) res=min(res,query(u<<1,l,mid,ql,qr));
        if (qr>mid) res=min(res,query(u<<1|1,mid+1,r,ql,qr));
        return res;
    }
}seg;
signed main() {
    freopen("records.in","r",stdin);
    freopen("records.out","w",stdout);
    int T=read();
    while (T--) {
        n=read();
        nums.clear();
        for (int i=1;i<=n;i++) {
            l[i]=read(),r[i]=read();
            nums.push_back(l[i]);
            nums.push_back(r[i]);
        }
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        int sz=nums.size();
        seg.init(sz);
        seg.update(1,1,sz,getid(r[1]),getid(r[1]),1);
        for (int i=2;i<=n;i++) {
            int lid=getid(l[i]);
            int rid=getid(r[i]);
            int mn=seg.query(1,1,sz,1,rid-1);
            if (mn!=inf) {
                int old=seg.query(1,1,sz,rid,rid);
                if (mn+1<old) seg.update(1,1,sz,rid,rid,mn+1);
            }
            if (lid>1) seg.update(1,1,sz,1,lid-1,inf);
        }
        int ans=seg.query(1,1,sz,1,sz);
        printf("%d\n",ans);
    }
    return 0;
}