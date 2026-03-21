/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e5+10,inf=INT_MAX;
int n,m,qcnt,minn=inf,maxn=-inf;
int res[N],a[N];
struct ques {
    int x,y,k,id,op;
}q[N<<1],q1[N<<1],q2[N<<1];
struct Fenwick {
    int tr[N<<1];
    int lowbit (int x) {return x&(-x);}
    void Update (int p,int w) {
        while (p<(N<<1)) {
            tr[p]+=w;
            p+=lowbit(p);
        }
    }
    int Query (int p) {
        int res=0;
        while (p) {
            res+=tr[p];
            p-=lowbit(p);
        }
        return res;
    }
}bit;
void Solve (int vl,int vr,int ql,int qr) {
    if (ql>qr) return;
    if (vl==vr) {
        for (int i=ql;i<=qr;i++) {
            if (q[i].op) res[q[i].id]=vl;
        }
        return;
    }
    int mid=vl+vr>>1;
    int cnt1=0,cnt2=0;
    for (int i=ql;i<=qr;i++) {
        if (!q[i].op) {
            if (q[i].x<=mid) bit.Update(q[i].id,q[i].k),q1[++cnt1]=q[i];
            else q2[++cnt2]=q[i];
        }
        else {
            int s=bit.Query(q[i].y)-bit.Query(q[i].x-1);
            if (s>=q[i].k) q1[++cnt1]=q[i];
            else q[i].k-=s,q2[++cnt2]=q[i];
        }
    }
    for (int i=1;i<=cnt1;i++) {
        if (!q1[i].op) bit.Update(q1[i].id,-q1[i].k);
    }
    for (int i=1;i<=cnt1;i++) q[i+ql-1]=q1[i];
    for (int i=1;i<=cnt2;i++) q[i+ql+cnt1-1]=q2[i];
    Solve (vl,mid,ql,ql+cnt1-1);
    Solve (mid+1,vr,ql+cnt1,qr);
}
signed main() {
    Cios;
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        q[++qcnt]={a[i],0,1,i,0};
        minn=min(minn,a[i]);
        maxn=max(maxn,a[i]);
    }
    int qr=0;
    for (int i=1;i<=m;i++) {
        char op;
        int x,y,k;
        cin>>op>>x>>y;
        if (op=='Q') {
            cin>>k;
            q[++qcnt]={x,y,k,++qr,1};
        }
        else {
            q[++qcnt]={a[x],0,-1,x,0};
            a[x]=y;
            minn=min(minn,y);
            maxn=max(maxn,y);
            q[++qcnt]={a[x],0,1,x,0};
        }
    }
    Solve(minn,maxn,1,qcnt);
    for (int i=1;i<=qr;i++) cout<<res[i]<<"\n";
    return 0;
}