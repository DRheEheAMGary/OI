/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1005;
int n,a,b,s[N];
signed main() {
    Cios;
    int T;
    cin>>T;
    while (T--) {
        cin>>n>>a>>b;
        for (int i=1;i<=n;i++) cin>>s[i];
        int res=0;
        for (int i=1;i<=n;i++) {
            if (a==0&&b==0) break;
            if (s[i]==1) {
                if (a) a--,res++;
                else if (b) b--,res++;
                else break;
            }
            else {
                if (b) b--,res++;
                else break;
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}

/*
g++ -g mainc.cpp -o mainc.exe -std=c++14 -O2 -static; echo "finish"; .\mainc.exe
g++  mainc.cpp -o mainc -std=c++14 -O2 && echo "finish" && ./mainc
*/