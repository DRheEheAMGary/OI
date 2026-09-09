/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e6+10;
int n,p[N];
class Fenwick {
    int tr[N];
    inline int lb (int x) {return x&(-x);}
    public:
    void update (int x,int v) {
        while (x<N) {
            tr[x]+=v;
            x+=lb(x);
        }
    }
    int query (int x) {
        int res=0;
        while (x) {
            res+=tr[x];
            x-=lb(x);
        }
        return res;
    }
    inline int query (int l,int r) {return query(r)-query(l-1);}
}bit;
int setl[N],setr[N];
int ll[N],rr[N];
int prf[N],suf[N];
signed main() {
    Cios;
    // freopen ("canyon.in","r",stdin);
    // freopen ("canyon.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i];
    // int res=0;
    // bit.update(p[1],1);
    // for (int l=1;l<=n;l+=2) {
    //     for (int r=l+1;r<=n;r++) {
    //         int minp=min(p[l],p[r]);
    //         bit.update(p[r],1);
    //         res=max(res,bit.query(1,minp-1)+2);
    //     }
    //     bit.update(p[l],-1);   
    //     for (int r=n;r>=l+2;r--) {
    //         int minp=min(p[l],p[r]);    
    //         bit.update(p[r],-1);
    //         res=max(res,bit.query(1,minp-1)+2);
    //     }
    // }
    // cout<<res<<"\n";
    for (int i=n;i>=1;i--) {
        rr[i]=bit.query(p[i]-1);
        bit.update(p[i],1);
    }
    for (int i=1;i<=n;i++) bit.update(p[i],-1);
    for (int i=1;i<=n;i++) {
        ll[i]=bit.query(p[i]-1);
        bit.update(p[i],1);
    }
    for (int i=1;i<=n;i++) bit.update(p[i],-1);
    for (int i=1;i<=n;i++) prf[i]=max(p[i],prf[i-1]);
    for (int i=n;i>=1;i--) suf[i]=max(p[i],suf[i+1]);
    for (int i=1;i<=n;i++) {
        int l=i+1,r=n+1,res=0;
        while (l<=r) {
            int mid=(l+r)>>1;
            if (suf[mid]>p[i]) res=mid,l=mid+1;
            else r=mid-1;
        }
        setr[i]=res;
        l=0,r=i-1,res=0;
        while (l<=r) {
            int mid=(l+r)>>1;
            if (prf[mid]>p[i]) res=mid,r=mid-1;
            else l=mid+1;
        }
        setl[i]=res;
    }
    int res=0;
    for (int i=1;i<=n;i++) {
        if (setl[i]!=0) res=max(res,2+ll[i]-(setl[i]-1));
        if (setr[i]!=0) res=max(res,2+rr[i]-(n-setr[i]));
    }
    #ifdef DEBUG
    for (int i=1;i<=n;i++) printf("i:%d ll:%d rr:%d setl:%d setr:%d suf:%d prf:%d\n",i,ll[i],rr[i],setl[i],setr[i],suf[i],prf[i]);
    #endif
    cout<<res<<"\n";
    return 0;
}

/*
g++ -g canyon.cpp -o canyon.exe -O2 -std=c++14 -static -DDEBUG ; echo "finish" ; .\canyon.exe

6
5 1 6 2 3 4

5

5
5 4 3 2 1

2

20
1 3 5 7 9 11 13 20 17 19 8 18 16 14 12 10 15 6 4 2

6
*/