/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
char a[55][55];
signed main() {
    Cios;
    int h,w;
    cin>>h>>w;
    for (int i=1;i<=h;i++) {
        for (int j=1;j<=w;j++) cin>>a[i][j];
    }
    int up=1,dw=h,lf=1,rt=w;
    for (;up<=h;up++) {
        bool zero=0;
        for (int i=1;i<=w;i++) zero=zero||(a[up][i]!='.');
        if (zero) break;
    }
    for (;dw>=1;dw--) {
        bool zero=0;
        for (int i=1;i<=w;i++) zero=zero||(a[dw][i]!='.');
        if (zero) break;
    }
    for (;lf<=w;lf++) {
        bool zero=0;
        for (int i=1;i<=h;i++) zero=zero||(a[i][lf]!='.');
        if (zero) break;
    }
    for (;rt>=1;rt--) {
        bool zero=0;
        for (int i=1;i<=h;i++) zero=zero||(a[i][rt]!='.');
        if (zero) break;
    }
    for (int i=up;i<=dw;i++) {
        for (int j=lf;j<=rt;j++) cout<<a[i][j];
        cout<<"\n";
    }
    return 0;
}