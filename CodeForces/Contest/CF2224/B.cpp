/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e5+10;
int n,a[N];
map<int,int> bkt;
signed main() {
    Cios;
    int T;
    cin>>T;
    while (T--) {
        cin>>n;
        bkt.clear();
        int mxval=-1,rval=-1;
        for (int i=1;i<=n;i++) cin>>a[i],bkt[a[i]]++,mxval=max(mxval,a[i]);
        for (int i=0;i<=mxval;i++) {
            if (bkt[i]==0) break;
            rval=i;
        }
        int res=0;
        res=mxval*n;
        if (rval!=-1) {
            int endlen=0;
            if (mxval==rval) res-=rval,endlen=n-rval-1;
            else endlen=n-rval-2;
            res+=(rval+2)*(rval+1)/2;
            res+=endlen*(rval+1);
        }
        cout<<res<<"\n";
    }
    return 0;
}