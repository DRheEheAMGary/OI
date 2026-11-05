/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e6+10;
int nxt[N];
string s,t;
int sl,tl;
signed main() {
    Cios;
    cin>>s>>t;
    sl=s.size();
    tl=t.size();
    s=" "+s;
    t=" "+t;
    nxt[1]=0;
    for (int i=2,j=0;i<=tl;i++) {
        while (j>0&&t[i]!=t[j+1]) j=nxt[j];
        if (t[i]==t[j+1]) j++;
        nxt[i]=j;
    }
    for (int i=1,j=0;i<=sl;i++) {
        while (j>0&&s[i]!=t[j+1]) j=nxt[j];
        if (s[i]==t[j+1]) j++;
        if (j==tl) cout<<i-tl+1<<"\n",j=nxt[j];
    }
    for (int i=1;i<=tl;i++) cout<<nxt[i]<<" ";
    return 0;
}

/*
g++ -g mainc.cpp -o mainc.exe -std=c++14 -O2 -static; echo "finish"; .\mainc.exe; rm mainc.exe
cd $work && g++  mainc.cpp -o mainc -std=c++14 -O2 && echo "finish" && ./mainc && rm mainc
*/