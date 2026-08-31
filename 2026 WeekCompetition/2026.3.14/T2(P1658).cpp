/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e3+10;
int n,x,a[N];
signed main(){
    Cios;
    cin>>x>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    if (a[1]!=1) {
        cout<<"-1\n";
        return 0;
    }
    int res=0,now=0;
    while (now<x) {
        int i=0;
        while (i+1<=n&&a[i+1]<=now+1) i++;
        res++;
        now+=a[i];
    }
    cout<<res<<"\n";
    return 0;
}