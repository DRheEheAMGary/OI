/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e6+10;
int n;
class DSU {
    int l[N],r[N],sz[N],v[N],fa[N];
    struct node {
        int idx,val;
        bool operator < (const node &p) const {return val>p.val;}
    };
    int find (int x) {
        if (x==fa[x]) return x;
        return fa[x]=find(fa[x]);
    }
    void merge (int x,int y) {
        x=find(x);
        y=find(y);
        if (sz[x]<sz[y]) swap(x,y);
        fa[y]=x;
        sz[x]+=sz[y];
        v[x]+=v[y];
        l[x]=min(l[x],l[y]);
        r[x]=max(r[x],r[y]);
    }
    public:
    void setnode (int i,int _v) {
        fa[i]=i;
        l[i]=r[i]=i;
        sz[i]=1;
        v[i]=_v;
    }
    int solve (int k) {
        priority_queue<node> pq;
        for (int i=1;i<=n;i++) pq.push({i,v[i]});
        while (k--) {
            node p=pq.top();
            pq.pop();
            int i=p.idx;
            // printf("i:%lld v:%lld",i,p.val);
            if (fa[i]!=i||v[i]!=p.val) {
                k++;
                continue;
            }
            if (l[i]-1<1&&r[i]+1>n) continue;
            else if (l[i]-1<1&&r[i]+1<=n) merge(r[i]+1,i);
            else if (r[i]+1>n&&l[i]-1>=1) merge(l[i]-1,i);
            else {
                if (v[find(r[i]+1)]<v[find(l[i]-1)]) merge(r[i]+1,i);
                else merge(l[i]-1,i);
            }
            i=find(i);
            pq.push({i,v[i]});
            
            // for (int j=1;j<=n;j++) {
            //     if (j==fa[j]) printf("j:%lld l:%lld r:%lld v:%lld\n",j,l[j],r[j],v[j]);
            // }
            // printf("\n");
        }
        int res=0x3f3f3f3f3f3f3f3f;
        for (int i=1;i<=n;i++) {
            if (i==fa[i]) res=min(res,v[i]);
        }
        return res;
    }
}dsu;
signed main() {
    // freopen("test/merge/ex_merge3.in","r",stdin);
    // freopen("merge.ans","w",stdout);
    Cios;
    int c,q;
    cin>>c>>q;
    while (q--) {
        int k;
        cin>>n>>k;
        for (int i=1;i<=n;i++) {
            int a;
            cin>>a;
            dsu.setnode(i, a);
        }
        cout<<dsu.solve(k)<<"\n";
    }
    return 0;
}