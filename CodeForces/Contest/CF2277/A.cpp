/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=200;
int a[N];
signed main() {
    Cios;
    int T;
    cin>>T;
    while (T--) {
        int n,k;
        cin>>n>>k;
        int minv=1<<30;
        for (int i=1;i<=n;i++) cin>>a[i],minv=min(minv,a[i]);
        sort(a+1,a+1+n);
        int lstmax=-1,nowmax=-1,nowl=0,res=-1;
        for (int i=1;i<=n;i++) {
            if (nowl==k&&n-i>=k) {
                if (~lstmax) {
                    if (nowmax-lstmax>1) {
                        res=lstmax+1;
                        break;
                    }
                }
                lstmax=nowmax;
                nowmax=-1;
                nowl=0;
            }
            nowmax=max(nowmax,a[i]);
            nowl++;
        }
        if (~res) cout<<res<<"\n";
        else cout<<lstmax+1<<"\n";
    }
    return 0;
}

/*
g++ -g A.cpp -o A.exe -std=c++14 -O2 -static; echo "finish"; .\A.exe
cd $work/CodeForces/Contest/CF2277 && g++  A.cpp -o A -std=c++14 -O2 && echo "finish" && ./A
*/