/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=3e5+10;
int n;
struct node {
    int x,y;
}p[N];
int miny=N+1;
signed main() {
    Cios;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i].x>>p[i].y;
    sort (p+1,p+1+n,[&] (node a,node b) {return a.x<b.x;});
    int res=0;
    for (int i=1;i<=n;i++) {
        if (p[i].y<miny) {
            res++;
            miny=p[i].y;
        }
    }
    cout<<res;
    return 0;
}