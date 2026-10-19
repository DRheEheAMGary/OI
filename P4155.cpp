/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=4e5+10;
struct interval {
    int id,l,r;
    bool operator < (const interval p) const {
        return l<p.l;
    }
}a[N];
int nxt[N][20],pos[N],res[N];
int n,m;
signed main() {
    Cios;
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        int c,d;
        cin>>c>>d;
        if (c<d) a[i]={i,c,d};
        else a[i]={i,c,d+m};
    }
    for (int i=1;i<=n;i++) {
        a[i+n]=a[i];
        a[i+n].l+=m;
        a[i+n].r+=m;
    }
    sort(a+1,a+1+2*n);
    for (int i=1;i<=2*n;i++) {
        if (!pos[a[i].id]) pos[a[i].id]=i;
    }
    int p=1;
    for (int i=1;i<=2*n;i++) {
        while (p+1<=2*n&&a[p+1].l<=a[i].r) p++;
        nxt[i][0]=p;
    }
    for (int j=1;j<20;j++) {
        for (int i=1;i<=2*n;i++) nxt[i][j]=nxt[nxt[i][j-1]][j-1];
    }
    for (int i=1;i<=n;i++) {
        int cur=pos[i];
        int lim=a[cur].l+m;
        int cnt=1;
        for (int j=19;j>=0;j--) {
            if (nxt[cur][j]!=0&&a[nxt[cur][j]].r<lim) {
                cnt+=(1<<j);
                cur=nxt[cur][j];
            }
        }
        res[i]=cnt+1;
    }
    for (int i=1;i<=m;i++) cout<<res[i]<<" \n"[i==n];
    return 0;
}