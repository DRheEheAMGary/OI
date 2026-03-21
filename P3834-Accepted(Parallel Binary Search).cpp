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
int res[N];
struct ques {
    int x,y,k,id,op;
}q[N<<1],q1[N<<1],q2[N<<1];
struct Fenwick {
    int tr[N<<1];
    int lowbit (int x) {return x&(-x);}
    void Update (int p,int w) {
        while (p<=(N<<1)) {
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
            if (q[i].y<=mid) {
                bit.Update(q[i].x,1);
                q1[++cnt1]=q[i];
            }
            else q2[++cnt2]=q[i];
        }
        else {
            int s=bit.Query(q[i].y)-bit.Query(q[i].x-1);
            if (s>=q[i].k) q1[++cnt1]=q[i];
            else q[i].k-=s,q2[++cnt2]=q[i];
        }
    }
    for (int i=1;i<=cnt1;i++) {
        if (!q1[i].op) bit.Update(q1[i].x,-1);
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
        int x;
        cin>>x;
        q[++qcnt]={i,x,0,0,0};
        minn=min(minn,x);
        maxn=max(maxn,x);
    }
    for (int i=1;i<=m;i++) {
        int l,r,k;
        cin>>l>>r>>k;
        q[++qcnt]={l,r,k,i,1};
    }
    Solve(minn,maxn,1,qcnt);
    for (int i=1;i<=m;i++) cout<<res[i]<<"\n";
    return 0;
}