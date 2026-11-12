/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=3e5+10,L=3e5+5;
constexpr intl inf=1ll<<60;
int mod;
int d[N][10][10],s[N][10][10],lead[N][10],pref[N],w[N][10],diff[N],dfx[N],x[N];
inline int abs (int x) {return (x>=0?x:-x);}
inline int getT (int l,int p,int q) {
    int v=d[l][p][q];
    if (p>0&&q>0) v-=d[l][p-1][q-1];
    return (v%mod+mod)%mod;
}
inline string add1 (string s) {
    int n=s.size(),c=1;
    for (int i=n-1;i>=0&&c;i--) {
        int v=s[i]-'0'+c;
        s[i]='0'+(v%10);
        c=v/10;
    }
    if (c) s='1'+s;
    return s;
}
inline int C (const string &str) {
    int l=str.size();
    if (l==1&&str[0]<='1') return 0;
    for (int i=1;i<=l;i++) x[i]=str[l-i]-'0';
    for (int k=1;k<l;k++) diff[k]=abs(x[l-k]-x[l-k+1]);
    for (int g=0;g<10;g++) w[1][g]=1;
    for (int u=1;u<l;u++) {
        for (int g=0;g<10;g++) w[u+1][g]=0;
        for (int g=0;g<10;g++) {
            if (!w[u][g]) continue;
            if (g-diff[u]>=0) w[u+1][g-diff[u]]=(w[u+1][g-diff[u]]+w[u][g])%mod;
            if (diff[u]>0&&g+diff[u]<=9) w[u+1][g+diff[u]]=(w[u+1][g+diff[u]]+w[u][g])%mod;
        }
    }
    for (int k=1;k<l;k++) dfx[k]=abs(x[k]-x[k+1]);
    int maxk=1;
    for (int k=1;k<l;k++) {
        if (dfx[k]!=dfx[l-k]&&k<l-k) maxk=k+1;
    }
    intl res=pref[l-1];
    for (int h=1;h<x[l];h++) (res+=lead[l][h])%=mod;
    for (int v=l-1;v>=1;v--) {
        int t=l-v,tl=l-2*t;
        if (v*2>l) {
            intl csum=0;
            int xv=x[v],xv1=x[v+1];
            for (int g=0;g<10;g++) {
                if (!w[t][g]) continue;
                int c=g-xv1,p=min(xv-1+c,9),q=p-c,res1=0;
                if (p>=0&&q>=0&&q<=9) res1=d[tl][p][q];
                int z=g+xv1,pp=max({0,z-9,z-(xv-1)}),qp=z-pp,res2=0;
                if (pp<=9&&qp>=0&&qp<=9) res2=s[tl][pp][qp];
                int itr=0;
                if (xv1<xv) itr=getT(tl,g,xv1);
                (csum+=(intl)w[t][g]*(((res1+res2-itr)%mod+mod)%mod))%=mod;
            }
            (res+=csum)%=mod;
        }
        else if (v*2==l) {
            int csum=0;
            for (int g=0;g<x[v];g++) (csum+=w[t][g])%=mod;
            (res+=csum)%=mod;
        }
        else {
            if (v+1>=maxk) {
                intl csum=0;
                int tar=diff[v];
                for (int g=0;g<x[v];g++) {
                    if (abs(x[v+1]-g)==tar) (csum+=w[v][g])%=mod;
                }
                (res+=csum)%=mod;
            }
        }
    }
    return res%mod;
}
signed main() {
    Cios;
    int T;
    cin>>T>>mod;
    int curt[10][10];
    for (int i=0;i<10;i++) for (int j=0;j<10;j++) curt[i][j]=(i==j);
    for (int p=0;p<10;p++) {
        for (int q=0;q<10;q++) {
            int curd=curt[p][q];
            if (p>0&&q>0) (curd+=d[1][p-1][q-1])%=mod;
            d[1][p][q]=curd;
        }
    }
    for (int p=9;p>=0;p--) {
        for (int q=0;q<10;q++) {
            int curs=curt[p][q];
            if (p<9&&q>0) (curs+=s[1][p+1][q-1])%=mod;
            s[1][p][q]=curs;
        }
    }
    for (int h=0;h<10;h++) {
        int sum=0;
        for (int q=0;q<10;q++) (sum+=curt[h][q])%=mod;
        lead[1][h]=sum;
    }
    int ssum=0;
    for (int h=1;h<10;h++) (ssum+=lead[1][h])%=mod;
    pref[1]=ssum;
    for (int i=0;i<10;i++) for (int j=0;j<10;j++) curt[i][j]=1;
    for (int p=0;p<10;p++) {
        for (int q=0;q<10;q++) {
            int curd=curt[p][q];
            if (p>0&&q>0) (curd+=d[2][p-1][q-1])%=mod;
            d[2][p][q]=curd;
        }
    }
    for (int p=9;p>=0;p--) {
        for (int q=0;q<10;q++) {
            int curs=curt[p][q];
            if (p<9&&q>0) (curs+=s[2][p+1][q-1])%=mod;
            s[2][p][q]=curs;
        }
    }
    for (int h=0;h<10;h++) {
        int sum=0;
        for (int q=0;q<10;q++) (sum+=curt[h][q])%=mod;
        lead[2][h]=sum;
    }
    ssum=pref[1];
    for (int h=1;h<10;h++) (ssum+=lead[2][h])%=mod;
    pref[2]=ssum;
    for (int l=3;l<=L;l++) {
        int prl=l-2;
        for (int p=0;p<10;p++) {
            for (int q=0;q<10;q++) {
                int k=min(9-p,9-q);
                int sp=max(0,p+q-9);
                curt[p][q]=((d[prl][p+k][q+k]+s[prl][sp][p+q-sp]-getT(prl,p,q))%mod+mod)%mod;
            }
        }
        for (int p=0;p<10;p++) {
            for (int q=0;q<10;q++) {
                int curd=curt[p][q];
                if (p>0&&q>0) (curd+=d[l][p-1][q-1])%=mod;
                d[l][p][q]=curd;
            }
        }
        for (int p=9;p>=0;p--) {
            for (int q=0;q<10;q++) {
                int curs=curt[p][q];
                if (p<9&&q>0) (curs+=s[l][p+1][q-1])%=mod;
                s[l][p][q]=curs;
            }
        }
        for (int h=0;h<10;h++) {
            int sum=0;
            for (int q=0;q<10;q++) (sum+=curt[h][q])%=mod;
            lead[l][h]=sum;
        }
        ssum=pref[l-1];
        for (int h=1;h<10;h++) (ssum+=lead[l][h])%=mod;
        pref[l]=ssum;
    }
    while (T--) {
        string ls,rs;
        cin>>ls>>rs;
        rs=add1(rs);
        cout<<((C(rs)-C(ls))%mod+mod)%mod<<"\n";
    }
    return 0;
}

/*
g++ -g numbers.cpp -o numbers.exe -std=c++14 -O2 -static; echo "finish"; .\numbers.exe; rm numbers.exe
cd $work && g++  numbers.cpp -o numbers -std=c++14 -O2 && echo "finish" && ./numbers && rm numbers
*/