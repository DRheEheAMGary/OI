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
int n,k;
intl b[N];
int ml[N],mr[N];
bool check (intl ans) {
    int l=1,r=n;
    intl sum=0;
    for (;l<=n;l++) {
        sum+=b[l];
        if (sum>ans) break;
    }
    for (sum=0;r>=1;r--) {
        sum+=b[r];
        if (sum>ans) break;
    }
    if (l>r) return 1;
    for (int i=1;i<=n;i++) {
        if (b[i]>ans) return 0;
    }
    sum=0;
    for (int i=1,j=1;i<=n;i++) {
        sum+=b[i];
        while (sum>ans&&j<=i) sum-=b[j++];
        ml[i]=j;
    }
    sum=0;
    for (int i=n,j=n;i>=1;i--) {
        sum+=b[i];
        while (sum>ans&&j>=i) sum-=b[j--];
        mr[i]=j;
    }
    int cnt=0,cur=l,px=l,mxr=-1;
    while (cur<=r) {
        while (px<=r&&ml[px]<=cur) mxr=max(mxr,mr[px++]);
        if (mxr<cur) return 0;
        cnt++;
        if (cnt>k) return 0;
        cur=mxr+1;
    }
    return cnt<=k;
}
signed main() {
    Cios;
    freopen("thaw.in","r",stdin);
    freopen("thaw.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>b[i];
    intl l=0,r=2e14+10,res=-1;
    while (l<=r) {
        intl mid=(l+r)>>1;
        if (check(mid)) r=mid-1,res=mid;
        else l=mid+1;
    }
    cout<<res<<"\n";
    return 0;
}

/*
g++ -g thaw.cpp -o thaw.exe -std=c++14 -O2 -static; echo "finish"; .\thaw.exe; rm thaw.exe
cd $work/ZhengRui/Competition/noip20/12/thaw && g++ thaw.cpp -o thaw -std=c++14 -O2 && echo "finish" && ./thaw && rm thaw
*/