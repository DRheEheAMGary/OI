/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e5+10;
int n,a[N];
bool vis[N];
bool check (int k) {
    int m=n-k;
    if (m<=0) return 1;
    int p1=n,p2=n,lim=n-k+1;
    for (int i=m;i>=1;i--) {
        int cap1=(p1>=lim)?(a[p1]-1):-1;
        int cap2=(p2>=lim)?(a[p2]>>1):-1;
        if (cap1>=cap2) {
            if (cap1<a[i]) return 0;
            p1--;
        }
        else {
            if (cap2<a[i]) return 0;
            p2--;
        }
    }
    return 1;
}
signed main() {
    Cios;
    // freopen("box.in","r",stdin);
    // freopen("box.out","w",stdout);
    int T;
    cin>>T;
    while (T--) {
        cin>>n;
        for (int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+1+n);
        int l=(n+2)/3,r=n,res=n;
        while (l<=r) {
            int mid=(l+r)>>1;
            if (check(mid)) res=mid,r=mid-1;
            else l=mid+1;
        }
        cout<<res<<"\n";
    }
    return 0;
}

/*
g++ -g box.cpp -o box.exe -std=c++14 -O2 -static; echo "finish"; .\box.exe; rm box.exe
cd $work/ZhengRui/Competition/noip20/13/box && g++ box.cpp -o box -std=c++14 -O2 && echo "finish" && ./box && rm box
*/