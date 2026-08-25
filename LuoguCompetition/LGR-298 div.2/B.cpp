/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e6+10;
vector <int> ptv;
int n,a[N];
int gcd (int a,int b) {return b?gcd(b,a%b):a;}
signed main() {
    Cios;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        if (a[i]!=0) ptv.push_back(i);
    }
    int resx=-1,resy=-1;
    if (ptv.size()==1) {
        resx=a[ptv[0]],resy=n;
        int _g=gcd(resx,resy);
        resx/=_g;
        resy/=_g;
        cout<<resx<<" "<<resy<<"\n";
        return 0;
    }
    for (vector <int>::iterator it=ptv.begin();it!=ptv.end();it++) {
        if (it==ptv.begin()) {
            auto nxt=next(it);
            int len=*nxt-1;
            resx=a[*it];
            resy=len;
            int _g=gcd(resx,resy);
            resx/=_g;
            resy/=_g;
        }
        else if (it==prev(ptv.end())) {
            auto pre=prev(it);
            int len=n-*pre;
            int _x=a[*it],_y=len;
            int _g=gcd(_x,_y);
            _x/=_g;
            _y/=_g;
            if ((__int128)_x*resy<(__int128)_y*resx) resx=_x,resy=_y;
        }
        else {
            auto pre=prev(it),nxt=next(it);
            int len=*nxt-*pre-1;
            int _x=a[*it],_y=len;
            int _g=gcd(_x,_y);
            _x/=_g;
            _y/=_g;
            if ((__int128)_x*resy<(__int128)_y*resx) resx=_x,resy=_y;
        }
    }
    cout<<resx<<" "<<resy<<"\n";
    return 0;
}