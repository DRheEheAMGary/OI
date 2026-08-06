/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
#include <ios>
using namespace std;
#define intc constexpr int
#define intl long long
#define double long double
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define szof sizeof
intc N=100;
double p[N],sump[N];
signed main() {
    Cios;
    int n,r;
    for (int __id=1;cin>>n>>r&&(n||r);__id++) {
        for (int i=0;i<n;i++) cin>>p[i];
        double totp=0;
        memset(sump,0,szof sump);
        for (int t=0;t<(1<<n);t++) {
            int cnt=__builtin_popcount(t);
            double cur=1;
            if (cnt==r) {
                for (int i=0;i<n;i++) {
                    if ((t>>i)&1) cur*=p[i];
                    else cur*=(1-p[i]);
                }
                totp+=cur;
                for (int i=0;i<n;i++) {
                    if ((t>>i)&1) sump[i]+=cur;
                }
            }
        }
        cout<<"Case "<<__id<<":"<<"\n";
        cout<<fixed<<setprecision(6);
        for (int i=0;i<n;i++) cout<<sump[i]/totp<<"\n";
    }
    return 0;
}