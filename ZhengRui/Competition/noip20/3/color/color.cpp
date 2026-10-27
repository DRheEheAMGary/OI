/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e5+10;
int r[N],y[N],b[N];
void turn (int i,char c) {
    if (c=='R'||c=='O'||c=='P'||c=='A') r[i]=1;
    if (c=='Y'||c=='O'||c=='G'||c=='A') y[i]=1;
    if (c=='B'||c=='P'||c=='G'||c=='A') b[i]=1;
}
int n;
signed main() { 
    Cios;
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while (T--) {
        cin>>n;
        string s;
        cin>>s;
        s=' '+s;
        for (int i=1;i<=n;i++) turn(i,s[i]);
        bool rl=0,yl=0,bl=0;
        int res=0;
        for (int i=1;i<=n;i++) {
            if (r[i]) {
                if (rl);
                else rl=1,res++;
            }
            else rl=0;
            if (y[i]) {
                if (yl);
                else yl=1,res++;
            }
            else yl=0;
            if (b[i]) {
                if (bl);
                else bl=1,res++;
            }
            else bl=0;
        }
        cout<<res<<"\n";
        for (int i=1;i<=n;i++) r[i]=y[i]=b[i]=0;
    }
    return 0;
}

/*
g++ -g color.cpp -o color.exe -std=c++14 -O2 -static; echo "finish"; .\color.exe
g++  color.cpp -o color -std=c++14 -O2 && echo "finish" && ./color
*/