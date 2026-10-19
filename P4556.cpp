/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lc (p<<1)
#define rc (p<<1|1)
intc N=1e5+10,modx=39989,mody=1000000000;
constexpr double eps=1e-9;
struct Line {
    double k,b;
    double y (int x) {return k*x+b;}
}li[N];
int tr[modx<<2],cnt=0;
int cmp(double x,double y) {
    if (x-y>eps) return 1;
    if (y-x>eps) return -1;
    return 0;
}
void modify (int p,int l,int r,int u) {
    int &v=tr[p];
    int mid=(l+r)>>1;
    int res=cmp(li[u].y(mid),li[v].y(mid));
    if (res==1||(res==0&&u<v)) swap(u,v);
    if (l==r) return;
    int resl=cmp(li[u].y(l),li[v].y(l));
    int resr=cmp(li[u].y(r),li[v].y(r));
    if (resl==1||(resl==0&&u<v)) modify (lc,l,mid,u);
    if (resr==1||(resr==0&&u<v)) modify (rc,mid+1,r,u);
}
void update (int p,int l,int r,int ul,int ur,int u) {
    if (ul<=l&&r<=ur) {
        modify(p,l,r,u);
        return;
    }
    int mid=(l+r)>>1;
    if (ul<=mid) update (lc,l,mid,ul,ur,u);
    if (ur> mid) update (rc,mid+1,r,ul,ur,u);
}
int maxp (int x,int u,int v) {
    if (!u) return v;
    if (!v) return u;
    int res=cmp(li[u].y(x),li[v].y(x));
    if (res==1) return u;
    if (res==-1) return v;
    return min(u,v);
}
int query (int p,int l,int r,int x) {
    if (l==r) return tr[p];
    int mid=(l+r)>>1;
    int res=tr[p];
    if (x<=mid) res=maxp(x,res,query(lc,l,mid,x));
    else        res=maxp(x,res,query(rc,mid+1,r,x));
    return res;
}
signed main() {
    Cios;
    int n;
    cin>>n;
    int lst=0;
    while (n--) {
        int op;
        cin>>op;
        if (op==0) {
            int k;
            cin>>k;
            k=(k+lst-1)%modx+1;
            lst=query(1,1,modx,k);
            cout<<lst<<"\n";
        }
        else {
            int x0,y0,x1,y1;
            cin>>x0>>y0>>x1>>y1;
            x0=(x0+lst-1)%modx+1;
            x1=(x1+lst-1)%modx+1;
            y0=(y0+lst-1)%mody+1;
            y1=(y1+lst-1)%mody+1;
            if (x0>x1) {
                swap(x0,x1);
                swap(y0,y1);
            }
            cnt++;
            if (x0==x1) {
                li[cnt].k=0;
                li[cnt].b=max(y0,y1);
            }
            else {
                li[cnt].k=(double)(y1-y0)/(x1-x0);
                li[cnt].b=y0-li[cnt].k*x0;
            }
            update(1,1,modx,x0,x1,cnt);
        }
    }
    return 0;
}