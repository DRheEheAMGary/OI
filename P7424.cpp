/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e5+10,inf=(1<<30);;
int n,m,qcnt=0,res[N];
struct node {
    int x,y,k,id,op;
}q[N<<1],q1[N<<1],q2[N<<1];
struct Fenwick {
    int tr[N];
    inline int lb (int x) {return x&(-x);}
    inline void Update (int p,int w) {
        while (p<N) {
            tr[p]+=w;
            p+=lb(p);
        }
    }
    inline int Query (int p) {
        int res=0;
        while (p) {
            res+=tr[p];
            p-=lb(p);
        }
        return res;
    }
    inline int QueryInterval (int l,int r) {
        return Query(r)-Query(l-1);
    }
}bit;
inline void Slove (int vl,int vr,int ql,int qr) {
    if (ql>qr) return;
    if (vl==vr) {
        if (vl==m+1) return;
        for (int i=ql;i<=qr;i++) {
            if (q[i].op) res[vl]++;
        }
        return;
    }
    int mid=(vl+vr)>>1;
    int cnt1=0,cnt2=0;
    for (int i=ql;i<=qr;i++) {
        if (q[i].op) {
            int s=bit.QueryInterval(q[i].x,q[i].y);
            if (s>=q[i].k) q1[++cnt1]=q[i];
            else q[i].k-=s,q2[++cnt2]=q[i];
        }
        else {
            if (q[i].x<=mid) bit.Update(q[i].id,1),q1[++cnt1]=q[i];
            else q2[++cnt2]=q[i];
        }
    }
    for (int i=1;i<=cnt1;i++) {
        if (!q1[i].op) bit.Update(q1[i].id,-1);
    }
    for (int i=1;i<=cnt1;i++) q[i+ql-1]=q1[i];
    for (int i=1;i<=cnt2;i++) q[i+ql+cnt1-1]=q2[i];
    Slove (vl,mid,ql,ql+cnt1-1);
    Slove (mid+1,vr,ql+cnt1,qr);
}
signed main() {
    Cios;
    cin>>n>>m;
    vector<node> tmp;
    for (int i=1;i<=n;i++) {
        int l,r,k;
        cin>>l>>r>>k;
        tmp.push_back({l,r,k,i,1});
    }
    for (int i=1;i<=m;i++) {
        int p;
        cin>>p;
        q[++qcnt]={i,0,0,p,0};
    }
    for (int i=0;i<n;i++) q[++qcnt]=tmp[i];
    Slove (1,m+1,1,qcnt);
    for (int i=1;i<=m;i++) cout<<res[i]<<"\n";
    return 0;
}