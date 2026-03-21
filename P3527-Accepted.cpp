/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=3e5+10;
int n,m,k;
struct node {
    int x,y;
    intl k;
    int id,op;
}q[N<<1],q1[N<<1],q2[N<<1];
vector <int> cy[N];
struct Fenwick {
    intl tr[N];
    inline int lb (int x) {return x&(-x);}
    void Update (int p,int w) {
        while (p<N) {
            tr[p]+=w;
            p+=lb(p);
        }
    }
    intl Query (int p) {
        intl res=0;
        while (p) {
            res+=tr[p];
            p-=lb(p);
        }
        return res;
    }
    void UpdateInterval (int l,int r,int k) {
        Update (l,k);
        Update (r+1,-k);
    }
}bit;
int res[N];
void Solve (int l,int r,int ql,int qr) {
    if (ql>qr) return;
    if (l==r) {
        for (int i=ql;i<=qr;i++) {
            if (q[i].op) res[q[i].id]=l;
        }
        return;
    }
    int mid=(l+r)>>1;
    int cnt1=0,cnt2=0;
    for (int i=ql;i<=qr;i++) {
        if (q[i].op) {
            intl res=0;
            for (int o:cy[q[i].x]) {
                res+=bit.Query(o);
                if (res>=q[i].k) break;
            }
            if (res>=q[i].k) q1[++cnt1]=q[i];
            else q[i].k-=res,q2[++cnt2]=q[i];
        }
        else {
            if (q[i].id<=mid) {
                if (q[i].x<=q[i].y) bit.UpdateInterval(q[i].x,q[i].y,q[i].k);
                else bit.UpdateInterval(q[i].x, m, q[i].k),bit.UpdateInterval(1,q[i].y,q[i].k);
                q1[++cnt1]=q[i];
            }
            else q2[++cnt2]=q[i];
        }
    }
    for (int i=1;i<=cnt1;i++) {
        if (!q1[i].op) {
            if (q1[i].x<=q1[i].y) bit.UpdateInterval(q1[i].x,q1[i].y,-q1[i].k);
            else bit.UpdateInterval(q1[i].x, m, -q1[i].k),bit.UpdateInterval(1,q1[i].y,-q1[i].k);
        }
    }
    for (int i=1;i<=cnt1;i++) q[i+ql-1]=q1[i];
    for (int i=1;i<=cnt2;i++) q[i+ql+cnt1-1]=q2[i];
    Solve(l,mid,ql,ql+cnt1-1);
    Solve(mid+1,r,ql+cnt1,qr);
}
int qcnt=0;
signed main() {
    Cios;
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
        int o;
        cin>>o;
        cy[o].push_back(i);
    }
    vector<node> tmp;
    for (int i=1;i<=n;i++) {
        int p;
        cin>>p;
        tmp.push_back({i,0,p,i,1});
    }
    cin>>k;
    for (int i=1;i<=k;i++) {
        int l,r,a;
        cin>>l>>r>>a;
        q[++qcnt]={l,r,a,i,0};
    }
    for (node nd:tmp) q[++qcnt]=nd;
    Solve(1,k+1,1,qcnt);
    for (int i=1;i<=n;i++) {
        if (res[i]==k+1) cout<<"NIE\n";
        else cout<<res[i]<<"\n";
    }
    return 0;
}