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
int res,n,a[N],sum[N],mx[N];
class Fenwick {
    int tr[N<<2];
    inline int lb (int x) {return x&(-x);}
    public:
    void update (int x,int v) {
        x+=(N<<1);
        while (x<(N<<2)) {
            tr[x]+=v;
            x+=lb(x);
        }
    }
    int query (int x) {
        int res=0;
        x+=(N<<1);
        while (x) {
            res+=tr[x];
            x-=lb(x);
        }
        return res;
    }
}bit;
void solve (int l,int r) {
    if (l==r) return res++,void();
    int mid=(l+r)>>1;
    solve(l,mid);
    solve(mid+1,r);
    mx[mid]=-sum[mid];
    mx[mid+1]=-sum[mid+1];
    for (int i=mid+2;i<=r;i++) mx[i]=min(mx[i-1],-sum[i]);
    for (int i=mid-1;i>=l;i--) mx[i]=min(mx[i+1],-sum[i]);
    int p=r;
    for (int i=l;i<=mid;i++) {
        while (p>=mid+1&&mx[i]>=mx[p]) bit.update(-sum[p]-mx[p],1),p--;
        res+=bit.query(sum[i-1]);
    }
    for (int i=p+1;i<=r;i++) bit.update(-sum[i]-mx[i],-1);
    p=l;
    for (int i=r;i>=mid+1;i--) {
        while (p<=mid&&mx[i]>mx[p]) bit.update(-sum[p-1]-mx[p], 1),p++;
        res+=bit.query(sum[i]);
    }
    for (int i=l;i<=p-1;i++) bit.update(-sum[i-1]-mx[i],-1);
}
signed main() {
    Cios;
    string s;
    cin>>s;
    n=s.size();
    for (int i=1;i<=n;i++) {
        a[i]=(s[i-1]=='('?1:-1);
        sum[i]=sum[i-1]+a[i];
    }
    solve(1,n);
    cout<<res<<'\n';
    return 0;
}