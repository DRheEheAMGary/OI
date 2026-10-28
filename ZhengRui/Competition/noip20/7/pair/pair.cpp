/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e6+10;
int n,k,a[N];
signed main() {
    freopen("pair.in","r",stdin);
    freopen("pair.out","w",stdout);
    // scanf("%d%d",&n,&k);
    // for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    Cios;
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    int half=n/2+n%2;
    int res=0;
    int l,r;
    for (l=half,r=n;l>=1&&r>half;r--,l--) {
        while (l>=1&&a[r]-a[l]<k) l--;
        if (l<1) break;
        res++;
    }
    cout<<res<<"\n";
    return 0;
}

/*
g++ -g pair.cpp -o pair.exe -std=c++14 -O2 -static; echo "finish"; .\pair.exe; rm pair.exe
cd $work/ZhengRui/Competition/noip20/7/pair && g++ pair.cpp -o pair -std=c++14 -O2 && echo "finish" && ./pair && rm pair
*/