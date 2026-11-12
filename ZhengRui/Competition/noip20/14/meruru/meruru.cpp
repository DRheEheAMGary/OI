/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
typedef __int128 intll;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e5+10;
inline intl gcd (intl a,intl b) {return b?gcd(b,a%b):a;}
struct Leaf {
    intl m,w;
    int id;
}a[N];
intl sm[N],sw[N],S[N],bp[N<<1];
int gr[N*3];
struct Cut {
    int id;
    intl x,y;
};
int n;
signed main() {
    Cios;
    // freopen("meruru.in","r",stdin);
    // freopen("meruru.out","w",stdout);
    int _c,_T;
    cin>>_c>>_T;
    while (_T--) {
        cin>>n;
        intl summ=0,sumw=0;
        for (int i=1;i<=n;i++) {
            cin>>a[i].m;
            a[i].id=i,summ+=a[i].m;
        }
        for (int i=1;i<=n;i++) cin>>a[i].w,sumw+=a[i].w;
        sort (a+1,a+1+n,[] (const Leaf &a,const Leaf &b) {return (intll)a.w*b.m<(intll)a.m*b.w;});
        for (int i=1;i<=n;i++) sm[i]=sm[i-1]+a[i].m,sw[i]=sw[i-1]+a[i].w,S[i]=2*sm[i];
        S[0]=0;
        int tot=0;
        for (int i=0;i<=n;i++) {
            if (S[i]<=summ) bp[++tot]=S[i];
            if (S[i]>=summ) bp[++tot]=S[i]-summ;
        }
        sort(bp+1,bp+1+tot);
        tot=unique(bp+1,bp+tot+1)-bp-1;
        auto pos=[&] (intl pos)->int {return lower_bound(S+1,S+1+n,pos)-S;};
        auto check=[&] (intl L,int l,int r)->bool {
            intl R=L+summ;
            if (l==r) return (intll)summ*a[l].w>=(intll)sumw*a[l].m;
            intll term_l=(intll)(S[l]-L)*a[l].w*a[r].m;
            intll term_mid=(intll)2*(sw[r-1]-sw[l])*a[l].m*a[r].m;
            intll term_r=(intll)(R-S[r-1])*a[r].w*a[l].m;
            return term_l+term_mid+term_r>=(intll)sumw*a[l].m*a[r].m;
        };
        int l=-1,r=-1;
        for (int i=1;i<tot;i++) {
            intl nxt=bp[i+1];
            l=pos(nxt);
            r=pos(nxt+summ);
            if (check(nxt,l,r)) break;
        }
        if (l==-1) l=pos(bp[tot]),r=pos(bp[tot]+summ);
        for (int i=1;i<=n+5;i++) gr[i]=0;
        vector <Cut> ct;
        if (l==r) {
            intl nd=summ;
            intl cur=2*a[l].m;
            if (nd==cur) gr[a[l].id]=1;
            else {
                intl g=gcd(nd,cur);
                ct.push_back({a[l].id,nd/g,cur/g});
                gr[a[l].id]=1;
                gr[n+1]=0;
            }
        }
        else {
            intl mm=sm[r-1]-sm[l];
            intl ww=sw[r-1]-sw[l];
            for (int i=l+1;i<r;i++) gr[a[i].id]=1;
            intl Cm=summ-2*mm;
            intl Cw=sumw-2*ww;
            intll d=(intll)4*(a[l].m*a[r].w-a[r].m*a[l].w);
            intll nu,du,nv,dv;
            if (d!=0) {
                nu=(intll)Cm*a[r].w-(intll)Cw*a[r].m;
                du=(intll)2*(a[l].m*a[r].w-a[l].w*a[r].m);
                if (du<0) nu=-nu,du=-du;
                nv=(intll)a[l].m*Cw-(intll)a[l].w*Cm;
                dv=(intll)2*(a[l].m*a[r].w-a[l].w*a[r].m);
                if (dv<0) nv=-nv,dv=-dv;
            }
            else {
                if (Cm<=2*a[l].m) nu=Cm,du=2*a[l].m,nv=0,dv=1;
                else nu=1,du=1,nv=Cm-2*a[l].m,dv=2*a[r].m;
            }
            int cnt=0;
            if (nu==0) gr[a[l].id]=0;
            else if (nu==du) gr[a[l].id]=1;
            else {
                cnt++;
                intl gu=gcd(nu,du);
                ct.push_back({a[l].id,(intl)nu/gu,(intl)du/gu});
                gr[a[l].id]=1;
                gr[n+cnt]=0;
            }
            if (nv==0) gr[a[r].id]=0;
            else if (nv==dv) gr[a[r].id]=1;
            else {
                cnt++;
                intl gv=gcd(nv,dv);
                ct.push_back({a[r].id,(intl)nv/gv,(intl)dv/gv});
                gr[a[r].id]=1;
                gr[n+cnt]=0;
            }
        }
        cout<<ct.size()<<"\n";
        for (auto [id,x,y]:ct) cout<<id<<" "<<x<<" "<<y<<"\n";
        for (int i=1;i<=n+ct.size();i++) cout<<gr[i]<<" \n"[i==n+ct.size()];
    }
    return 0;
}

/*
g++ -g meruru.cpp -o meruru.exe -std=c++14 -O2 -static; echo "finish"; .\meruru.exe; rm meruru.exe
cd $work && g++ meruru.cpp -o meruru -std=c++14 -O2 && echo "finish" && ./meruru && rm meruru
*/