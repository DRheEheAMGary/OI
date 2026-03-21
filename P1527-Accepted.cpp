/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1000,N2=2.5e5+10,M=1e6+10,inf=(1<<30);
int n,m,maxa=-inf,mina=inf;
int res[M];
struct Fenwick {
    int tr[N][N];
    inline int lowbit (int x) {return x&(-x);}
    void Update (int px,int py,int w) {
        for (int x=px;x<N;x+=lowbit(x)) {
            for (int y=py;y<N;y+=lowbit(y)) tr[x][y]+=w;
        }
    }
    int Query (int px,int py){
        int res=0;
        for (int x=px;x;x-=lowbit(x)) {
            for (int y=py;y;y-=lowbit(y)) res+=tr[x][y];
        }
        return res;
    }
    int Queryblock (int x1,int y1,int x2,int y2) {
        return Query(x2,y2)-Query(x2,y1-1)-Query(x1-1,y2)+Query(x1-1,y1-1);
    }
}bit;
struct ques {
    int x1,y1,x2,y2,k,idx,op;
}q[M<<1],q1[M<<1],q2[M<<1];
int qcnt=0;
void Solve (int vl,int vr,int ql,int qr) {
    if (ql>qr) return;
    if (vl==vr) {
        for (int i=ql;i<=qr;i++) {
            if (q[i].op) res[q[i].idx]=vl;
        }
        return ;
    }
    int mid=vl+vr>>1;
    int cnt1=0,cnt2=0;
    for (int i=ql;i<=qr;i++) {
        if (q[i].op) {
            int res=bit.Queryblock(q[i].x1,q[i].y1,q[i].x2,q[i].y2);
            if (res>=q[i].k) q1[++cnt1]=q[i];
            else q[i].k-=res,q2[++cnt2]=q[i];
        }
        else {
            if (q[i].k<=mid) bit.Update(q[i].x1,q[i].y1,1),q1[++cnt1]=q[i];
            else q2[++cnt2]=q[i];
        }
    }
    for (int i=1;i<=cnt1;i++) {
        if (!q1[i].op) bit.Update(q1[i].x1,q1[i].y1,-1);
    }
    for (int i=1;i<=cnt1;i++) q[i+ql-1]=q1[i];
    for (int i=1;i<=cnt2;i++) q[i+cnt1+ql-1]=q2[i];
    Solve(vl,mid,ql,ql+cnt1-1);
    Solve(mid+1,vr,ql+cnt1,qr);
}
signed main() {
    Cios;
    cin>>n>>m;
    int x_;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) cin>>x_,q[++qcnt]={i,j,0,0,x_,0,0},maxa=max(maxa,x_),mina=min(mina,x_);
    }
    for (int i=1;i<=m;i++) {
        int x1,y1,x2,y2,k;
        cin>>x1>>y1>>x2>>y2>>k;
        q[++qcnt]={x1,y1,x2,y2,k,i,1};
    }
    Solve(mina,maxa,1,qcnt);
    for (int i=1;i<=m;i++) cout<<res[i]<<"\n";
    return 0;
}