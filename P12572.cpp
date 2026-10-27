/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
typedef long long intl;
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=105;
intl n,a[N];
vector <int> res;
void work (int i) {
    res.push_back(i);
    a[i]+=a[i+1];
}
void plusx (int i,intl x) {
    if (x<=2) {
        while (x--) work(i);
        return;
    }
    if (x%2==1) work(i),x--;
    plusx(i+1,x/2-1);
    work(i);
    work(i);
}
signed main() {
    Cios;
    int T,G;
    cin>>T>>G;
    while (T--) {
        cin>>n;
        for (int i=1;i<=99;i++) a[i]=0;
        a[100]=1;
        for (int i=99;i>=1;i--) work(i);
        plusx(1,n-1);
        cout<<res.size()<<"\n";
        for (int v:res) cout<<v<<" ";
        cout<<"\n";
        res.clear();
    }
    return 0;
}

/*
g++ -g mainc.cpp -o mainc.exe -std=c++14 -O2 -static; echo "finish"; .\mainc.exe
g++  mainc.cpp -o mainc -std=c++14 -O2 && echo "finish" && ./mainc
*/