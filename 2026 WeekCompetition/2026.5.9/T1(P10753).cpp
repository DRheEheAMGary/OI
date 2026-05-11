/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1e6+10;
int n,q,dis[N];
string s1,s2;
int dist (char a,char b) {
    return (a-b+26)%26;
}
signed main() {
    Cios;
    cin>>n>>q;
    cin>>s1;
    cin>>s2;
    int sum=0;
    for (int i=0;i<n;i++) {
        dis[i]=dist(s1[i],s2[i]);
        sum+=(i%2==0?(1):(-1))*dis[i];
    }
    if (sum%26==0) cout<<"da\n";
    else cout<<"ne\n";
    while (q--) {
        int p;
        char c;
        cin>>p>>c;
        p--;
        int dta=s1[p]-c;
        s1[p]=c;
        if (p%2==1) sum+=dta;
        else sum-=dta;
        if (sum%26==0) cout<<"da\n";
        else cout<<"ne\n";
    }
    return 0;
}
